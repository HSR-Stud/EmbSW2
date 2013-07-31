/*
 * List.h
 *
 *  Created on: 04.03.2013
 *      Author: rbondere
 */

#ifndef LIST_H_
#define LIST_H_

class List
{
  public:
    List(int theSize = 100, int theThreshold = 1);
    virtual ~List();
    void quickSort(int leftBound,
                   int rightBound);
    void insertionSort(int* d,          // start of list
                       int listLength);
    void randomFill(); // fill list with random values
  private:
    int* data; // dynamic array
    int size;
    int threshold;
    void swap(int& a,
              int& b);
};

#endif /* LIST_H_ */
