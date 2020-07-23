/*
 * Sticks.cpp
 *
 * Dining Philosophers: Sticks class (Monitor) using RAII
 *
 *  Created on: 25.03.2020
 *      Author: Reto Bonderer
 */

#include <pthread.h>
#include "Sticks.h"
#include "ResourceLock.h"

Sticks::Sticks(int nr)
  : nSticks(nr), 
    stick(new bool[nSticks])
{
  for (int i = 0; i < nSticks; ++i)
    stick[i] = false;
  
  // Initialize mutex and condition variable objects
  pthread_mutex_init(&stickMutex, 0);
  pthread_cond_init (&stickCv, 0);
}

Sticks::~Sticks()
{
  delete[] stick;
  pthread_mutex_destroy(&stickMutex);
  pthread_cond_destroy(&stickCv);
}

void Sticks::put(int left, int right)
{
  {                                      // start of CS
		ResourceLock lock(stickMutex);
		stick[left] = false;
		stick[right] = false;
		pthread_cond_signal(&stickCv);
  }                                      // end of CS
}

void Sticks::get(int left, int right)
{
  {                                      // start of CS
		ResourceLock lock(stickMutex);
		while (stick[left] || stick[right]) 
		{
		  pthread_cond_wait(&stickCv, &stickMutex);
		}
		stick[left] = true;
		stick[right] = true;
  }                                      // end of CS
}

