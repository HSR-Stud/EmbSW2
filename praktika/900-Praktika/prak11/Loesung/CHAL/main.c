/*
 * main.c
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#include <bsl/include/led.h>
#include <bsl/include/switch.h>

int main(void)
{
  bsl_Led statusIndicator;
  bsl_ledInit(&statusIndicator, bsl_led1);

  bsl_Led errorIndicator;
  bsl_ledInit(&errorIndicator, bsl_led2);

  bsl_Switch statusSwitch;
  bsl_switchInit(&statusSwitch, bsl_switch1);

  bsl_Switch errorSwitch;
  bsl_switchInit(&errorSwitch, bsl_switch2);

  while(1)
  {
    if(bsl_switchPressed(&statusSwitch))
      bsl_ledOn(&statusIndicator);
    else
      bsl_ledOff(&statusIndicator);

    if(bsl_switchPressed(&errorSwitch))
      bsl_ledOn(&errorIndicator);
    else
      bsl_ledOff(&errorIndicator);
  }

  return 0;
}
