/*
 * montecarlo.cpp
 *
 *  Created on: 13.04.2011
 *      Author: rbondere
 */
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "montecarlo.h"
using namespace std;

double monteCarlo(double(*f)(double),
                  double lb,
                  double hb,
                  double height,
                  double epsilon,
                  unsigned long minIterations)
{
  double x;
  double y;
  double rectArea = (hb - lb) * height;
  double area = -rectArea; // must not be 0, unless rectArea == 0
  double oldArea;
  unsigned long n = 0;
  unsigned long count = 0;
  do
  {
    ++n;
    oldArea = area;
    x = (double)rand() / RAND_MAX * (hb - lb) + lb;
    y = (double)rand() / RAND_MAX * height;
    if (y <= f(x))
      ++count;
    area = (double)count / n * rectArea;
  } while (fabs(oldArea - area) > epsilon || n < minIterations);
  cout << "Epsilon: " << epsilon << endl;
  cout << "Number of iterations: " << n << endl;
  return area;
}

