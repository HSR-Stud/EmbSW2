/*
 * PoolAllocator.h
 *
 *  Created on: 30.05.2012
 *      Author: rbondere
 */

#ifndef POOLALLOCATOR_H_
#define POOLALLOCATOR_H_

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
    PoolAllocator(uint8_t* heapAddr) :
        freeList(reinterpret_cast<Node*>(heapAddr))
    {
      for (std::size_t i = 0; i < heapSize / elemSize - 1; ++i) // link array elements together
        freeList[i].next = &freeList[i + 1];
      freeList[heapSize / elemSize - 1].next = 0;
    }

    void* allocate(std::size_t bytes) throw(HeapException)
    {
      if (bytes != elemSize)
        throw HeapSizeMismatch();
      if (freeList != 0)
      {
        void* pMem = freeList;
        freeList = freeList->next;
        return pMem;
      }
      else
        throw OutOfHeap();
    }

    void deallocate(void*& ptr) throw()
    {
      if (ptr == 0)
        return;
      Node* p = static_cast<Node*>(ptr);
      p->next = freeList;
      freeList = p;
      ptr = 0;
    }

  private:
    union Node
    {
        uint8_t data[elemSize];
        Node* next;
    };
    Node* freeList;
};

} /* namespace dynamicMemory */

#endif /* POOLALLOCATOR_H_ */
