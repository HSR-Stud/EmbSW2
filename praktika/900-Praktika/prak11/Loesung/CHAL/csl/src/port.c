/*
 * port.c
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#include "../include/port.h"

#include "../include/hwReg.h"
#include "./protHwRegAccess.h"

enum
{
  addrPortACtrlRegs = 0x00006F80, ///< base address of the control register of port A
  addrPortBCtrlRegs = 0x00006F90, ///< base address of the control register of port B

  addrPortADataRegs = 0x00006FC0, ///< base address of the data register of port A
  addrPortBDataRegs = 0x00006FC8  ///< base address of the data register of port B
};

void csl_portInit(csl_Port* port, csl_PortId id, bool initSamplePeriod)
{
  if(csl_portA == id)
  {
    port->ctrl = (csl_PortCtrlRegs*)addrPortACtrlRegs;
    port->data = (csl_PortDataRegs*)addrPortADataRegs;
  }
  else
  {
    port->ctrl = (csl_PortCtrlRegs*)addrPortBCtrlRegs;
    port->data = (csl_PortDataRegs*)addrPortBDataRegs;
  }

  if(initSamplePeriod)
  {
    protHwRegAccessAllow();

    // Sets the sample period for the entire port to 510 * T_sysclk.
    // This is done, because the sample period cannot be set for each GIO pin separately.
    // More information can be found in the user manual of the C2000 DSP.
    if(!csl_hwReg32AreBitsSet(&(port->ctrl->ctrl), ~((uint32_t)0)))
    {
      csl_hwReg32SetValue(&(port->ctrl->ctrl), ~((uint32_t)0)); // sample period = 510 * T_sysclk
    }

    protHwRegAccessDisallow();
  }
}
