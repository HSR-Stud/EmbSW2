/*
 * switch.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef BSL_SWITCH_H_
#define BSL_SWITCH_H_

#include <csl/include/pin.h>

/**
 * @brief The EswRobot switch ID.
 */
typedef enum
{
  bsl_switch1,
  bsl_switch2
} bsl_SwitchId;

/**
 * @brief The EswRobot switch data.
 */
typedef struct
{
  csl_Pin pin;
} bsl_Switch;

/**
 * @brief Initializes the EswRobot switch.
 *
 * @param sw switch data
 * @param id switch ID
 *
 * @pre @p sw pointer must be valid, validity is not checked!
 */
static inline void bsl_switchInit(bsl_Switch* sw, bsl_SwitchId id)
{
  csl_pinInit(&(sw->pin), (bsl_switch1 == id) ? csl_pin26 : csl_pin30, csl_pinFun1);
  csl_pinSetDirection(&(sw->pin), csl_pinIn);
}

/**
 * @brief Returns if the EswRobot switch is pressed.
 *
 * @param sw switch data
 *
 * @pre @p sw pointer must be valid, validity is not checked!
 */
static inline bool bsl_switchPressed(const bsl_Switch* sw)
{
  return !csl_pinGet(&(sw->pin));
}

#endif /* BSL_SWITCH_H_ */
