/*
 * List.cpp
 *
 *  Created on: 23.02.2012
 *      Author: rbondere
 */


#include <cassert>

template <typename Item>
List<Item>::List() :
    nr(0), currPos(0)
{
}

template <typename Item>
List<Item>::~List()
{
}

template <typename Item>
bool List<Item>::isEmpty() const
{
  return nr == 0;
}

template <typename Item>
int List<Item>::getNumber() const
{
  return nr;
}

template <typename Item>
int List<Item>::getNext() const
{
  if (currPos >= nr)
    return 0;
  else
    return currPos + 1;
}

template <typename Item>
void List<Item>::setPosition(int pos)
{
  assert(pos >= 0 && pos <= nr);
  currPos = pos;
}

template <typename Item>
int List<Item>::getPosition() const
{
  return currPos;
}

