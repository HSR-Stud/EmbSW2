/*
 * MeasureList.h
 *
 *  Created on: 24.02.2013
 *      Author: rbondere
 *  Aggregation version (no inheritance)
 */

#ifndef MEASURELIST_H_
#define MEASURELIST_H_

#include "SList.h"

class MeasureList
{
  public:
    MeasureList(double tol = 20.0);
    void insertValue(double val);
    void setTolerance(double tol);
    double getMean(); // returns mean value
    void exclude(); // excludes values beyond tolerance band
    void print() const; // prints content of list
  private:
    SList<double> list;
    double tolerance; // in percent
};

#endif /* MEASURELIST_H_ */
