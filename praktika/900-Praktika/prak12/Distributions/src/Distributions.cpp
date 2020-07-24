//===========================================================
// Name        : Distributions.cpp
// Author      : Reto Bonderer
// Version     :
// Copyright   : (c) HSR R. Bonderer
// Description : Tests various integer random distributions
//===========================================================

#include <iostream>
#include <iomanip>
#include <random>
#include "RandIntGen.h"

using namespace std;

int main()
{
  enum
  {
    minValue = 1, // minimal value for random numbers
    maxValue = 20, // maximal value for random numbers
    stdDev = 2, // normal distribution standard deviation
    mean = 11, // normal distribution mean
    wbAlpha = 2, // weibull alpha
    wbBeta = 3, // weibull beta
    iterations = 20000 // number of iterations
  };

  int histogram[maxValue - minValue + 1] = {0};
  RandIntGen rg(time(0));
  std::random_device rDev;
  std::default_random_engine rgStd(rDev());
  int r;

  // uniform distribution
  cout << "Uniform distribution" << endl;
  for (int i = 0; i < iterations; ++i)
  {
    r = rg.getUniform(minValue, maxValue);
    ++histogram[r - minValue];
  }
  for (int i = 0; i < maxValue - minValue + 1; ++i)
  {
    cout << histogram[i] << " ";
  }
  cout << endl;

  // uniform distribution using std library random generators
  for (int i = 0; i < maxValue - minValue + 1; ++i)
  {
    histogram[i] = 0;
  }
  cout << "Uniform distribution (std library)" << endl;
  std::uniform_int_distribution<int> uniformDist(minValue, maxValue);
  for (int i = 0; i < iterations; ++i)
  {
    r = uniformDist(rgStd);
    ++histogram[r - minValue];
  }
  for (int i = 0; i < maxValue - minValue + 1; ++i)
  {
    cout << histogram[i] << " ";
  }
  cout << endl;

  // normal distribution
  for (int i = 0; i < maxValue - minValue + 1; ++i)
  {
    histogram[i] = 0;
  }
  cout << "Normal distribution" << endl;
  for (int i = 0; i < iterations; i++)
  {
    r = rg.getNormal(mean, stdDev);
    if (r >= 0 && r <= maxValue-minValue)    // r could be beyond array limits
      ++histogram[r];
  }
  for (int i = 0; i < maxValue - minValue + 1; ++i)
  {
    cout << histogram[i] << " ";
  }
  cout << endl;

  // normal distribution using std library random generators
  for (int i = 0; i < maxValue - minValue + 1; ++i)
  {
    histogram[i] = 0;
  }
  cout << "Normal distribution (std library)" << endl;
  std::normal_distribution<double> normalDist(mean, stdDev);
  for (int i = 0; i < iterations; i++)
  {
    r = std::round(normalDist(rgStd));
    if (r >= 0 && r <= maxValue-minValue)    // r could be beyond array limits
      ++histogram[r];
  }
  for (int i = 0; i < maxValue - minValue + 1; ++i)
  {
    cout << histogram[i] << " ";
  }
  cout << endl;

  // Weibull distribution
  for (int i = 0; i < maxValue - minValue + 1; ++i)
  {
    histogram[i] = 0;
  }
  cout << "Weibull distribution" << endl;
  for (int i = 0; i < iterations; ++i)
  {
    r = rg.getWeibull(wbAlpha, wbBeta);
    if (r >= 0 && r <= maxValue-minValue)    // r could be beyond array limits
      ++histogram[r];
  }
  for (int i = 0; i < maxValue - minValue + 1; ++i)
  {
    cout << histogram[i] << " ";
  }
  cout << endl;

  // Weibull distribution using std library random generators
  for (int i = 0; i < maxValue - minValue + 1; ++i)
  {
    histogram[i] = 0;
  }
  cout << "Weibull distribution (std library)" << endl;
  std::weibull_distribution<double> weibullDist(wbAlpha, wbBeta);
  for (int i = 0; i < iterations; ++i)
  {
    r = std::round(weibullDist(rgStd));
    if (r >= 0 && r <= maxValue-minValue)    // r could be beyond array limits
      ++histogram[r];
  }
  for (int i = 0; i < maxValue - minValue + 1; ++i)
  {
    cout << histogram[i] << " ";
  }
  cout << endl;


  return 0;
}
