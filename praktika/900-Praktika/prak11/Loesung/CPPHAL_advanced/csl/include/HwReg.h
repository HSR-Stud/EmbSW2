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
     * @param bits bits to set
     */
    void setBits(const RegType& bits)
    {
      reg |= bits;
    }

    /**
     * @brief Clears the specified bits in the register.
     *
     * @param bits bits to clear
     */
    void clearBits(const RegType& bits)
    {
      reg &= ~bits;
    }

    /**
     * @brief Returns if the bits are set in the register.
     *
     * @param bits bits to check
     *
     * @return true if the bits are set and false otherwise
     */
    bool areBitsSet(const RegType& bits) const
    {
      return (reg & bits) == bits;
    }

    /**
     * @brief Sets the value in the register.
     *
     * @param value value to set
     */
    void setValue(const RegType& value)
    {
      reg = value;
    }

    /**
     * @brief Sets the sub-value in the register.
     *
     * @tparam bitWidth bit width of the sub-value
     * @tparam shift shift for the sub-value
     *
     * @param value sub-value to set
     */
    template<unsigned int bitWidth, unsigned int shift>
    void setSubValue(RegType value) // const RegType& results in an linking error
    {
      clearBits(((static_cast<RegType>(1) << bitWidth) - static_cast<RegType>(1)) << shift);
      setBits(value << shift);
    }

    /**
     * @brief Sets the sub-value in the register.
     *
     * @tparam bitWidth bit width of the sub-value
     *
     * @param value sub-value to set
     * @param shift shift for the sub-value
     */
    template<unsigned int bitWidth>
    void setSubValue(const RegType& value, unsigned int shift)
    {
      clearBits(((static_cast<RegType>(1) << bitWidth) - static_cast<RegType>(1)) << shift);
      setBits(value << shift);
    }

  private:
    /**
     * @brief The destructor.
     */
    ~HwReg(); // prevent destructing of directly mapped register

    /**
     * @brief The copy-constructor.
     */
    HwReg(const HwReg&); // prevent copying of directly mapped register

    /**
     * @brief The assignment operator.
     */
    HwReg& operator=(const HwReg&); // prevent copying of directly mapped register

    volatile RegType reg; ///< register which is directly mapped to the register address
};

} // namespace csl

#endif /* CSL_HWREG_H_ */
