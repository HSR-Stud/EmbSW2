/*
 * Randgen.h
 *
 *  Created on: 19.03.2015
 *      Author: rbondere
 */

#ifndef RANDINTGEN_H_
#define RANDINTGEN_H_

class RandIntGen
{
  public:
    RandIntGen(int seed = 0);

    // returns a uniformly distributed random int value
    int getUniform(int low,             // lowest random value
                   int high) const;     // highest random value

    // returns a normally distributed random int value
    int getNormal(double mean,          // mean (expected value)
                  double sdev) const;   // standard deviation

    // returns a Weibull distributed random int value
    int getWeibull(double alpha,
                   double beta) const;
};

#endif /* RANDINTGEN_H_ */
