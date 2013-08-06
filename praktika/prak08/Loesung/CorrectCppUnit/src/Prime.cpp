// Filename: "Prime.cpp", 11.04.2013 phoerler

#include <string>

#include "Prime.h"

bool isPrime(int cand)
{
  int b = 2;
  bool p = true;
  if (cand < 2)
    return false;
  while (p && (b * b <= cand))
  {
    if (cand % b == 0)
      p = false;
    b++;
  }
  return p;
}
