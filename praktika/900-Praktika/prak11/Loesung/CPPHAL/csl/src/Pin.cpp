/*
 * Pin.cpp
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#include "./ProtHwRegAccess.h"

#include "../include/Pin.h"

namespace csl
{

bool Pin::initDonePort[numPorts] = {};

Pin::Pin(Id id, Direction dir, Mux mux) :
    port((id < numPinsPerPort) ? Port::a : Port::b,
         !initDonePort[id < numPinsPerPort]),
    // The pin and bit number is the same for portA.
    // In case of portB, the pin number has to be adjusted
    // by the number of pins per port to get the bit number.
    // note: cast to uint32_t is necessary, because 1 converts to a 16 bit int
    bit((id < numPinsPerPort) ?
        static_cast<uint32_t>(1) << id :
        static_cast<uint32_t>(1) << (id-numPinsPerPort))
{
  // Ensures that each port is initialized only once.
  initDonePort[id < numPinsPerPort] = true;

  ProtHwRegAccess::allow();

  const unsigned int bitNr = (id < numPinsPerPort) ? id : (id-numPinsPerPort);

  // sync
  bool highReg = bitNr >= (numPinsPerPort/syncBitWidth);
  unsigned int shift = (highReg ? bitNr - (numPinsPerPort/syncBitWidth) : bitNr) * syncBitWidth;
  HwReg<uint32_t>::setSubValue<syncBitWidth>(port.ctrlRegs().sel[highReg], syncToSysClk, shift);

  // mux
  highReg = bitNr >= (numPinsPerPort/muxBitWidth);
  shift = (highReg ? bitNr - (numPinsPerPort/muxBitWidth) : bitNr) * muxBitWidth;
  HwReg<uint32_t>::setSubValue<muxBitWidth>(port.ctrlRegs().mux[highReg], mux, shift);

  // disable pull-up
  HwReg<uint32_t>::setBits(port.ctrlRegs().pud, bit);

  ProtHwRegAccess::disallow();

  setDirection(dir);
}

void Pin::setDirection(Direction dir)
{
  ProtHwRegAccess::allow();

  if(dir == in)
    HwReg<uint32_t>::HwReg::clearBits(port.ctrlRegs().dir, bit);
  else
    HwReg<uint32_t>::HwReg::setBits(port.ctrlRegs().dir, bit);

  ProtHwRegAccess::disallow();
}

} // namespace csl
