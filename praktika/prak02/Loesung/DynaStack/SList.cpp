/*
 * SList.cpp
 *
 *  Created on: 24.02.2013
 *      Author: rbondere
 */

#include <cassert>
using namespace std;

template<class T>
SList<T>::SList() :
  pHead(0), currPos(0), nr(0)
{
}

template<class T>
SList<T>::~SList()
{
  for (Node* p = pHead; p; p = pHead)
  {
    pHead = pHead->next;
    delete p;
  }
}

template<class T>
void SList<T>::insertAt(int pos,
                        T val)
{
  assert(pos >= 0);
  Node* pEl = new Node;
  pEl->value = val;
  if (pos != 0)
  {
    Node* p = nodePtr(pos);
    assert(p != 0);
    pEl->next = p->next;
    p->next = pEl;
  }
  else // insert at head
  {
    pEl->next = pHead;
    pHead = pEl;
  }
  ++nr;
}

template<class T>
void SList<T>::deleteAt(int pos)
{
  assert(pos > 0 && pos <= nr);
  Node* p = pHead; // cursor
  Node* pDel = p; // node to be deleted
  if (pos == 1) // first element
    pHead = pHead->next;
  else
  {
    for (int i = 1; i < pos - 1; ++i)
    {
      p = p->next;
    }
    pDel = p->next;
    p->next = pDel->next;
  }
  delete pDel;
  --nr;
}

template<class T>
int SList<T>::search(T val) const
{
  Node* p = pHead; // p points to element at pos 1, if not empty
  for (int i = 1; p; ++i)
  {
    if (p->value == val)
      return i;
    p = p->next;
  }
  return 0; // not found
}

template<class T>
bool SList<T>::isEmpty() const
{
  return nr == 0;
}

template<class T>
int SList<T>::getNumber() const
{
  return nr;
}

template<class T>
int SList<T>::getNext() const
{
  if (currPos >= nr)
    return 0;
  else
    return currPos + 1;
}

template<class T>
void SList<T>::setPosition(int pos)
{
  assert(pos >= 0 && pos <= nr);
  currPos = pos;
}

template<class T>
int SList<T>::getPosition() const
{
  return currPos;
}

template<class T>
T SList<T>::getValue(int pos) const
{
  assert(pos > 0 && pos <= nr);
  return nodePtr(pos)->value;
}

template<class T>
void SList<T>::setValue(int pos,
                        T val)
{
  assert(pos > 0 && pos <= nr);
  nodePtr(pos)->value = val;
}
