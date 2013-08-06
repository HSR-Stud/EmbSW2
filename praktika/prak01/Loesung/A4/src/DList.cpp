/*
 * DList.cpp
 *
 *  Created on: 20.02.2013
 *      Author: rbondere
 */

#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
DList<T>::DList() :
    List<T>(), pHead(0)
{
}

template <typename T>
DList<T>::~DList()
{
  for (Node* p = pHead; p; p = pHead)
  {
    pHead = pHead->next;
    delete p;
  }
}

template <typename T>
void DList<T>::insertAt(int pos,
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
    pEl->prev = p;
    p->next = pEl;
  }
  else // insert at head
  {
    pEl->next = pHead;
    pEl->prev = 0;
    pHead = pEl;
  }
  if (pEl->next != 0) // not last element in list
    pEl->next->prev = pEl;
  ++List<T>::nr;
}

template <typename T>
void DList<T>::deleteAt(int pos)
{
  assert(pos > 0 && pos <= List<T>::nr);
  Node* pDel = nodePtr(pos); // node to be deleted
  assert(pDel != 0);
  if (pos == 1) // first element
    pHead = pHead->next;
  else
  {
    pDel->prev->next = pDel->next;
  }
  if (pDel->next != 0) // not last element in list
    pDel->next->prev = pDel->prev;
  delete pDel;
  --List<T>::nr;
}

template <typename T>
int DList<T>::search(T val) const
{
  Node* p = pHead; // p points to element at pos 1, if not empty
  for (int i = 1; p; i++)
  {
    if (p->value == val)
      return i;
    p = p->next;
  }
  return 0; // not found
}

template <typename T>
int DList<T>::getPrev() const
{
  if (List<T>::currPos <= 0)
    return 0;
  else
    return List<T>::currPos - 1;
}

template <typename T>
T DList<T>::getValue(int pos) const
{
  assert(pos > 0 && pos <= List<T>::nr);
  return nodePtr(pos)->value;
}

template <typename T>
void DList<T>::setValue(int pos,
                    T val)
{
  assert(pos > 0 && pos <= List<T>::nr);
  nodePtr(pos)->value = val;
}

template <typename T>
void DList<T>::print() const
{
  cout << "-------------------" << endl;
  cout << "Number of elements: " << List<T>::nr << endl;
  cout << "Content of list:" << endl;
  for (Node* p = pHead; p; p = p->next)
    cout << p->value << " ";
  cout << endl;
}
#if 0
template <typename T>
DList<T>::Node* DList<T>::nodePtr(int pos) const
{
  assert(pos > 0 && pos <= List<T>::nr);
  Node* p = pHead; // p points to element at pos 1, if not empty
  for (int i = 1; p && i < pos; i++)
  {
    p = p->next;
  }
  return p;
}
#endif
