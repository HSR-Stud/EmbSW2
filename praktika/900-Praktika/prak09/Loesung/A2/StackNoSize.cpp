/*
 * StackNoSize.cpp
 *
 *  Created on: 24.04.2015
 *      Author: rbondere
 */


template<typename ElemType>
StackNoSize<ElemType>::StackNoSize(ElemType* pArr) :
  top(0), error(false), pElems(pArr)
{
}

template<typename ElemType>
ElemType StackNoSize<ElemType>::pop()
{
  error = isEmpty();
  if (!error)
  {
    --top;
    return pElems[top];
  }
  else
    return ElemType(0);
}

template<typename ElemType>
ElemType StackNoSize<ElemType>::peek() const
{
  error = isEmpty();
  if (!error)
    return pElems[top - 1];
  else
    return ElemType(0);
}
