/*
 * Switch.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef BSL_SWITCH_H_
#define BSL_SWITCH_H_

#include <csl/include/Pin.h>

namespace bsl
{

/**
 * @brief The switch ID.
 */
enum SwitchId
{
  switch1,
  switch2
};

/**
 * @brief Abstracts EswRobot switches.
 */
template<SwitchId id>
class Switch
{
  public:
    /**
     * @brief Initializes the switch.
     */
    Switch() :
      pin(csl::pin::in)
    {

    }

    /**
     * @brief Returns if the switch is pressed.
     *
     * @return true if the switch is pressed and false otherwise
     */
    bool pressed() const
    {
      return !pin.get();
    }

  private:
    csl::pin::Pin<id == switch1 ?
        csl::pin::pin26 :
        csl::pin::pin30> pin; ///< GIO pin
};

} // namespace bsl

#endif /* BSL_SWITCH_H_ */
