/*
 * Stack.h
 *
 *  Created on: 24.04.2015
 *      Author: rbondere
 */

#ifndef STACK_H_
#define STACK_H_
#include "StackNoSize.h"

template<typename ElemType, int size = 10>
class Stack: public StackNoSize<ElemType>
{
  public:
    Stack();
    // Default-Konstruktor

    void push(const ElemType& e);
    // legt ein Element auf den Stack, falls der Stack noch nicht voll ist
    // wasError() gibt Auskunft, ob push() erfolgreich war

    bool isFull() const;
    // return: true: Stack ist voll
    //         false: sonst

  private:
    ElemType elems[size]; // Speicher fuer Speicherung des Stacks
};

// ugly include
#include "Stack.cpp"
#endif // STACK_H_
