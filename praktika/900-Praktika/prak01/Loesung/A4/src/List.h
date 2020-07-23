/*
 * List.h
 *
 *  Created on: 15.02.2016
 *      Author: rbondere
 */

#ifndef LIST_H_
#define LIST_H_

class List
{
  public:
    List() :
        nr(0)
    {
    }

    virtual ~List()
    {
    }

    virtual void insertAt(int pos, double val) = 0;
    // inserts element at (after) position pos (0: at head)

    virtual void deleteAt(int pos) = 0;
    // deletes element at position pos (>0)

    virtual int search(double val) const = 0;
    // searches val in list and returns position of first match, starting
    // at head
    // returns 0 if value is not found

    int getNumber() const
    // returns number of elements
    {
      return nr;
    }

    bool isEmpty() const
    // returns true if list is empty, else false
    {
      return nr == 0;
    }

    virtual double getValue(int pos) const = 0;
    // returns value at position pos

    virtual void setValue(int pos, double val) = 0;
    // sets value val at position pos

    virtual void print() const = 0;
    // prints content of list to console

  protected:
    void setNumber(int nr)
    // sets number of elements
    {
      this->nr = nr;
    }

  private:
    int nr; // number of Elements
};

#endif /* LIST_H_ */
