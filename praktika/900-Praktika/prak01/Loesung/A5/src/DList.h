/*
 * DList.h
 * Double linked list for type T
 *
 *  Created on: 17.02.2020
 *      Author: rbondere
 */

#ifndef DLIST_H_
#define DLIST_H_

#include <cassert>
#include <iostream>

#include "List.h"

template<typename T>
class DList: public List<T>
{
  public:
    DList() :
      List<T>(), pHead(nullptr)
    {

    }
    virtual ~DList();

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
        Node* prev;
    };
    Node* pHead; // ptr to head of list
    Node* nodePtr(int pos) const;
    // returns a pointer to the node given by position pos
};

template<typename T>
DList<T>::~DList()
{
  for (Node* p = pHead; p; p = pHead)
  {
    pHead = pHead->next;
    delete p;
  }
}

template<typename T>
void DList<T>::insertAt(int pos, const T& val)
{
  assert(pos >= 0);
  Node* pEl = new Node;
  pEl->value = val;
  if (pos != 0)
  {
    Node* p = nodePtr(pos);
    assert(p != nullptr);
    pEl->next = p->next;
    pEl->prev = p;
    p->next = pEl;
  }
  else // insert at head
  {
    pEl->next = pHead;
    pEl->prev = nullptr;
    pHead = pEl;
  }
  if (pEl->next != nullptr) // not last element in list
    pEl->next->prev = pEl;
  List<T>::setNumber(List<T>::getNumber() + 1);
}

template<typename T>
void DList<T>::deleteAt(int pos)
{
  assert(pos > 0 && pos <= List<T>::getNumber());
  Node* pDel = nodePtr(pos); // node to be deleted
  assert(pDel != nullptr);
  if (pos == 1) // first element
    pHead = pHead->next;
  else
  {
    pDel->prev->next = pDel->next;
  }
  if (pDel->next != nullptr) // not last element in list
    pDel->next->prev = pDel->prev;
  delete pDel;
  List<T>::setNumber(List<T>::getNumber() - 1);
}

template<typename T>
int DList<T>::search(const T& val) const
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
const T& DList<T>::getValue(int pos) const
{
  assert(pos > 0 && pos <= List<T>::getNumber());
  return nodePtr(pos)->value;
}

template<typename T>
void DList<T>::setValue(int pos, const T& val)
{
  assert(pos > 0 && pos <= List<T>::getNumber());
  nodePtr(pos)->value = val;
}

template<typename T>
void DList<T>::print() const
{
  std::cout << "-------------------" << std::endl;
  std::cout << "Number of elements: " << List<T>::getNumber() << std::endl;
  std::cout << "Content of list:" << std::endl;
  for (Node* p = pHead; p; p = p->next)
    std::cout << p->value << " ";
  std::cout << std::endl;
}

template <typename T>
typename DList<T>::Node* DList<T>::nodePtr(int pos) const
{
  assert(pos > 0 && pos <= List<T>::getNumber());
  Node* p = pHead; // p points to element at pos 1, if not empty
  for (int i = 1; p && i < pos; ++i)
  {
    p = p->next;
  }
  return p;
}

#endif /* DLIST_H_ */
