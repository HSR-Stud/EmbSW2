/*
 * hwReg.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef CSL_HWREG_H_
#define CSL_HWREG_H_

#include <stdint.h>
#include <stdbool.h>

#include "./bits.h"

/**
 * @brief Sets the specified bits in the 32 bit register.
 *
 * @param reg register
 * @param bits bits to set
 *
 * @pre @p reg pointer must be valid, validity is not checked!
 */
static inline void csl_hwReg32SetBits(volatile uint32_t* reg, uint32_t bits)
{
  *reg |= bits;
}

/**
 * @brief Clears the specified bits in the 32 bit register.
 *
 * @param reg register
 * @param bits bits to clear
 *
 * @pre @p reg pointer must be valid, validity is not checked!
 */
static inline void csl_hwReg32ClearBits(volatile uint32_t* reg, uint32_t bits)
{
  *reg &= ~bits;
}

/**
 * @brief Returns if the bits are set in the 32 bit register.
 *
 * @param reg register
 * @param bits bits to check
 * @return true if the bits are set and false otherwise
 *
 * @pre @p reg pointer must be valid, validity is not checked!
 */
static inline bool csl_hwReg32AreBitsSet(const volatile uint32_t* reg, uint32_t bits)
{
  return (*reg & bits) == bits;
}

/**
 * @brief Sets the value in the 32 bit register.
 *
 * @param reg register
 * @param value value to set
 *
 * @pre @p reg pointer must be valid, validity is not checked!
 */
static inline void csl_hwReg32SetValue(volatile uint32_t* reg, uint32_t value)
{
  *reg = value;
}

/**
 * @brief Sets the 2 bit sub-value in the 32 bit register.
 *
 * @param reg register
 * @param value sub-value to set
 * @param shift shift for the sub-value
 *
 * @pre @p reg pointer must be valid, validity is not checked!
 */
static inline void csl_hwReg32Set2BitSubValue(volatile uint32_t* reg, uint32_t value, unsigned int shift)
{
  csl_hwReg32ClearBits(reg, (uint32_t)((1 << 2) - 1) << shift);
  csl_hwReg32SetBits(reg, value << shift);
}

/**
 * @brief Sets the specified bits in the 16 bit register.
 *
 * @param reg register
 * @param bits bits to set
 *
 * @pre @p reg pointer must be valid, validity is not checked!
 */
static inline void csl_hwReg16SetBits(volatile uint16_t* reg, uint16_t bits)
{
  *reg |= bits;
}

/**
 * @brief Clears the specified bits in the 16 bit register.
 *
 * @param reg register
 * @param bits bits to clear
 *
 * @pre @p reg pointer must be valid, validity is not checked!
 */
static inline void csl_hwReg16ClearBits(volatile uint16_t* reg, uint16_t bits)
{
  *reg &= ~bits;
}

/**
 * @brief Returns if the bits are set in the 16 bit register.
 *
 * @param reg register
 * @param bits bits to check
 * @return true if the bits are set and false otherwise
 *
 * @pre @p reg pointer must be valid, validity is not checked!
 */
static inline bool csl_hwReg16AreBitsSet(const volatile uint16_t* reg, uint16_t bits)
{
  return (*reg & bits) == bits;
}

/**
 * @brief Sets the value in the 16 bit register.
 *
 * @param reg register
 * @param value value to set
 *
 * @pre @p reg pointer must be valid, validity is not checked!
 */
static inline void csl_hwReg16SetValue(volatile uint16_t* reg, uint16_t value)
{
  *reg = value;
}

/**
 * @brief Sets the 2 bit sub-value in the 16 bit register.
 *
 * @param reg register
 * @param value sub-value to set
 * @param shift shift for the sub-value
 *
 * @pre @p reg pointer must be valid, validity is not checked!
 */
static inline void csl_hwReg16Set2BitSubValue(volatile uint16_t* reg, uint16_t value, unsigned int shift)
{
  csl_hwReg16ClearBits(reg, (uint16_t)((1 << 2) - 1) << shift);
  csl_hwReg16SetBits(reg, value << shift);
}

#endif /* CSL_HWREG_H_ */
