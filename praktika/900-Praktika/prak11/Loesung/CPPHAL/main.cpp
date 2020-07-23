/*
 * main.cpp
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#include <bsl/include/Led.h>
#include <bsl/include/Switch.h>

using bsl::Led;
using bsl::Switch;

int main(void)
{
  Led statusIndicator(Led::led1);
  Led errorIndicator(Led::led2);
  Switch statusSwitch(Switch::switch1);
  Switch errorSwitch(Switch::switch2);

  while(1)
  {
    if(statusSwitch.pressed())
      statusIndicator.on();
    else
      statusIndicator.off();

    if(errorSwitch.pressed())
      errorIndicator.on();
    else
      errorIndicator.off();
  }

  return 0;
}
