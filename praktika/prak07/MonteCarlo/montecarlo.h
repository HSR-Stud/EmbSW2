/*
 * montecarlo.h
 *
 *  Created on: 13.04.2011
 *      Author: rbondere
 */

#ifndef MONTECARLO_H_
#define MONTECARLO_H_

// integrates the function f within [lb,hb], stops as soon as change <= epsilon
double monteCarlo(double(*f)(double x), // ptr to function to integrate
                  double lb, // lower bound
                  double hb, // higher bound
                  double height, // must be higher than max of f(x) within [lb,hb]
                  double epsilon = 1e-5, // minimal change
                  unsigned long minIterations = 10000); // minimal number of iterations
#endif /* MONTECARLO_H_ */
