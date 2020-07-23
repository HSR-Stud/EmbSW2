/*
 * main.c
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#include <stdint.h>


#define  EALLOW __asm(" EALLOW")
#define  EDIS   __asm(" EDIS")


// portA
#define GP_A_CTRL (*((volatile uint32_t *)((uint32_t)0x00006F80)))
#define GP_A_SEL1 (*((volatile uint32_t *)((uint32_t)0x00006F82)))
#define GP_A_SEL2 (*((volatile uint32_t *)((uint32_t)0x00006F84)))
#define GP_A_MUX1 (*((volatile uint32_t *)((uint32_t)0x00006F86)))
#define GP_A_MUX2 (*((volatile uint32_t *)((uint32_t)0x00006F88)))
#define GP_A_DIR  (*((volatile uint32_t *)((uint16_t)0x00006F8A)))
#define GP_A_PUD  (*((volatile uint32_t *)((uint32_t)0x00006F8C)))

#define GP_A_DATA (*((volatile uint32_t *)((uint32_t)0x00006FC0)))
#define GP_A_SET  (*((volatile uint32_t *)((uint32_t)0x00006FC2)))
#define GP_A_CLR  (*((volatile uint32_t *)((uint32_t)0x00006FC4)))
#define GP_A_TOG  (*((volatile uint32_t *)((uint32_t)0x00006FC6)))


// bit manipulation
#define SET_BIT(reg, bit) ((reg) |=  (((uint32_t)1u) << ((uint32_t)(bit))))
#define CLR_BIT(reg, bit) ((reg) &= ~(((uint32_t)1u) << ((uint32_t)(bit))))
#define GET_BIT(reg, bit) (((reg) & (((uint32_t)1u) << ((uint32_t)(bit)))) >> ((uint32_t)(bit)))

#define SET_BITS(reg, bits)     ((reg) |=  (bits))
#define CLR_BITS(reg, bits)     ((reg) &= ~(bits))
#define ARE_BITS_SET(reg, bits) (((reg) & (bits)) == (bits))


// pin configuration
#define LED1_PIN     6u
#define LED2_PIN     2u
#define SWITCH1_PIN  26u
#define SWITCH2_PIN  30u

int main(void)
{
  EALLOW; // allow register changes

  // init GIOs
  GP_A_CTRL = (uint32_t)0xFFFFFFFF; // control register
  GP_A_SEL1 = (uint32_t)0; // Sync for Pin 0 - Pin 15
  GP_A_SEL2 = (uint32_t)0; // Sync for Pin 16 - Pin 31
  GP_A_MUX1 = (uint32_t)0; // GIO for Pin 0 - Pin 15
  GP_A_MUX2 = (uint32_t)0; // GIO for Pin 16 - Pin 31
  GP_A_DIR =  (uint32_t)0; // all GIO's as input
  GP_A_PUD =  (uint32_t)0xFFFFFFFF; // disable GIO pullup for all GIOs

  // LED 1 - statusIndicator
  SET_BIT(GP_A_DIR, LED1_PIN); // configure direction output

  // LED 2 - errorIndicator
  SET_BIT(GP_A_DIR, LED2_PIN); // configure direction output

  // SWITCH 1 - statusSwitch
  CLR_BIT(GP_A_DIR, SWITCH1_PIN); // configure direction input

  // SWITCH 2 - errorSwitch
  CLR_BIT(GP_A_DIR, SWITCH2_PIN); // configure direction input

  EDIS; // disallow register changes

  while(1)
  {
    if(!ARE_BITS_SET(GP_A_DATA, 1ul << SWITCH1_PIN))
      SET_BITS(GP_A_SET,  1ul << LED1_PIN);
    else
      SET_BITS(GP_A_CLR,  1ul << LED1_PIN);

    if(!ARE_BITS_SET(GP_A_DATA,  1ul << SWITCH2_PIN))
      SET_BITS(GP_A_SET,  1ul << LED2_PIN);
    else
      SET_BITS(GP_A_CLR,  1ul << LED2_PIN);
  }

  return 0;
}
