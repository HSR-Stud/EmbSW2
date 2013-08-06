/*
 * stack.h
 *
 *  Created on: 05.03.2011
 *      Author: rbondere
 *  Stack, der dynamisch erweitert wird
 */

#ifndef STACK_H_
#define STACK_H_

#include "slist.h"

template<typename ElemType>
class Stack
{
  public:
    Stack();
    // Default-Konstruktor

    ~Stack();
    // Destruktor

    void push(ElemType e);
    // legt ein Element auf den Stack. Falls der Stack voll ist, wird er
    // dynamisch erweitert
    // wasError() gibt Auskunft, ob push() erfolgreich war

    ElemType pop();
    // nimmt ein Element vom Stack, falls der Stack nicht leer ist
    // wasError() gibt Auskunft, ob pop() erfolgreich war

    ElemType peek() const;
    // liest das oberste Element vom Stack, falls der Stack nicht leer ist
    // wasError() gibt Auskunft, ob peek() erfolgreich war

    bool isEmpty() const;
    // return: true: Stack ist leer
    //         false: sonst

    int getDepth() const;
    // return: Stacktiefe: Anzahl gueltige Elemente im Stack

    bool wasError() const;
    // return: true: Operation war fehlerhaft
    //         false: sonst

  private:
    SList<ElemType> list; // Dynamischer Speicher für Stack
    mutable bool error;   // true: Fehler passiert; false: sonst
    // mutable: auch const-Methoden können dieses Attribut setzen
};

// ugly include
#include "stack.cpp"
#endif // STACK_H_
