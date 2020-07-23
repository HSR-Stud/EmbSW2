/*
 * main.cpp
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#include <bsl/include/Led.h>
#include <bsl/include/Switch.h>

using namespace bsl;

int main(void)
{
  Led<led1> statusIndicator;
  Led<led2> errorIndicator;
  Switch<switch1> statusSwitch;
  Switch<switch2> errorSwitch;

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
