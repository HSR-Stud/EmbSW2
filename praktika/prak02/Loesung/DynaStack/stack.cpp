/*
 * stack.cpp
 *
 *  Created on: 24.02.2013
 *      Author: rbondere
 */

#include "slist.h"

template<typename ElemType>
Stack<ElemType>::Stack() :
  error(false)
{
}

template<typename ElemType>
Stack<ElemType>::~Stack()
{
}

template<typename ElemType>
void Stack<ElemType>::push(ElemType e)
{
  error = false;
  list.insertAt(0, e); // insert at head
}

template<typename ElemType>
ElemType Stack<ElemType>::pop()
{
  error = list.isEmpty();
  if (!error)
  {
    ElemType e = list.getValue(1); // pos == 1: element at head
    list.deleteAt(1);
    return e;
  }
  else
    return 0;
}

template<typename ElemType>
ElemType Stack<ElemType>::peek() const
{
  error = list.isEmpty();
  if (!error)
  {
    return list.getValue(1); // pos == 1: element at head
  }
  else
    return 0;
}

template<typename ElemType>
bool Stack<ElemType>::isEmpty() const
{
  return list.isEmpty();
}

template<typename ElemType>
int Stack<ElemType>::getDepth() const
{
  return list.getNumber();
}

template<typename ElemType>
bool Stack<ElemType>::wasError() const
{
  return error;
}
