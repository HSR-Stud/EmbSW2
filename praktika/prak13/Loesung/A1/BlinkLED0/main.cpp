/*
 * main.cpp
 *
 *  Created on: 03.04.2012
 *      Author: mtrummer
 */
extern "C"{
#include "./Library/boards/at91sam9261-ek/board.h"
#include "./Library/utility/led.h"
#include "./Library/peripherals/dbgu/dbgu.h"

}


#include <stdio.h>

int main(void)
{
	LED_Configure(1);

	LED_Set(1);

	while(1)
	{

	}
}
