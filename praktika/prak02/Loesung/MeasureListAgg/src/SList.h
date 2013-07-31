/*
 * SList.h
 *
 * Singly-linked list Template
 * The following operators must be defined for every type T
 * == << =
 *
 *  Created on: 24.02.2013
 *      Author: rbondere
 */

#ifndef SLIST_H_
#define SLIST_H_
template<class T>
class SList
{
  public:
    SList();
    virtual ~SList();
    void insertAt(int pos,
                  T val);
    // inserts element at (after) position pos (0: at head)
    void deleteAt(int pos);
    // deletes element at position pos (>0)
    int search(T val) const;
    // searches val in list and returns position of first match, starting
    // at head
    // returns 0 if value is not found
    bool isEmpty() const;
    // returns true if list is empty, else false
    int getNumber() const;
    // returns number of elements
    int getNext() const;
    // returns position of next element (0: no next, i.e. at end)
    int getPosition() const;
    // returns current position (0: list is empty)
    void setPosition(int pos);
    // sets current position to pos
    T getValue(int pos) const;
    // returns value at position pos
    void setValue(int pos,
                  T val);
    // sets value val at position pos
    void print() const;
    // prints content of list to console
  private:
    struct Node
    {
        T value;
        Node* next;
    };
    Node* pHead; // ptr to head of list
    int currPos; // current position
    int nr; // number of Elements

    Node* nodePtr(int pos) const
    // returns a pointer to the node given by position pos

    // Compiler note:
    // The definition must be here. g++ refuses to compile if the definition is
    // in SList.cpp
    // This is a compiler error

    {
      Node* p = pHead; // p points to element at pos 1, if not empty
      for (int i = 1; p && i < pos; i++)
      {
        p = p->next;
      }
      return p;
    }
};

// ugly include
#include "SList.cpp"

#endif /* SLIST_H_ */
