/*
 * PhiloTest.cpp
 *
 * Dining Philosophers: Philosopher test program
 *
 *
 *  Created on: 24.03.2020
 *      Author: Reto Bonderer
 */
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include "Philosopher.h"
#include "Sticks.h"
using namespace std;

enum {numPhilos = 5};

int main()
{
  Sticks s(numPhilos);  // shared resource
  Philosopher p[numPhilos] =
  {   // pid, thinkDelay, eatDelay, Sticks&
    Philosopher(1, 100000, 500000, s),
    Philosopher(2, 200000, 400000, s),
    Philosopher(3, 300000, 300000, s),
    Philosopher(4, 400000, 200000, s),
    Philosopher(5, 500000, 100000, s)
  };

  for (int i = 0 ; i < numPhilos; ++i)
  {
    p[i].live();
  }

  // wait for all philosophers to leave
  for (int i = 0 ; i < numPhilos; ++i)
  {
    p[i].join();
  } 
  return 0;
}

