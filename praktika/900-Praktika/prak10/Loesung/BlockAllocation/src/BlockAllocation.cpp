//============================================================================
// Name        : BlockAllocation.cpp
// Author      : Reto Bonderer
// Version     : 02.06.2016
// Description : Block allocation with 4 fixed-size pools
//============================================================================

#include <iostream>
#include "BlockAllocator.h"
using namespace std;
using namespace dynamicMemory;

int main()
{
  enum
  {
    testPool1Size = 200, testElem1Size = 4,
    testPool2Size = 200, testElem2Size = 8,
    testPool3Size = 512, testElem3Size = 32,
    testPool4Size = 1024, testElem4Size = 128,
    nPtrs = 20
  };
  static uint8_t pool1Heap[testPool1Size];
  static uint8_t pool2Heap[testPool2Size];
  static uint8_t pool3Heap[testPool3Size];
  static uint8_t pool4Heap[testPool4Size];

  BlockAllocator<testPool1Size, testElem1Size,
                 testPool2Size, testElem2Size,
                 testPool3Size, testElem3Size,
                 testPool4Size, testElem4Size> block(&pool1Heap[0], &pool2Heap[0],
                                                     &pool3Heap[0], &pool4Heap[0]);

  void* p[nPtrs] = { nullptr }; // some void-pointers
  cout << "Memory Map" << endl;
  cout << "Pool 1: " << hex << (void*)pool1Heap << "-"
       << (void*)(pool1Heap + testPool1Size - 1) << " size: " << dec
       << testPool1Size << endl;
  cout << "Pool 2: " << hex << (void*)pool2Heap << "-"
       << (void*)(pool2Heap + testPool2Size - 1) << " size: " << dec
       << testPool2Size << endl;
  cout << "Pool 3: " << hex << (void*)pool3Heap << "-"
       << (void*)(pool3Heap + testPool3Size - 1) << " size: " << dec
       << testPool3Size << endl;
  cout << "Pool 4: " << hex << (void*)pool4Heap << "-"
       << (void*)(pool4Heap + testPool4Size - 1) << " size: " << dec
       << testPool4Size << endl;

  try  // ... some allocations
  {
    p[0] = block.allocate(4);
    cout << "p[0] = " << hex << p[0] << endl;
    p[1] = block.allocate(4);
    cout << "p[1] = " << hex << p[1] << endl;
    p[2] = block.allocate(3); // should work
    cout << "p[2] = " << hex << p[2] << endl;
    block.deallocate(p[1]);
    cout << "p[1] = " << hex << p[1] << endl;
    p[3] = block.allocate(4);
    cout << "p[3] = " << hex << p[3] << endl; // should be former address of p[1]
    p[4] = block.allocate(128);
    cout << "p[4] = " << hex << p[4] << endl;
    p[5] = block.allocate(140);
    cout << "p[5] = " << hex << p[5] << endl; // should throw HeapSizeMismatch exception
    p[6] = block.allocate(123);
    cout << "p[6] = " << hex << p[6] << endl;
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
      block.deallocate(p[i]);
      cout << ".";
    }
    catch (...)
    {
      cout << "Shouldn't get here" << endl;
    }
  }
  return 0;
}
