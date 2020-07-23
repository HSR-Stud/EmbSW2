/*
 * SList.h
 *
 * Singly-linked list for type T
 *
 *  Created on: 17.02.2020
 *      Author: rbondere
 */

#ifndef SLIST_H_
#define SLIST_H_

#include <iostream>
#include <cassert>

#include "List.h"

template<typename T>
class SList: public List<T>
{
  public:
    SList() :
      List<T>(), pHead(nullptr)
    {

    }

    virtual ~SList();

    virtual void insertAt(int pos, const T& val);
    // inserts element at (after) position pos (0: at head)

    virtual void deleteAt(int pos);
    // deletes element at position pos (>0)

    virtual int search(const T& val) const;
    // searches val in list and returns position of first match, starting
    // at head
    // returns 0 if value is not found

    virtual const T& getValue(int pos) const;
    // returns value at position pos

    virtual void setValue(int pos, const T& val);
    // sets value val at position pos

    virtual void print() const;
    // prints content of list to console

  private:
    struct Node
    {
        T value;
        Node* next;
    };
    Node* pHead; // ptr to head of list
    Node* nodePtr(int pos) const;
    // returns a pointer to the node given by position pos
};

template<typename T>
SList<T>::~SList()
{
  for (Node* p = pHead; p; p = pHead)
  {
    pHead = pHead->next;
    delete p;
  }
}

template<typename T>
void SList<T>::insertAt(int pos, const T& val)
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
  List<T>::setNumber(List<T>::getNumber() + 1);
}

template<typename T>
void SList<T>::deleteAt(int pos)
{
  assert(pos > 0 && pos <= List<T>::getNumber());
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
  List<T>::setNumber(List<T>::getNumber() - 1);
}

template<typename T>
int SList<T>::search(const T& val) const
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

template<typename T>
const T& SList<T>::getValue(int pos) const
{
  assert(pos > 0 && pos <= List<T>::getNumber());
  return nodePtr(pos)->value;
}

template<typename T>
void SList<T>::setValue(int pos, const T& val)
{
  assert(pos > 0 && pos <= List<T>::getNumber());
  nodePtr(pos)->value = val;
}

template<typename T>
void SList<T>::print() const
{
  std::cout << "-------------------" << std::endl;
  std::cout << "Number of elements: " << List<T>::getNumber() << std::endl;
  std::cout << "Content of list:" << std::endl;
  for (Node* p = pHead; p; p = p->next)
    std::cout << p->value << " ";
  std::cout << std::endl;
}

template <typename T>
typename SList<T>::Node* SList<T>::nodePtr(int pos) const
{
  assert(pos > 0 && pos <= List<T>::getNumber());
  Node* p = pHead; // p points to element at pos 1, if not empty
  for (int i = 1; p && i < pos; ++i)
  {
    p = p->next;
  }
  return p;
}

#endif /* SLIST_H_ */
