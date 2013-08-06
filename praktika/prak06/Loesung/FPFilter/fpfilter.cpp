/*
 * fpfilter.cpp
 *
 * computes the convolution of a filter and a data file
 *
 *  Created on: 25.03.2013
 *      Author: rbondere
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "fpfilter.h"
using namespace std;

int getFilterSize(const char* filter)
{
  ifstream fin(filter);
  if (!fin.is_open())
  {
    cerr << "Failed to open " << filter;
    exit(1);
  }

  int len = 0;
  double d;
  while (fin >> d)
    ++len;
  return len;
}

void readFilter(const char* file,
                double buffer[])
{
  ifstream fin(file);
  if (!fin.is_open())
  {
    cerr << "Error: failed to open " << file;
    exit(1);
  }

  int len = 0;
  while (fin >> buffer[len++])
  {
  }
}

double convolve(const double filter[],
                const double buffer[],
                int lf,
                int pos)
{
  double sum = 0;
  for (int k = 0; k < lf; ++k)
  {
    sum += filter[k] * buffer[(lf + pos - k) % lf];
  }
  return sum;
}
