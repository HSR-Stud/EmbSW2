/*
 * stack.h
 *
 *  Created on: 09.05.2012
 *      Author: rbondere
 */

#ifndef STACK_H_
#define STACK_H_

template<typename ElemType, int size = 10>
class Stack
{
  public:
    Stack();
    // Default-Konstruktor

    void push(ElemType e);
    // legt ein Element auf den Stack, falls der Stack noch nicht voll ist
    // wasError() gibt Auskunft, ob push() erfolgreich war

    ElemType pop();
    // nimmt ein Element vom Stack, falls der Stack nicht leer ist
    // wasError() gibt Auskunft, ob pop() erfolgreich war

    ElemType peek() const;
    // liest das oberste Element vom Stack, falls der Stack nicht leer ist
    // wasError() gibt Auskunft, ob peek() erfolgreich war

    bool isEmpty() const {return top == 0;}
    // return: true: Stack ist leer
    //         false: sonst

    bool isFull() const;
    // return: true: Stack ist voll
    //         false: sonst

    bool wasError() const {return error;}
    // return: true: Operation war fehlerhaft
    //         false: sonst

  private:
    ElemType elems[size]; // Speicher für Speicherung des Stacks
    int top;              // Arrayindex des naechsten freien Elements
    mutable bool error;   // true: Fehler passiert; false: sonst
    // mutable: auch const-Methoden können dieses Attribut setzen
};

// ugly include
#include "stack.cpp"
#endif // STACK_H_
