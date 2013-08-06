/*
 * stackNoSize.h
 *
 *  Created on: 09.05.2012
 *      Author: rbondere
 */

#ifndef STACKNOSIZE_H_
#define STACKNOSIZE_H_

template<typename ElemType>
class StackNoSize
{
  public:
    StackNoSize(ElemType* pArr = 0);
    // Default-Konstruktor

    ElemType pop();
    // nimmt ein Element vom Stack, falls der Stack nicht leer ist
    // wasError() gibt Auskunft, ob pop() erfolgreich war

    ElemType peek() const;
    // liest das oberste Element vom Stack, falls der Stack nicht leer ist
    // wasError() gibt Auskunft, ob peek() erfolgreich war

    bool isEmpty() const {return top == 0;}
    // return: true: Stack ist leer
    //         false: sonst

    bool wasError() const {return error;}
    // return: true: Operation war fehlerhaft
    //         false: sonst

  protected:
    int top;              // Arrayindex des naechsten freien Elements
    mutable bool error;   // true: Fehler passiert; false: sonst
    // mutable: auch const-Methoden können dieses Attribut setzen
    
  private:
    ElemType* pElems;     // Pointer auf Array in Unterklasse (nicht ganz sauber)
};

// ugly include
#include "stackNoSize.cpp"
#endif // STACKNOSIZE_H_
