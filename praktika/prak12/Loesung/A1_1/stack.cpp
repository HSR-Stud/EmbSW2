/*
 * stack.cpp
 *
 *  Created on: 25.05.2010
 *      Author: rbondere
 */


template<typename ElemType, int size>
Stack<ElemType, size>::Stack() :
  top(0), error(false)
{
}

template<typename ElemType, int size>
void Stack<ElemType, size>::push(ElemType e)
{
  error = isFull();
  if (!error)
  {
    elems[top] = e;
    top++;
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

