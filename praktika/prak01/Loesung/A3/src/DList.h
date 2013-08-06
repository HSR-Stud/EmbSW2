/*
 * DList.h
 * Double linked list for doubles
 *
 *  Created on: 19.02.2013
 *      Author: rbondere
 */

#ifndef DLIST_H_
#define DLIST_H_
#include "List.h"

class DList: public List
{
  public:
    DList();
    virtual ~DList();

    virtual void insertAt(int pos,
                          double val);
    // inserts element at (after) position pos (0: at head)

    virtual void deleteAt(int pos);
    // deletes element at position pos (>0)

    virtual int search(double val) const;
    // searches val in list and returns position of first match, starting
    // at head
    // returns 0 if value is not found

    int getPrev() const;
    // returns position of previous element (0: no previous, i.e. at head)

    virtual double getValue(int pos) const;
    // returns value at position pos

    virtual void setValue(int pos,
                          double val);
    // sets value val at position pos

    virtual void print() const;
    // prints content of list to console

  private:
    struct Node
    {
        double value;
        Node* next;
        Node* prev;
    };
    Node* pHead; // ptr to head of list

    Node* nodePtr(int pos) const;
    // returns a pointer to the node given by position pos
};

#endif /* DLIST_H_ */
