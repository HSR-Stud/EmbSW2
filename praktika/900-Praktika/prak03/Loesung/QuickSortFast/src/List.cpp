/*
 * List.cpp
 *
 *  Created on: 01.03.2017
 *      Author: rbondere
 */

#include <cstdlib>
#include <ctime>
#include "List.h"

List::List(int theSize, int theThreshold, int rSeed) :
  size(theSize), threshold(theThreshold), data(new int[size]), randomSeed(rSeed)
{
}

List::~List()
{
  delete[] data;
}

void List::quickSort(int leftBound,
                     int rightBound)
{
  if (rightBound-leftBound < threshold)
    insertionSort(&data[leftBound], rightBound-leftBound+1);

  int left = leftBound; // index of left boundary
  int right = rightBound; // index of right boundary
  int pivot = data[(left + right) / 2]; // select middle element in array

  do
  {
    while (data[left] < pivot)
      ++left;
    while (data[right] > pivot)
      --right;

    if (left <= right)
    {
      if (left < right)
        swap(data[left], data[right]);
      ++left;
      --right;
    }
  } while (left <= right);

  if (leftBound < right)
    quickSort(leftBound, right);
  if (rightBound > left)
    quickSort(left, rightBound);

}

inline void List::insertionSort(int* d,
                                int listLength)
{
  int j;
  int buf; // Buffer

  for (int i = 1; i < listLength; i++)
  {
    buf = d[i];
    j = i;
    while (j > 0 && buf < d[j-1])
    {
      d[j] = d[j-1];
      j = j - 1;
    }
    d[j] = buf;
  }
}

void List::randomFill()
{
  srand(randomSeed);
  for (int i = 0; i < size; ++i)
    data[i] = rand();
}

void List::swap(int& a,
                int& b)
{
  int tmp = a;
  a = b;
  b = tmp;
}
