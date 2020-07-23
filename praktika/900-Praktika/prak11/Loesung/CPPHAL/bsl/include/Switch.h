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
 * @brief Abstracts EswRobot switches.
 */
class Switch
{
  public:
    /**
     * @brief The switch ID.
     */
    enum Id
    {
      switch1,
      switch2
    };

    /**
     * @brief Initializes the switch.
     *
     * @param id switch ID
     */
    Switch(Id id) :
      pin(switch1 == id ? csl::Pin::pin26 : csl::Pin::pin30,
          csl::Pin::in)
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
    csl::Pin pin; ///< GIO pin
};

} // namespace bsl

#endif /* BSL_SWITCH_H_ */
