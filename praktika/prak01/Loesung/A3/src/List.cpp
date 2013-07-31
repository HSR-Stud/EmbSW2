/*
 * List.cpp
 *
 *  Created on: 19.02.2013
 *      Author: rbondere
 */

#include <cassert>
#include "List.h"

List::List() :
    currPos(0), nr(0)
{
}

List::~List()
{
}

bool List::isEmpty() const
{
  return nr == 0;
}

int List::getNumber() const
{
  return nr;
}

int List::getNext() const
{
  if (currPos >= nr)
    return 0;
  else
    return currPos + 1;
}

void List::setPosition(int pos)
{
  assert(pos >= 0 && pos <= nr);
  currPos = pos;
}

int List::getPosition() const
{
  return currPos;
}

