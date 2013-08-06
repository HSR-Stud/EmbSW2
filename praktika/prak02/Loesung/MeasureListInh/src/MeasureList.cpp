/*
 * MeasureList.cpp
 *
 *  Created on: 03.03.2011
 *      Author: rbondere
 */

#include <cmath>
#include "MeasureList.h"

MeasureList::MeasureList(double tol) :
  tolerance(tol)
{
}

MeasureList::~MeasureList()
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
  double lower = mean - tolerance / 100 * fabs(mean);
  double higher = mean + tolerance / 100 * fabs(mean);
  int pos;
  for (setPosition(0); (pos = getNext()) != 0; /* nothing to do */)
  {
    if (getValue(pos) < lower || getValue(pos) > higher)
      deleteAt(pos);
  }
}

void MeasureList::insertValue(double val)
{
  insertAt(0, val); // inserts value at head
}

double MeasureList::getMean()
{
  double sum = 0;
  int pos = 0;
  for (setPosition(pos); (pos = getNext()) != 0; sum += getValue(pos))
  {
  }
  int nr = getNumber();
  assert(nr);
  return sum / nr;
}

