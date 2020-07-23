/*
 * SList.cpp
 *
 *  Created on: 17.02.2020
 *      Author: rbondere
 */

#include <cassert>
#include <iostream>
#include "SList.h"
using namespace std;

SList::SList() :
    List(), pHead(nullptr)
{
}

SList::~SList()
{
  for (Node* p = pHead; p; p = pHead)
  {
    pHead = pHead->next;
    delete p;
  }
}

void SList::insertAt(int pos, double val)
{
  assert(pos >= 0);
  Node* pEl = new Node;
  pEl->value = val;
  if (pos != 0)
  {
    Node* p = nodePtr(pos);
    assert(p != nullptr);
    pEl->next = p->next;
    p->next = pEl;
  }
  else // insert at head
  {
    pEl->next = pHead;
    pHead = pEl;
  }
  setNumber(getNumber() + 1);
}

void SList::deleteAt(int pos)
{
  assert(pos > 0 && pos <= getNumber());
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
  setNumber(getNumber() - 1);
}

int SList::search(double val) const
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

double SList::getValue(int pos) const
{
  assert(pos > 0 && pos <= getNumber());
  return nodePtr(pos)->value;
}

void SList::setValue(int pos, double val)
{
  assert(pos > 0 && pos <= getNumber());
  nodePtr(pos)->value = val;
}

void SList::print() const
{
  cout << "-------------------" << endl;
  cout << "Number of elements: " << getNumber() << endl;
  cout << "Content of list:" << endl;
  for (Node* p = pHead; p; p = p->next)
    cout << p->value << " ";
  cout << endl;
}

SList::Node* SList::nodePtr(int pos) const
{
  assert(pos > 0 && pos <= getNumber());
  Node* p = pHead; // p points to element at pos 1, if not empty
  for (int i = 1; p && i < pos; ++i)
  {
    p = p->next;
  }
  return p;
}
