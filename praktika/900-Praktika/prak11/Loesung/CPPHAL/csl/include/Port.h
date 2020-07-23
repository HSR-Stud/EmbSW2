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
#include <stdint.h> // C2000 compiler does not define <cstdint>
}

namespace csl
{

/**
 * @brief Abstracts C2000 ports.
 */
class Port
{
  public:
    /**
     * @brief The port ID.
     */
    enum Id
    {
      a,
      b
    };

    /**
     * @brief The control registers.
     */
    struct CtrlRegs
    {
      volatile uint32_t ctrl;
      volatile uint32_t sel[2];
      volatile uint32_t mux[2];
      volatile uint32_t dir;
      volatile uint32_t pud;
    };

    /**
     * @brief The data registers.
     */
    struct DataRegs
    {
      volatile const uint32_t dat;
      volatile uint32_t set;
      volatile uint32_t clear;
      volatile uint32_t toggle;
    };

    /**
     * @brief Initializes the port to the preset sample period.
     *
     * @param id port ID
     * @param initSamplePeriod initializes the sample period if set
     */
    Port(Id id, bool initSamplePeriod = false);

    /**
     * @brief Returns the port control registers.
     *
     * @return port control registers
     */
    CtrlRegs& ctrlRegs()
    {
      return cRegs;
    }

    /**
     * @brief Returns the port control registers.
     *
     * @return port control registers
     */
    const CtrlRegs& ctrlRegs() const // method for read only access used by const objects and/or methods
    {
      return cRegs;
    }

    /**
     * @brief Returns the port data registers.
     *
     * @return port data registers
     */
    DataRegs& dataRegs()
    {
      return dRegs;
    }

    /**
     * @brief Returns the port data registers.
     *
     * @return port data registers
     */
    const DataRegs& dataRegs() const // method for read only access used by const objects and/or methods
    {
      return dRegs;
    }

  private:
    enum
    {
      addrPortACtrlRegs = 0x00006F80, ///< base address of the control register of port A
      addrPortBCtrlRegs = 0x00006F90, ///< base address of the control register of port B

      addrPortADataRegs = 0x00006FC0, ///< base address of the data register of port A
      addrPortBDataRegs = 0x00006FC8  ///< base address of the data register of port B
    };

    CtrlRegs& cRegs; ///< control registers
    DataRegs& dRegs; ///< data registers
};

} // namespace csl

#endif /* CSL_PORT_H_ */
