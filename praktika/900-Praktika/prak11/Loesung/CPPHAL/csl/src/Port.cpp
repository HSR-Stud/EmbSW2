/*
 * Port.cpp
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#include "./ProtHwRegAccess.h"

#include "../include/Port.h"
#include "../include/HwReg.h"

namespace csl
{

Port::Port(Id id, bool initSamplePeriod) :
  cRegs(id == a ?
          *reinterpret_cast<CtrlRegs*>(addrPortACtrlRegs) :
          *reinterpret_cast<CtrlRegs*>(addrPortBCtrlRegs)),
  dRegs(id == a ?
          *reinterpret_cast<DataRegs*>(addrPortADataRegs) :
          *reinterpret_cast<DataRegs*>(addrPortBDataRegs))
{
  if(initSamplePeriod)
  {
    ProtHwRegAccess::allow();

    // Sets the sample period for the entire port to 510 * T_sysclk.
    // This is done, because the sample period cannot be set for each GIO pin separately.
    // More information can be found in the user manual of the C2000 DSP.
    if(!HwReg<uint32_t>::areBitsSet(cRegs.ctrl, ~static_cast<uint32_t>(0)))
    {
      HwReg<uint32_t>::setValue(cRegs.ctrl, ~static_cast<uint32_t>(0)); // sample period = 510 * T_sysclk
    }

    ProtHwRegAccess::disallow();
  }
}

} // namespace csl
