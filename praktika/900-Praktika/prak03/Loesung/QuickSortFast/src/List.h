/*
 * List.h
 *
 *  Created on: 01.03.2017
 *      Author: rbondere
 */

#ifndef LIST_H_
#define LIST_H_

class List
{
  public:
    List(int theSize = 100, int theThreshold = 1, int rSeed = 47);
    virtual ~List();
    void quickSort(int leftBound,
                   int rightBound);
    void insertionSort(int* d,          // start of list
                       int listLength);
    void randomFill(); // fill list with random values
  private:
    int size;  // size of list
    int threshold;
    int* data; // dynamic array
    int randomSeed;
    void swap(int& a,
              int& b);
};

#endif /* LIST_H_ */
