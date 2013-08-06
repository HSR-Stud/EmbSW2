/*
 * MeasureList.h
 *
 *  Created on: 03.03.2011
 *      Author: rbondere
 *  Aggregation version (no inheritance)
 */

#ifndef MEASURELIST_H_
#define MEASURELIST_H_

#include "SList.h"

class MeasureList: public SList<double>
{
  public:
    MeasureList(double tol = 20);
    virtual ~MeasureList();
    void insertValue(double val);
    void setTolerance(double tol);
    double getMean(); // returns mean value
    void exclude(); // excludes values beyond tolerance band
  private:
    double tolerance; // in percent
};

#endif /* MEASURELIST_H_ */
