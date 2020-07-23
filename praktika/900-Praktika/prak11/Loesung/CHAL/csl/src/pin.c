/*
 * pin.c
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#include "../include/pin.h"

#include "./protHwRegAccess.h"

enum
{
  numPorts = 2, ///< number of C2000 ports
  numPinsPerPort = 32, ///< number of pins per C2000 port
  muxBitWidth = 2, ///< bit width per mux setting
  syncBitWidth = 2, ///< bit width per sync setting
  syncToSysClk = 0 ///< sync to system clock
};

static bool initDonePort[numPorts] = {};

void csl_pinInit(csl_Pin* pin, csl_PinId id, csl_PinMux mux)
{
  // The pin and bit number is the same for portA.
  // In case of portB, the pin number has to be adjusted
  // by the number of pins per port to get the bit number.
  if(id < numPinsPerPort)
  {
    // Ensures that port A is initialized only once.
    csl_portInit(&(pin->port), csl_portA, !initDonePort[0]);
    initDonePort[0] = true;
    pin->bit = ((uint32_t)1) << id;
  }
  else
  {
    // Ensures that port B is initialized only once.
    csl_portInit(&(pin->port), csl_portB, !initDonePort[1]);
    initDonePort[1] = true;
    pin->bit = ((uint32_t)1) << (id - numPinsPerPort);
  }

  protHwRegAccessAllow();

  unsigned int bitNr = (id < numPinsPerPort) ? id : (id - numPinsPerPort);

  // sync
  bool highReg = bitNr >= (numPinsPerPort/syncBitWidth);
  unsigned int shift = (highReg ? bitNr - (numPinsPerPort/syncBitWidth) : bitNr) * syncBitWidth;
  csl_hwReg32Set2BitSubValue(&(pin->port.ctrl->sel[highReg]), syncToSysClk, shift);

  // mux
  highReg = bitNr >= (numPinsPerPort/muxBitWidth);
  shift = (highReg ? bitNr - (numPinsPerPort/muxBitWidth) : bitNr) * muxBitWidth;
  csl_hwReg32Set2BitSubValue(&(pin->port.ctrl->mux[highReg]), mux, shift);

  // disable pull-up
  csl_hwReg32SetBits(&(pin->port.ctrl->pud), pin->bit);

  protHwRegAccessDisallow();

  // default set to in
  csl_pinSetDirection(pin, csl_pinIn);
}

void csl_pinSetDirection(csl_Pin* pin, csl_PinDirection dir)
{
  protHwRegAccessAllow();

  if(dir == csl_pinIn)
  {
    csl_hwReg32ClearBits(&(pin->port.ctrl->dir), pin->bit);
  }
  else
  {
    csl_hwReg32SetBits(&(pin->port.ctrl->dir), pin->bit);
  }

  protHwRegAccessDisallow();
}
