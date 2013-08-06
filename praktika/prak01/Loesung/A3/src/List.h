/*
 * List.h
 *
 *  Created on: 19.02.2013
 *      Author: rbondere
 */

#ifndef LIST_H_
#define LIST_H_

class List
{
  public:
    List();
    virtual ~List();

    virtual void insertAt(int pos,
                          double val) = 0;
    // inserts element at (after) position pos (0: at head)

    virtual void deleteAt(int pos) = 0;
    // deletes element at position pos (>0)

    virtual int search(double val) const = 0;
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

    virtual double getValue(int pos) const = 0;
    // returns value at position pos

    virtual void setValue(int pos,
                          double val) = 0;
    // sets value val at position pos

    virtual void print() const = 0;
    // prints content of list to console

  protected: // :-( attributes should rather be private than protected
    int currPos; // current position
    int nr; // number of Elements
};

#endif /* LIST_H_ */
