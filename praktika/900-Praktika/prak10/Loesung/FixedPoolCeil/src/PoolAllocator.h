/*
 * PoolAllocator.h
 *
 *  Created on: 27.04.2020
 *      Author: Reto Bonderer
 */

#ifndef POOLALLOCATOR_H_
#define POOLALLOCATOR_H_

#include <stdint.h>

namespace dynamicMemory
{
class HeapException
{
};

class HeapSizeMismatch: public HeapException
{
};

class OutOfHeap: public HeapException
{
};

template<std::size_t heapSize, std::size_t elemSize>
class PoolAllocator
{
  public:
    PoolAllocator(uint8_t* heapAddr);
    void* allocate(std::size_t bytes);
    void deallocate(void*& ptr) noexcept; // void*& allows writing ptr
  private:
    union Node
    {
      uint8_t data[elemSize];
      Node* next;
    };
    Node* freeList;
};

template<std::size_t heapSize, std::size_t elemSize>
PoolAllocator<heapSize, elemSize>::PoolAllocator(uint8_t* heapAddr) :
    freeList(reinterpret_cast<Node*>(heapAddr))
{
  const std::size_t nElems = heapSize / sizeof(Node);
  for (std::size_t i = 0; i < nElems - 1; ++i) // link array elements together
    freeList[i].next = &freeList[i + 1];
  freeList[nElems - 1].next = nullptr;
}

template<std::size_t heapSize, std::size_t elemSize>
void* PoolAllocator<heapSize, elemSize>::allocate(std::size_t bytes)
{
  if (bytes > elemSize)
    throw HeapSizeMismatch();
  if (freeList != nullptr)
  {
    void* pMem = freeList;
    freeList = freeList->next;
    return pMem;
  }
  else
    throw OutOfHeap();
}

template<std::size_t heapSize, std::size_t elemSize>
void PoolAllocator<heapSize, elemSize>::deallocate(void*& ptr) noexcept
{
  if (ptr == nullptr)
    return;
  Node* p = static_cast<Node*>(ptr);
  p->next = freeList;
  freeList = p;
  ptr = nullptr;  // increases safety
}

} /* namespace dynamicMemory */

#endif /* POOLALLOCATOR_H_ */
