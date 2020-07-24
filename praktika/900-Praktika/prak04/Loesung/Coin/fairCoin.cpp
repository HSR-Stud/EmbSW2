//================================================
// Name        : biasedCoin.cpp
// Author      : Reto Bonderer
// Version     : 20190528
// Copyright   : (c) HSR R. Bonderer
// Description : Get a uniform distribution from a biased coin
//=================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

enum
{
  iterations = 10000000 // number of iterations
};

// returns a biased coin value (0, 1)
unsigned int biasedCoin();

// returns a fair coin value (0, 1) using biasedCoin()
unsigned int fairCoin();

int main()
{
  unsigned int histogram[2] = {0};
  srand(time(0));

  for (unsigned int i = 0; i < iterations; ++i)
  {
    ++histogram[fairCoin()];
  }
  for (int i = 0; i < 2; ++i)
    cout << i << ": " << setw(10) << histogram[i] << " (" 
         << histogram[i]*100.0/iterations << " %)" << endl;

  return 0;
}

unsigned int biasedCoin()
{
  enum
  {
    bias = 60   // p(0) = bias in percent, p(1) = 1-p(0)
  };

  if (rand() < RAND_MAX/100*bias)
    return 0;
  else 
    return 1;
}

unsigned int fairCoin()
{
  while (1)
  {
    unsigned int first = biasedCoin();
    unsigned int second = biasedCoin();
    if (first == 0 && second == 1)
      return 0;
    else if (first == 1 && second == 0)
      return 1;
  }
}

