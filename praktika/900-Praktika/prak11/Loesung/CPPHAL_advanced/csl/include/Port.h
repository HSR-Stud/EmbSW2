/*
 * Port.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef CSL_PORT_H_
#define CSL_PORT_H_

extern "C"
{
#include <stdint.h> // C2000 does not define <cstdint>
}

namespace csl
{

namespace port
{

enum
{
  numPins = 32 ///< number of pins per C2000 port
};

/**
 * @brief The port ID.
 */
enum Id
{
  a,
  b
};

/**
 * @brief The port register addresses.
 *
 * @tparam id port ID
 */
template<Id id>
struct GetAddrReg
{
  static const uintptr_t ctrl;
  static const uintptr_t sel1;
  static const uintptr_t sel2;
  static const uintptr_t mux1;
  static const uintptr_t mux2;
  static const uintptr_t dir;
  static const uintptr_t pud;

  static const uintptr_t dat;
  static const uintptr_t set;
  static const uintptr_t clr;
  static const uintptr_t toggle;
};
template<>
struct GetAddrReg<a>
{
  static const uintptr_t ctrl   = 0x00006F80;
  static const uintptr_t sel1   = ctrl+2;
  static const uintptr_t sel2   = ctrl+4;
  static const uintptr_t mux1   = ctrl+6;
  static const uintptr_t mux2   = ctrl+8;
  static const uintptr_t dir    = ctrl+10;
  static const uintptr_t pud    = ctrl+12;

  static const uintptr_t dat    = 0x00006FC0;
  static const uintptr_t set    = dat+2;
  static const uintptr_t clr    = dat+4;
  static const uintptr_t toggle = dat+6;
};
template<>
struct GetAddrReg<b>
{
  static const uintptr_t ctrl   = 0x00006F90;
  static const uintptr_t sel1   = ctrl+2;
  static const uintptr_t sel2   = ctrl+4;
  static const uintptr_t mux1   = ctrl+6;
  static const uintptr_t mux2   = ctrl+8;
  static const uintptr_t dir    = ctrl+10;
  static const uintptr_t pud    = ctrl+12;

  static const uintptr_t dat    = 0x00006FC8;
  static const uintptr_t set    = dat+2;
  static const uintptr_t clr    = dat+4;
  static const uintptr_t toggle = dat+6;
};

/**
 * @brief Abstracts C2000 ports.
 * 
 * @tparam id port ID
 */
template<Id id>
class Port
{
  public:
    /**
     * @brief Initializes the port to the preset sample period.
     *
     * @param initSamplePeriod initializes the sample period if set
     */
    Port(bool initSamplePeriod = false);
};


//
// implementation
//

template<Id id>
Port<id>::Port(bool initSamplePeriod)
{
  if(initSamplePeriod)
  {
    ProtHwRegAccess::allow();

    // Sets the sample period for the entire port to 510 * T_sysclk.
    // This is done, because the sample period cannot be set for each GIO pin separately.
    // More information can be found in the user manual of the C2000 DSP.
    if(!reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<id>::ctrl)->areBitsSet(
        ~static_cast<uint32_t>(0)))
    {
      reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<id>::ctrl)->setValue(
          ~static_cast<uint32_t>(0)); // sample period = 510 * T_sysclk
    }

    ProtHwRegAccess::disallow();
  }
}

} // namespace port

} // namespace csl

#endif /* CSL_PORT_H_ */
