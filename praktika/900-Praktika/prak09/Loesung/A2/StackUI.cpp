/*
 * StackUI.cpp
 *
 *  Created on: 09.05.2012
 *      Author: rbondere
 */

#include <iostream>

// DO NOT #include "StackUI.h" !!
using namespace std;

template<typename ElemType, int size>
void StackUI<ElemType, size>::dialog()
{
  char ch = 0;
  ElemType e;
  do
  {
    cout << "\n\nOperation (Quit, pUsh, pOp, peeK, isEmpty) ";
    cin >> ch;
    switch (ch)
    {
      case 'q':
      case 'Q': // quit
        break;
      case 'u':
      case 'U': // push
        cout << "\nElement to push: ";
        cin >> e;
        s.push(e);
        if (s.wasError())
          cout << "\nError: Stack full.";
        break;
      case 'o':
      case 'O': // pop
        e = s.pop();
        if (s.wasError())
          cout << "\nError: Stack is empty (nothing to pop).";
        else
          cout << "\nPopped element " << e;
        break;
      case 'k':
      case 'K': // peek
        e = s.peek();
        if (s.wasError())
          cout << "\nError: Stack is empty (nothing to peek).";
        else
          cout << "\nPeeked element " << e;
        break;
      case 'e':
      case 'E': // isEmpty
        if (s.isEmpty())
          cout << "\nStack is empty.";
        else
          cout << "\nStack contains elements.";
        break;
      default:
        cout << "\nInvalid operation.";
        break;
    }
  } while (ch != 'Q' && ch != 'q');

}
