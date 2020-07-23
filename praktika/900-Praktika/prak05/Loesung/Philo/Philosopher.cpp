/*
 * Philosopher.cpp
 *
 * Dining Philosophers: Philosopher class
 *
 *  Created on: 24.03.2020
 *      Author: Reto Bonderer
 */
#include <iostream>
#include <unistd.h>
#include "Philosopher.h"
#include "Sticks.h"
using namespace std;

Philosopher::Philosopher(int pid, int thinkDelay, int eatDelay, Sticks& s)
  : id(pid),
    tDelay(thinkDelay),
    eDelay(eatDelay),
    stick(s)
{
  left = id==1? stick.getNr() - 1: id-2; // follow the anti deadlock strategy
  right = id-1;
}
    
Philosopher::~Philosopher()
{
  pthread_attr_destroy(&attr);
}
    
void Philosopher::live()
{
  // For portability, explicitly create threads in a joinable state
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_create(&tid, &attr, staticWrapper, this); // call the static wrapper
}

void Philosopher::join()
{
  pthread_join(tid, 0);
}

void Philosopher::lifeThread()
{
  for (int i = 0 ; i < nMeals; ++i)
  {
    cout << "Philosopher " << id << " is thinking..." << endl;
    usleep(tDelay);
    cout << "Philosopher " << id << " likes to eat..." << endl;
    stick.get(left, right);
    cout << "Philosopher " << id << " is eating..." << endl;
    usleep(eDelay);
    cout << "Philosopher " << id << " puts sticks back..." << endl;
    stick.put(left, right);
  }
  cout << "Philosopher " << id << " leaves." << endl;
  pthread_exit(0);
}

