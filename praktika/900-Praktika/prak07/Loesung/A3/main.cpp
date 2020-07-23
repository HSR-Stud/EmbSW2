//#include <cstdio>
#include <stdint.h>

int main(void)
{
  volatile uint32_t r = 0;
  r = 15;
//  printf("r = %#x\n",r);
  r |= 3 << 4;
//  printf("r = %#x\n",r);
  r &= 6 << 4;
//  printf("r = %#x\n",r);
  
  return 0;
}

