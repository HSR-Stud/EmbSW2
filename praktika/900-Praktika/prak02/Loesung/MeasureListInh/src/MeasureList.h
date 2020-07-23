/*
 * MeasureList.h
 *
 *  Created on: 26.02.2015
 *      Author: rbondere
 *  Inheritance version
 */

#ifndef MEASURELIST_H_
#define MEASURELIST_H_

#include "SList.h"

class MeasureList: public SList<double>
{
  public:
    MeasureList(double tol = 20.0);
    void insertValue(double val);
    void setTolerance(double tol);
    double getMean(); // returns mean value
    void exclude(); // excludes values beyond tolerance band
  private:
    double tolerance; // in percent
};

#endif /* MEASURELIST_H_ */
