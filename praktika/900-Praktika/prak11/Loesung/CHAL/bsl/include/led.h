/*
 * led.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef BSL_LED_H_
#define BSL_LED_H_

#include <csl/include/pin.h>

/**
 * @brief The EswRobot LED ID.
 */
typedef enum
{
  bsl_led1,
  bsl_led2
} bsl_LedId;

/**
 * @brief The EswRobot LED data.
 */
typedef struct
{
  csl_Pin pin; ///< GIO pin
} bsl_Led;

/**
 * @brief Initializes the EswRobot LED.
 *
 * @param led LED data
 * @param id LED ID
 *
 * @pre @p led pointer must be valid, validity is not checked!
 */
static inline void bsl_ledInit(bsl_Led* led, bsl_LedId id)
{
  csl_pinInit(&(led->pin), (bsl_led1 == id) ? csl_pin6 : csl_pin2, csl_pinFun1);
  csl_pinSetDirection(&(led->pin), csl_pinOut);
}

/**
 * @brief Turns off the EswRobot LED.
 *
 * @param led LED data
 *
 * @pre @p led pointer must be valid, validity is not checked!
 */
static inline void bsl_ledOff(bsl_Led* led)
{
  csl_pinClear(&(led->pin));
}

/**
 * @brief Turns on the EswRobot LED.
 *
 * @param led LED data
 *
 * @pre @p led pointer must be valid, validity is not checked!
 */
static inline void bsl_ledOn(bsl_Led* led)
{
  csl_pinSet(&(led->pin));
}

#endif /* BSL_LED_H_ */
