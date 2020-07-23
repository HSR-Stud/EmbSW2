/*
 * MeasureList.cpp
 *
 *  Created on: 26.02.2015
 *      Author: rbondere
 */

#include <cmath>
#include "MeasureList.h"

MeasureList::MeasureList(double tol) :
  tolerance(tol)
{
}

void MeasureList::setTolerance(double tol)
{
  tolerance = tol;
}

void MeasureList::exclude()
{
  double mean = getMean();
  // caution: mean may be negative
  double lower = mean - tolerance / 100.0 * fabs(mean);
  double higher = mean + tolerance / 100.0 * fabs(mean);
  for (int pos = 1; pos <= getNumber(); ++pos)
  {
    if (getValue(pos) < lower || getValue(pos) > higher)
    {
      deleteAt(pos);
      --pos;  // decrease position in this case
    }
  }
}

void MeasureList::insertValue(double val)
{
  insertAt(0, val); // inserts value at head
}

double MeasureList::getMean()
{
  double sum = 0.0;
  int nr = getNumber();
  for (int pos = 1; pos <= nr; ++pos)
  {
    sum += getValue(pos);
  }

  assert(nr);
  return sum / nr;
}

