//============================================================================
// Name        : RandDist.cpp
// Author      : Reto Bonderer
// Version     :
// Copyright   : (c) HSR R. Bonderer
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include "Randgen.h"

using namespace std;

int main()
{
  enum
  {
    minValue = 1, // minimal value for random numbers
    maxValue = 20, // maximal value for random numbers
    iterations = 20000
  // number of iterations
  };
  int histogram[maxValue - minValue + 1] = {0};
  Randgen rg(time(0));
  int r;
  // uniform distribution
  cout << "Uniform distribution" << endl;
  for (int i = 0; i < iterations; ++i)
  {

    r = rg.getUniform(minValue, maxValue);
    ++histogram[r - minValue];
  }
  for (int i = 0; i < maxValue - minValue + 1; ++i)
    cout << histogram[i] << " ";
  cout << endl;

  // normal distribution
  for (int i = 0; i < maxValue - minValue + 1; ++i)
    histogram[i] = 0;
  cout << "Normal distribution" << endl;
  for (int i = 0; i < iterations; i++)
  {

    r = rg.getNormal(11, 2);
    ++histogram[r - minValue];
  }
  for (int i = 0; i < maxValue - minValue + 1; ++i)
    cout << histogram[i] << " ";
  cout << endl;

  // Rayleigh distribution
  for (int i = 0; i < maxValue - minValue + 1; ++i)
    histogram[i] = 0;
  cout << "Rayleigh distribution" << endl;
  for (int i = 0; i < iterations; ++i)
  {

    r = rg.getRayleigh(3);
    ++histogram[r];
  }
  for (int i = 0; i < maxValue - minValue + 1; ++i)
    cout << histogram[i] << " ";
  cout << endl;

  // Weibull distribution
  for (int i = 0; i < maxValue - minValue + 1; ++i)
    histogram[i] = 0;
  cout << "Weibull distribution" << endl;
  for (int i = 0; i < iterations; ++i)
  {

    r = rg.getWeibull(2, 3);
    ++histogram[r];
  }
  for (int i = 0; i < maxValue - minValue + 1; ++i)
    cout << histogram[i] << " ";
  cout << endl;


  return 0;
}
