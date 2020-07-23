/*
 * BlockAllocator.h
 *
 *  Created on: 27.04.2020
 *      Author: Reto Bonderer
 */

#ifndef BLOCKALLOCATOR_H_
#define BLOCKALLOCATOR_H_

#include "PoolAllocator.h"

namespace dynamicMemory
{

template<std::size_t pool1Size, std::size_t elem1Size,  // elem1Size <= elem2Size <= ...
         std::size_t pool2Size, std::size_t elem2Size,  // elem3Size <= elem4Size!!
         std::size_t pool3Size, std::size_t elem3Size,
         std::size_t pool4Size, std::size_t elem4Size>
class BlockAllocator
{
  public:
    BlockAllocator(uint8_t* pool1Heap,
                   uint8_t* pool2Heap,
                   uint8_t* pool3Heap,
                   uint8_t* pool4Heap) :
            pool1(pool1Heap),
            pool2(pool2Heap),
            pool3(pool3Heap),
            pool4(pool4Heap),
            pool1Addr(pool1Heap),
            pool2Addr(pool2Heap),
            pool3Addr(pool3Heap),
            pool4Addr(pool4Heap)
    {
    }
    void* allocate(std::size_t bytes);
    void deallocate(void*& ptr) noexcept;

  private:
    PoolAllocator<pool1Size, elem1Size> pool1;
    PoolAllocator<pool2Size, elem2Size> pool2;
    PoolAllocator<pool3Size, elem3Size> pool3;
    PoolAllocator<pool4Size, elem4Size> pool4;
    uint8_t* pool1Addr;
    uint8_t* pool2Addr;
    uint8_t* pool3Addr;
    uint8_t* pool4Addr;
};

template<std::size_t pool1Size, std::size_t elem1Size,
         std::size_t pool2Size, std::size_t elem2Size,
         std::size_t pool3Size, std::size_t elem3Size,
         std::size_t pool4Size, std::size_t elem4Size>
void* BlockAllocator<pool1Size, elem1Size, pool2Size, elem2Size,
                     pool3Size, elem3Size, pool4Size, elem4Size>::allocate(std::size_t bytes)
{
  void* p;
  try
  {
    p = pool1.allocate(bytes);
  }
  catch (const HeapException& e)
  {
    try
    {
      p = pool2.allocate(bytes);
    }
    catch (const HeapException& e)
    {
      try
      {
        p = pool3.allocate(bytes);
      }
      catch (const HeapException& e)
      {
        p = pool4.allocate(bytes);
      }
    }
  }
  return p;
}

template<std::size_t pool1Size, std::size_t elem1Size,
         std::size_t pool2Size, std::size_t elem2Size,
         std::size_t pool3Size, std::size_t elem3Size,
         std::size_t pool4Size, std::size_t elem4Size>
void BlockAllocator<pool1Size, elem1Size, pool2Size, elem2Size,
                    pool3Size, elem3Size, pool4Size, elem4Size>::deallocate(void*& ptr) noexcept
{
  if (ptr == nullptr)
    return;

  if (pool1Addr <= ptr && ptr < pool1Addr + pool1Size)
    pool1.deallocate(ptr);
  else if (pool2Addr <= ptr && ptr < pool2Addr + pool2Size)
    pool2.deallocate(ptr);
  else if (pool3Addr <= ptr && ptr < pool3Addr + pool3Size)
    pool3.deallocate(ptr);
  else if (pool4Addr <= ptr && ptr < pool4Addr + pool4Size)
    pool4.deallocate(ptr);
}

} /* namespace dynamicMemory */
#endif /* BLOCKALLOCATOR_H_ */
