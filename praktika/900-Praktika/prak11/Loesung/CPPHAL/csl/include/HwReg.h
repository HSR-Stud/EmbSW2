/*
 * HwReg.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef CSL_HWREG_H_
#define CSL_HWREG_H_

extern "C"
{
#include <stdint.h> // C2000 does not define <cstdint>
}

#include "./bits.h"

namespace csl
{

/**
 * @brief Abstracts C2000 hardware registers.
 *
 * @tparam RegType register unsigned int type must match the integer width of the
 * used architecture
 */
template<typename RegType>
class HwReg
{
  public:
    /**
     * @brief Sets the specified bits in the register.
     *
     * @param reg register
     * @param bits bits to set
     */
    static void setBits(volatile RegType& reg, const RegType& bits)
    {
      reg |= bits;
    }

    /**
     * @brief Clears the specified bits in the register.
     *
     * @param reg register
     * @param bits bits to clear
     */
    static void clearBits(volatile RegType& reg, const RegType& bits)
    {
      reg &= ~bits;
    }

    /**
     * @brief Returns if the bits are set in the register.
     *
     * @param reg register
     * @param bits bits to check
     *
     * @return true if the bits are set and false otherwise
     */
    static bool areBitsSet(const volatile RegType& reg, const RegType& bits)
    {
      return (reg & bits) == bits;
    }

    /**
     * @brief Sets the value in the register.
     *
     * @param reg register
     * @param value value to set
     */
    static void setValue(volatile RegType& reg, const RegType& value)
    {
      reg = value;
    }

    /**
     * @brief Sets the sub-value in the register.
     *
     * @tparam bitWidth bit width of the sub-value
     *
     * @param reg register
     * @param value sub-value to set
     * @param shift shift for the sub-value
     */
    template<unsigned int bitWidth>
    static void setSubValue(volatile RegType& reg, const RegType& value, unsigned int shift)
    {
      clearBits(reg, (static_cast<RegType>(1) << bitWidth - static_cast<RegType>(1)) << shift);
      setBits(reg, value << shift);
    }
};

} // namespace csl

#endif /* CSL_HWREG_H_ */
