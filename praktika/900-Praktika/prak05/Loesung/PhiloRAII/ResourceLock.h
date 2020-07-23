/*
 * ResourceLock.h
 * RAII implementation of lock/unlock mutex
 *
 *  Created on: Apr 08, 2019
 *      Author: reto.bonderer
 */

#ifndef RESOURCELOCK_H_
#define RESOURCELOCK_H_
#include <pthread.h>
class ResourceLock
{
  public:
    ResourceLock(pthread_mutex_t& m) :
        mutex(m)
    {
      pthread_mutex_lock(&mutex);
    }
    ~ResourceLock()
    {
      pthread_mutex_unlock(&mutex);
    }
  private:
    pthread_mutex_t& mutex; // mutex of shared resource
};

#endif /* RESOURCELOCK_H_ */
