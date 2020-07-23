/*
 * Stack.cpp
 *
 *  Created on: 24.04.2015
 *      Author: rbondere
 */


template<typename ElemType, int size>
Stack<ElemType, size>::Stack() :
  top(0), error(false)
{
}

template<typename ElemType, int size>
void Stack<ElemType, size>::push(const ElemType& e)
{
  error = isFull();
  if (!error)
  {
    elems[top] = e;
    ++top;
  }
}

template<typename ElemType, int size>
ElemType Stack<ElemType, size>::pop()
{
  error = isEmpty();
  if (!error)
  {
    --top;
    return elems[top];
  }
  else
    return 0;
}

template<typename ElemType, int size>
ElemType Stack<ElemType, size>::peek() const
{
  error = isEmpty();
  if (!error)
    return elems[top - 1];
  else
    return 0;
}

template<typename ElemType, int size>
bool Stack<ElemType, size>::isFull() const
{
  return top == size;
}

