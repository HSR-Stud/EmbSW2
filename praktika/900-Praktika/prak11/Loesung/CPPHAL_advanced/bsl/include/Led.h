/*
 * Led.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef BSL_LED_H_
#define BSL_LED_H_

#include <csl/include/Pin.h>

namespace bsl
{

/**
 * @brief The LED ID.
 */
enum LedId
{
  led1,
  led2
};

/**
 * @brief Abstracts EswRobot LEDs.
 */
template<LedId id>
class Led
{
  public:
    /**
     * @brief Initializes the LED.
     */
    Led() :
      pin(csl::pin::out)
    {

    }

    /**
     * @brief Turns off the LED.
     */
    void off()
    {
      pin.clear();
    }

    /**
     * @brief Turns on the LED.
     */
    void on()
    {
      pin.set();
    }

  private:
    csl::pin::Pin<id == led1 ?
        csl::pin::pin6 :
        csl::pin::pin2> pin; ///< GIO pin

};

} // namespace bsl

#endif /* BSL_LED_H_ */
