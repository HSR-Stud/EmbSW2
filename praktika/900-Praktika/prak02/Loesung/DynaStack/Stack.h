/*
 * stack.h
 *
 *  Created on: 24.02.2017
 *      Author: rbondere
 *  Stack, der dynamisch erweitert wird
 */

#ifndef STACK_H_
#define STACK_H_

#include "SList.h"

template<typename ElemType>
class Stack
{
  public:
    Stack() : error(false)
    // Default-Konstruktor
    {
    }
    void push(const ElemType& e);
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

    bool wasError() const
    // return: true: Operation war fehlerhaft
    //         false: sonst
    {
      return error;
    }
  private:
    SList<ElemType> list; // Dynamischer Speicher fuer Stack
    mutable bool error;   // true: Fehler passiert; false: sonst
    // mutable: auch const-Methoden koennen dieses Attribut setzen
};

// template implementation

template<typename ElemType>
void Stack<ElemType>::push(const ElemType& e)
{
  error = false;
  list.insertAt(0, e); // insert at head
}

template<typename ElemType>
ElemType Stack<ElemType>::pop()
{
  error = list.isEmpty();
  if (!error)
  {
    ElemType e = list.getValue(1); // pos == 1: element at head
    list.deleteAt(1);
    return e;
  }
  else
    return 0;
}

template<typename ElemType>
ElemType Stack<ElemType>::peek() const
{
  error = list.isEmpty();
  if (!error)
  {
    return list.getValue(1); // pos == 1: element at head
  }
  else
    return 0;
}

template<typename ElemType>
bool Stack<ElemType>::isEmpty() const
{
  return list.isEmpty();
}

template<typename ElemType>
int Stack<ElemType>::getDepth() const
{
  return list.getNumber();
}

#endif // STACK_H_
