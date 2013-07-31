/*
 * SList.cpp
 *
 *  Created on: 19.02.2013
 *      Author: rbondere
 */

#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
SList<T>::SList() :
    List<T>(), pHead(0)
{
}

template <typename T>
SList<T>::~SList()
{
  for (Node* p = pHead; p; p = pHead)
  {
    pHead = pHead->next;
    delete p;
  }
}

template <typename T>
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
  ++List<T>::nr; // Compiler kennt nr nicht ohne Class-Qualifier
}

template <typename T>
void SList<T>::deleteAt(int pos)
{
  assert(pos > 0 && pos <= List<T>::nr);
  Node* p = pHead; // cursor
  Node* pDel = p; // node to be deleted
  if (pos == 1) // first element
    pHead = pHead->next;
  else
  {
    for (int i = 1; i < pos - 1; i++)
    {
      p = p->next;
    }
    pDel = p->next;
    p->next = pDel->next;
  }
  delete pDel;
  --List<T>::nr;
}

template <typename T>
int SList<T>::search(T val) const
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
T SList<T>::getValue(int pos) const
{
  assert(pos > 0 && pos <= List<T>::nr);
  return nodePtr(pos)->value;
}

template <typename T>
void SList<T>::setValue(int pos,
                    T val)
{
  assert(pos > 0 && pos <= List<T>::nr);
  nodePtr(pos)->value = val;
}

template <typename T>
void SList<T>::print() const
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
SList<T>::Node* SList<T>::nodePtr(int pos) const
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
