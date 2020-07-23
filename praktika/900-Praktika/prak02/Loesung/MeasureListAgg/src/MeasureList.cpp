/*
 * MeasureList.cpp
 *
 *  Created on: 24.02.2013
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
  for (int pos = 1; pos <= list.getNumber(); ++pos)
  {
    if (list.getValue(pos) < lower || list.getValue(pos) > higher)
    {
      list.deleteAt(pos);
      --pos;
    }
  }
}

void MeasureList::insertValue(double val)
{
  list.insertAt(0, val); // inserts value at head
}

void MeasureList::print() const
{
  list.print();
}

double MeasureList::getMean()
{
  double sum = 0;
  int nr = list.getNumber();
  for (int pos = 1; pos <= nr; ++pos)
  {
    sum += list.getValue(pos);
  }
  assert(nr);
  return sum / nr;
}

