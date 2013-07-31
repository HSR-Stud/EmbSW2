/*
 * stack.h
 *
 *  Created on: 09.05.2012
 *      Author: rbondere
 */

#ifndef STACK_H_
#define STACK_H_
#include "stackNoSize.h"

template<typename ElemType, int size = 10>
class Stack: public StackNoSize<ElemType>
{
  public:
    Stack();
    // Default-Konstruktor

    void push(ElemType e);
    // legt ein Element auf den Stack, falls der Stack noch nicht voll ist
    // wasError() gibt Auskunft, ob push() erfolgreich war

    bool isFull() const;
    // return: true: Stack ist voll
    //         false: sonst

  private:
    ElemType elems[size]; // Speicher für Speicherung des Stacks
};

// ugly include
#include "stack.cpp"
#endif // STACK_H_
