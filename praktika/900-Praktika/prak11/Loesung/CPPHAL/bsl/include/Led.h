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
 * @brief Abstracts EswRobot LEDs.
 */
class Led
{
  public:
    /**
     * @brief The LED ID.
     */
    enum Id
    {
      led1,
      led2
    };

    /**
     * @brief Initializes the LED.
     *
     * @param id LED ID
     */
    Led(Id id) :
      pin(led1 == id ? csl::Pin::pin6 : csl::Pin::pin2,
          csl::Pin::out)
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
    csl::Pin pin; ///< GIO pin

};

} // namespace bsl

#endif /* BSL_LED_H_ */
