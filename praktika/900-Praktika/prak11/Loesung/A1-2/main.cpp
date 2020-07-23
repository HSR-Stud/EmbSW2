#include <cstdio>
#include "ints.h"

const int const1 = 64;
const int const2 = 128;
const int const3 = 256;

int main(void)
{
  int tmp1;
  int tmp2 = 20;
  tmp1 = MAKRO_DEF1;
  tmp2 = tmp2 + MAKRO_DEF1;
  printf("Mit Makros: tmp1 = %d, tmp2 = %d\n", tmp1, tmp2);

  tmp2 = 20;
  tmp1 = en1;
  tmp2 = tmp2 + en1;
  printf("Mit Enums: tmp1 = %d, tmp2 = %d\n", tmp1, tmp2);

  tmp2 = 20;
  tmp1 = const3;
  tmp2 = tmp2 + const3;
  printf("Mit Const: tmp1 = %d, tmp2 = %d\n", tmp1, tmp2);

  tmp2 = foo(tmp1);
  printf("Unterprogramm: tmp1 = %d, tmp2 = %d\n", tmp1, tmp2);
  
  return 0;
}

