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
extern void codeInsertion();
extern void patchedCode();
}
#include <stdint.h>



void patchedCode(void)
{
	//Hier kann der zusätzlich Code geschrieben werden
	LED_Clear(0);
}


int main()
{
	LED_Configure(0);
	LED_Set(0);

	codeInsertion();

	//SOLUTION_BEGIN
	asm("LDR PC, =0x201000a0"); //Starte BlinkLED0
	//SOLUTION_END

	while(1)
	{

	}
}
