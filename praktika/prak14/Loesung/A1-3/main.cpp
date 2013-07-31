#include <cstdio>
#include "floats.h"

const double const1 = 432.22128;
const double const2 = 23.55128;
const double const3 = 256.56;

int main(void)
{
  double tmp1;
  double tmp2 = 2.5;
  tmp1 = MAKRO_DEF1;
  tmp2 = tmp2 + MAKRO_DEF1;
  printf("Mit Makros: tmp1 = %f, tmp2 = %f\n", tmp1, tmp2);

  tmp2 = 2.5;
  tmp1 = const3;
  tmp2 = tmp2 + const3;
  printf("Mit Const: tmp1 = %f, tmp2 = %f\n", tmp1, tmp2);

  tmp2 = foo(tmp1);
  printf("Unterprogramm: tmp1 = %f, tmp2 = %f\n", tmp1, tmp2);
  
  return 0;
}

