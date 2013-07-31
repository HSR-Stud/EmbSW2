/*
 * Randgen.h
 *
 *  Created on: 18.03.2013
 *      Author: rbondere
 */

#ifndef RANDGEN_H_
#define RANDGEN_H_

class Randgen
{
  public:
    Randgen(int seed = 0);

    // returns a uniformly distributed random int value
    int getUniform(int low, // lowest random value
                   int high); // highest random value

    // returns a normally distributed random int value
    int getNormal(double mean, // mean (expected value)
                  double sdev); // standard deviation
    // returns a Rayleigh distributed random int value
    int getRayleigh(double sdev); // standard deviation

    // returns a Weibull distributed random int value
    int getWeibull(double alpha,
                   double beta);
};

#endif /* RANDGEN_H_ */
