/*
 * pin.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef CSL_PIN_H_
#define CSL_PIN_H_

#include "./bits.h"
#include "./hwReg.h"
#include "./port.h"

/**
 * @brief The C2000 pin ID.
 */
typedef enum
{
  csl_pin0 = 0, // must be 0
  csl_pin1,
  csl_pin2,
  csl_pin3,
  csl_pin4,
  csl_pin5,
  csl_pin6,
  csl_pin7,
  csl_pin8,
  csl_pin9,
  csl_pin10,
  csl_pin11,
  csl_pin12,
  csl_pin13,
  csl_pin14,
  csl_pin15,
  csl_pin16,
  csl_pin17,
  csl_pin18,
  csl_pin19,
  csl_pin20,
  csl_pin21,
  csl_pin22,
  csl_pin23,
  csl_pin24,
  csl_pin25,
  csl_pin26,
  csl_pin27,
  csl_pin28,
  csl_pin29,
  csl_pin30,
  csl_pin31,
  csl_pin32,
  csl_pin33,
  csl_pin34,
  csl_pin35,
  csl_pin36,
  csl_pin37,
  csl_pin38,
  csl_pin39,
  csl_pin40,
  csl_pin41,
  csl_pin42,
  csl_pin43,
  csl_pin44,
  csl_pin45,
  csl_pin46,
  csl_pin47,
  csl_pin48,
  csl_pin49,
  csl_pin50,
  csl_pin51,
  csl_pin52,
  csl_pin53,
  csl_pin54,
  csl_pin55,
  csl_pin56,
  csl_pin57,
  csl_pin58,
  csl_pin59,
  csl_pin60,
  csl_pin61,
  csl_pin62,
  csl_pin63
} csl_PinId;

/**
 * @brief The pin data.
 */
typedef struct
{
  csl_Port port;
  uint32_t bit;
} csl_Pin;

/**
 * @brief The pin direction.
 */
typedef enum
{
  csl_pinIn,
  csl_pinOut
} csl_PinDirection;

/**
 * @brief The pin mux.
 */
typedef enum
{
  csl_pinFun1 = 0, ///< GIO
  csl_pinFun2 = csl_bit0,
  csl_pinFun3 = csl_bit1,
  csl_pinFun4 = csl_bit1 | csl_bit0
} csl_PinMux;

/**
 * @brief Initializes the C2000 pin to the default configuration.
 *
 * @param pin pin data
 * @param id pin ID
 * @param mux pin mux
 *
 * @pre @p pin pointer must be valid, validity is not checked!
 */
void csl_pinInit(csl_Pin* pin, csl_PinId id, csl_PinMux mux);

/**
 * @brief Sets the direction of the C2000 pin.
 *
 * @param pin pin data
 * @param dir direction
 *
 * @pre @p pin pointer must be valid, validity is not checked!
 */
void csl_pinSetDirection(csl_Pin* pin, csl_PinDirection dir);

/**
 * @brief Sets the the C2000 pin.
 *
 * @param pin pin data
 *
 * @pre @p pin pointer must be valid, validity is not checked!
 */
static inline void csl_pinSet(csl_Pin* pin)
{
  csl_hwReg32SetBits(&(pin->port.data->set), pin->bit);
}

/**
 * @brief Clears the C2000 pin.

 * @param pin pin data
 *
 * @pre @p pin pointer must be valid, validity is not checked!
 */
static inline void csl_pinClear(csl_Pin* pin)
{
  csl_hwReg32SetBits(&(pin->port.data->clear), pin->bit);
}

/**
 * @brief Toggles the C2000 pin.

 * @param pin pin data
 *
 * @pre @p pin pointer must be valid, validity is not checked!
 */
static inline void csl_pinToggle(csl_Pin* pin)
{
  csl_hwReg32SetBits(&(pin->port.data->toggle), pin->bit);
}

/**
 * @brief Returns the state of the C2000 pin.
 *
 * @param pin pin data
 * @return pin state
 *
 * @pre @p pin pointer must be valid, validity is not checked!
 */
static inline bool csl_pinGet(const csl_Pin* pin)
{
  return csl_hwReg32AreBitsSet(&(pin->port.data->dat), pin->bit);
}

#endif /* CSL_PIN_H_ */
