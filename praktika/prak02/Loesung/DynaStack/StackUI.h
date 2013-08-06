/*
 * StackUI.h
 *
 * User Interface for Stack application
 * Created on: 18.05.2009
 *      Author: rbondere
 */

#ifndef STACKUI_H_
#define STACKUI_H_
#include "stack.h"

template<typename ElemType>
class StackUI
{
  public:
    StackUI();
    virtual ~StackUI();
    void dialog();
    // starts the user dialog
  private:
    Stack<ElemType> s;
};

// ugly include
#include "StackUI.cpp"

#endif /* STACKUI_H_ */
