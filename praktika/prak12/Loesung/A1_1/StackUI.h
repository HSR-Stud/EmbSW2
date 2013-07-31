/*
 * StackUI.h
 *
 * User Interface for Stack application
 * Created on: 09.05.2012
 *      Author: rbondere
 */

#ifndef STACKUI_H_
#define STACKUI_H_
#include "stack.h"

template<typename ElemType, int size = 10>
class StackUI
{
  public:
    void dialog();
    // starts the user dialog
  private:
    Stack<ElemType, size> s;
};

// ugly include
#include "StackUI.cpp"

#endif /* STACKUI_H_ */
