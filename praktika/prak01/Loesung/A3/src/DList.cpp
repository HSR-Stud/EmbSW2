/*
 * DList.cpp
 *
 *  Created on: 25.02.2011
 *      Author: rbondere
 */

#include <cassert>
#include <iostream>
#include "DList.h"
using namespace std;

DList::DList() :
    List(), pHead(0)
{
}

DList::~DList()
{
  for (Node* p = pHead; p; p = pHead)
  {
    pHead = pHead->next;
    delete p;
  }
}

void DList::insertAt(int pos,
                     double val)
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
  ++nr;
}

void DList::deleteAt(int pos)
{
  assert(pos > 0 && pos <= nr);
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
  --nr;
}

int DList::search(double val) const
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

int DList::getPrev() const
{
  if (currPos <= 0)
    return 0;
  else
    return currPos - 1;
}

double DList::getValue(int pos) const
{
  assert(pos > 0 && pos <= nr);
  return nodePtr(pos)->value;
}

void DList::setValue(int pos,
                    double val)
{
  assert(pos > 0 && pos <= nr);
  nodePtr(pos)->value = val;
}

void DList::print() const
{
  cout << "-------------------" << endl;
  cout << "Number of elements: " << nr << endl;
  cout << "Content of list:" << endl;
  for (Node* p = pHead; p; p = p->next)
    cout << p->value << " ";
  cout << endl;
}

DList::Node* DList::nodePtr(int pos) const
{
  assert(pos > 0 && pos <= nr);
  Node* p = pHead; // p points to element at pos 1, if not empty
  for (int i = 1; p && i < pos; i++)
  {
    p = p->next;
  }
  return p;
}
