/*
 * Philosopher.h
 *
 * Dining Philosophers: Philosopher class
 *
 *  Created on: 20.12.2016
 *      Author: Reto Bonderer
 */
#ifndef PHILOSOPHER_H_
#define PHILOSOPHER_H_
#include <pthread.h>
#include "Sticks.h"

class Philosopher
{
  public:
    Philosopher(int pid, int thinkdelay, int eatDelay, Sticks& s);
    ~Philosopher();
    void live();        // the philosopher's life
    void join();        // wait for philosopher to leave
  private:
    enum {nMeals = 3};
    int id;             // this philosopher's id
    int tDelay;         // how long does this philosopher think?
    int eDelay;         // how long does this philosopher eat?
    int left;           // left fork number
    int right;          // right fork number
    Sticks& stick;      // sticks used by all philosophers
    pthread_attr_t attr;
    pthread_t tid;      // thread id
    void lifeThread();  // the (C++) - thread function
    static void* staticWrapper(void* p) // C Wrapper for pthread_create()
	  {                                   // p must be the this pointer
		  static_cast<Philosopher*>(p)->lifeThread();
  		return 0;
	  }
};

#endif
