/*
 * Pin.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef CSL_PIN_H_
#define CSL_PIN_H_

extern "C"
{
#include <stdint.h> // C2000 does not define <cstdint>
}

#include "./bits.h"
#include "./HwReg.h"
#include "./Port.h"

namespace csl
{

/**
 * @brief Abstracts C2000 pins.
 */
class Pin
{

  public:
    /**
     * @brief The pin ID.
     */
    enum Id
    {
      pin0 = 0, // must be 0
      pin1,
      pin2,
      pin3,
      pin4,
      pin5,
      pin6,
      pin7,
      pin8,
      pin9,
      pin10,
      pin11,
      pin12,
      pin13,
      pin14,
      pin15,
      pin16,
      pin17,
      pin18,
      pin19,
      pin20,
      pin21,
      pin22,
      pin23,
      pin24,
      pin25,
      pin26,
      pin27,
      pin28,
      pin29,
      pin30,
      pin31,
      pin32,
      pin33,
      pin34,
      pin35,
      pin36,
      pin37,
      pin38,
      pin39,
      pin40,
      pin41,
      pin42,
      pin43,
      pin44,
      pin45,
      pin46,
      pin47,
      pin48,
      pin49,
      pin50,
      pin51,
      pin52,
      pin53,
      pin54,
      pin55,
      pin56,
      pin57,
      pin58,
      pin59,
      pin60,
      pin61,
      pin62,
      pin63
    };

    /**
     * The pin direction.
     */
    enum Direction
    {
      in,
      out
    };

    /**
     * @brief The pin mux.
     */
    enum Mux
    {
      fun1 = 0, ///< GIO
      fun2 = bit0,
      fun3 = bit1,
      fun4 = bit1|bit0
    };

    /**
     * @brief Initializes the pin to the default configuration.
     *
     * @param id pin ID
     * @param dir pin direction
     * @param mux pin mux
     */
    Pin(Id id, Direction dir = in, Mux mux = fun1);

    /**
     * @brief Sets the direction of the pin.
     *
     * @param dir pin direction
     */
    void setDirection(Direction dir);

    /**
     * @brief Sets the pin.
     */
    void set()
    {
      HwReg<uint32_t>::setBits(port.dataRegs().set, bit);
    }

    /**
     * @brief Clears the pin.
     */
    void clear()
    {
      HwReg<uint32_t>::setBits(port.dataRegs().clear, bit);
    }

    /**
     * @brief Toggles the pin.
     */
    void toggle()
    {
      HwReg<uint32_t>::setBits(port.dataRegs().toggle, bit);
    }

    /**
     * @brief Returns the state of the pin.
     *
     * @return pin state
     */
    bool get() const
    {
      return HwReg<uint32_t>::areBitsSet(port.dataRegs().dat, bit);
    }

  private:
    enum
    {
      numPorts = 2, ///< number of C2000 ports
      numPinsPerPort = 32, ///< number of pins per C2000 port
      muxBitWidth = 2, ///< bit width per mux setting
      syncBitWidth = 2, ///< bit width per sync setting
      syncToSysClk = 0 ///< sync to system clock
    };

    static bool initDonePort[numPorts]; ///< port initialized flags

    Port port; ///< port
    const uint32_t bit; ///< bit number to access the control and data registers of the used port
};

} // namespace csl

#endif /* CSL_PIN_H_ */
