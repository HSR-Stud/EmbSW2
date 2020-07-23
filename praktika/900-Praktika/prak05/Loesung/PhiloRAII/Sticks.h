/*
 * Sticks.h
 *
 * Dining Philosophers: Sticks class (Monitor)
 *
 *  Created on: 07.04.2016
 *      Author: Reto Bonderer
 */
#ifndef STICKS_H_
#define STICKS_H_

class Sticks
{
  public:
    Sticks(int nr = 5);
    ~Sticks();
    int getNr() const {return nSticks;}
    void put(int left, int right);  // lay down left and right stick
    void get(int left, int right);  // try to pick left and right stick
  private:
    int nSticks;
    volatile bool* stick;    // ptr to dynamic array
    pthread_mutex_t stickMutex;
    pthread_cond_t  stickCv;
};

#endif
