/*
 * DList.h
 * Doubly linked list for doubles
 *
 *  Created on: 12.02.2016
 *      Author: rbondere
 */

#ifndef DLIST_H_
#define DLIST_H_

class DList
{
  public:
    DList();
    ~DList();

    void insertAt(int pos, double val);
    // inserts element at (after) position pos (0: at head)

    void deleteAt(int pos);
    // deletes element at position pos (>0)

    int search(double val) const;
    // searches val in list and returns position of first match, starting
    // at head
    // returns 0 if value is not found

    bool isEmpty() const;
    // returns true if list is empty, else false

    int getNumber() const;
    // returns number of elements

    double getValue(int pos) const;
    // returns value at position pos

    void setValue(int pos, double val);
    // sets value val at position pos

    void print() const;
    // prints content of list to console

  private:
    struct Node
    {
        double value;
        Node* next;
        Node* prev;
    };
    Node* pHead;  // ptr to head of list
    int nr;       // number of Elements

    Node* nodePtr(int pos) const;
    // returns a pointer to the node given by position pos
};

#endif /* DLIST_H_ */
