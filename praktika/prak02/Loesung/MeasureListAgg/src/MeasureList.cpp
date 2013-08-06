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
  double lower = mean - tolerance / 100 * fabs(mean);
  double higher = mean + tolerance / 100 * fabs(mean);
  int pos;
  for (list.setPosition(0); (pos = list.getNext()) != 0; /* nothing to update */ )
  {
    if (list.getValue(pos) < lower || list.getValue(pos) > higher)
      list.deleteAt(pos);
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
  int pos = 0;
  for (list.setPosition(pos); (pos = list.getNext()) != 0; sum += list.getValue(pos))
  {
  }
  int nr = list.getNumber();
  assert(nr);
  return sum / nr;
}

