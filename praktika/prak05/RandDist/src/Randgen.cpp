/*
 * Randgen.cpp
 *
 *  Created on: 18.03.2013
 *      Author: rbondere
 */
#include <cstdlib>
#include <cmath>
#include "Randgen.h"

using namespace std;

Randgen::Randgen(int seed)
{
  srand(seed);
}

int Randgen::getUniform(int low,
                        int high)
{
  return static_cast<int> (static_cast<double> (rand()) / (RAND_MAX + 1.0)
      * (high - low + 1)) + low;
  // '(RAND_MAX + 1.0)' ist notwendig, damit 0 <= u < 1.0 (ohne 1.0)
  // '+ 1' ist notwendig, weil nach int konvertiert wird.
  // Vor Konversion gibt es dadurch bei [1,20] Zahlen im Bereich [0.0,20.0[
  // Nach Konversion werden nur die ganzzahligen Anteile verwendet
  // Das hinterste "+ low" muss ausserhalb des Typecasts sein, andernfalls
  // ergibt es ein Überhöhung bei 0, falls low < 0 (alle Zahlen in 
  // [-0.9999, +0.9999] würden zu 0, d.h. doppelt so viele wie erlaubt)
}

int Randgen::getNormal(double mean,
                       double sdev)
{
  double v1;
  double v2;
  double s;
  do
  {
    v1 = 2 * static_cast<double> (rand()) / RAND_MAX - 1.0;
    v2 = 2 * static_cast<double> (rand()) / RAND_MAX - 1.0;
    s = v1 * v1 + v2 * v2;
  } while (s >= 1.0 || s == 0.0);
  double temp = sqrt(-2.0 * log(s) / s);
  return lround(v1 * temp * sdev + mean);
  // bei clipping (ohne lround(), sondern mit (int)) wird der Zufallswert
  // bei 0 doppelt gewertet!!
}

int Randgen::getRayleigh(double sdev)
{
  double v1;
  double v2;
  double s;
  double w1;
  double w2;
  do
  {
    v1 = 2 * static_cast<double> (rand()) / RAND_MAX - 1.0;
    v2 = 2 * static_cast<double> (rand()) / RAND_MAX - 1.0;
    s = v1 * v1 + v2 * v2;
  } while (s >= 1.0 || s == 0.0);
  double temp = sqrt(-2.0 * log(s) / s);
  w1 = (v1 * temp * sdev);
  w2 = (v2 * temp * sdev);
  return lround(sqrt(w1 * w1 + w2 * w2));
}

int Randgen::getWeibull(double alpha,
                        double beta)
{
  double u;
  double w;
  u = static_cast<double> (rand()) / (RAND_MAX + 1.0); // 0.0 <= u < 1.0
  w = beta * pow(-log(1.0 - u), 1 / alpha);
  return static_cast<int> (w);
}

