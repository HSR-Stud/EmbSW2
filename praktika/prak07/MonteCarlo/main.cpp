/*
 * main.cpp
 *
 *  Created on: 13.04.2011
 *      Author: rbondere
 */
#include <cmath>
#include <iostream>
#include <iomanip>
#include "montecarlo.h"
using namespace std;

double myF(double x); // function to integrate
double myCircle(double x); // circle function

int main()
{
  double lb = 1.0; // lower bound
  double hb = 1.4; // higher bound
  double height = 0.1;
  double epsilon = 1e-8; // accuracy
  double integral = monteCarlo(myF, lb, hb, height, epsilon);
  cout << setprecision(10) << "Integral: " << integral << endl;

  cout << "---- Pi ----" << endl;
  double piEstimate = 4.0 * monteCarlo(myCircle, 0.0, 1.0, 1.0, 1e-8);
  cout << "Accurate Pi:  " << M_PI << endl;
  cout << "Estimated Pi: " << piEstimate << endl;
  return 0;
}

double myF(double x)
{
  return sqrt((x - 1) * (2 - x)) * exp(-x * x);
}

double myCircle(double x)
{
  return sqrt(1.0 - x * x);
}
