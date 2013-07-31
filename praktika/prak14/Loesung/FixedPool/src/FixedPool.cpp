//============================================================================
// Name        : FixedPool.cpp
// Author      : Reto Bonderer
// Version     : 2012-05-30
// Description : Fixed-size pool implementation
//============================================================================

#include <iostream>
#include "PoolAllocator.h"
using namespace std;
using namespace dynamicMemory;

int main()
{
  enum
  {
    testHeapSize = 200, testElemSize = 4
  };
  uint8_t buffer[testHeapSize]; // our heap
  void* p[80] = {0}; // some void-pointers

  PoolAllocator<testHeapSize, testElemSize> pool(&buffer[0]);
  try
  {
    p[0] = pool.allocate(4);
    cout << "p[0] = " << hex << p[0] << endl;
    p[1] = pool.allocate(4);
    cout << "p[1] = " << hex << p[1] << endl;
    p[2] = pool.allocate(4);
    cout << "p[2] = " << hex << p[2] << endl;
    pool.deallocate(p[1]);
    cout << "p[1] = " << hex << p[1] << endl;
    p[3] = pool.allocate(4);
    cout << "p[3] = " << hex << p[3] << endl; // should be former address of p[1]
    p[4] = pool.allocate(5);
    cout << "p[4] = " << hex << p[4] << endl; // should throw HeapSizeMismatch exception

  }
  catch (const HeapSizeMismatch& e)
  {
    cout << "Heapsize mismatch exception occurred" << endl;
  }
  catch (const OutOfHeap& e)
  {
    cout << "Out of heap exception occurred" << endl;
  }

  try
  {
    for (int i = 5; i <= testHeapSize / testElemSize + 1; ++i)
      p[i] = pool.allocate(4);
    cout << dec << "p[" << testHeapSize / testElemSize + 1 << "] = " << hex
         << p[testHeapSize / testElemSize + 1]
         << endl;
    cout << dec << "p[" << testHeapSize / testElemSize + 2 << "] = " << hex
         << p[testHeapSize / testElemSize + 2]
         << endl;

    p[testHeapSize / testElemSize + 2] = pool.allocate(4); // should throw OutOfHeap exception

  }
  catch (const HeapSizeMismatch& e)
  {
    cout << "Heapsize mismatch exception occurred" << endl;
  }
  catch (const OutOfHeap& e)
  {
    cout << "Out of heap exception occurred" << endl;
  }

  return 0;
}
