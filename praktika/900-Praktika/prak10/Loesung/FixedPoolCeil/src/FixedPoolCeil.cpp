//===============================================
// Name        : FixedPoolCeil.cpp
// Author      : Reto Bonderer
// Version     : 02.06.2016
// Description : Fixed-size pool with upper limit implementation
//================================================

#include <iostream>
#include "PoolAllocator.h"
using namespace std;
using namespace dynamicMemory;

int main()
{
  enum
  {
    testHeapSize = 200, testElemSize = 8,
    nElems = testHeapSize / testElemSize,
    nPtrs = 80
  };
  static uint8_t buffer[testHeapSize]; // our heap
  void* p[nPtrs] = { nullptr }; // some void-pointers

  PoolAllocator<testHeapSize, testElemSize> pool(&buffer[0]);
  try
  {
    p[0] = pool.allocate(testElemSize);
    cout << "p[0] = " << hex << p[0] << endl;
    p[1] = pool.allocate(testElemSize);
    cout << "p[1] = " << hex << p[1] << endl;
    p[2] = pool.allocate(testElemSize - 1);                  // should work
    cout << "p[2] = " << hex << p[2] << endl;
    pool.deallocate(p[1]);
    cout << "p[1] = " << hex << p[1] << endl;
    p[3] = pool.allocate(testElemSize);
    cout << "p[3] = " << hex << p[3] << endl; // should be former address of p[1]
    p[4] = pool.allocate(testElemSize + 1);
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
  catch (...)
  {
    cout << "Shouldn't get here" << endl;
  }

  try
  {
    for (int i = 5; i < nElems + 2; ++i)  // there are 3 objects so far => (nElems-3) available
      p[i] = pool.allocate(testElemSize);
    cout << dec << "p[" << nElems + 1 << "] = " << hex << p[nElems + 1] << endl;
    cout << dec << "p[" << nElems + 2 << "] = " << hex << p[nElems + 2] << endl; // = 0
    p[nElems + 3] = pool.allocate(testElemSize); // should throw OutOfHeap exception
  }
  catch (const HeapSizeMismatch& e)
  {
    cout << "Heapsize mismatch exception occurred" << endl;
  }
  catch (const OutOfHeap& e)
  {
    cout << "Out of heap exception occurred" << endl;
  }
  catch (...)
  {
    cout << "Shouldn't get here" << endl;
  }

  cout << "Deallocate all";
  for (int i = 0; i < nPtrs; ++i)
  {
    try
    {
      pool.deallocate(p[i]);
      cout << ".";
    }
    catch (...)
    {
      cout << "Shouldn't get here" << endl;
    }
  }
  return 0;
}
