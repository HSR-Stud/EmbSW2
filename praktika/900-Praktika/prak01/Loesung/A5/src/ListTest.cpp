//======================================================
// Name        : ListTest.cpp
// Author      : Reto Bonderer
// Version     :
// Copyright   : (c) HSR R. Bonderer
// Description : List implementations
//=======================================================

#include <iostream>
#include "SList.h"
#include "DList.h"
using namespace std;

int main()
{
  SList<double> s;
  cout << "Singly linked list" << endl;
  s.print();

  s.insertAt(0, 1.23);
  s.insertAt(0, -34.6);
  s.insertAt(0, 0.4);
  s.print();

  s.insertAt(3, 7.97);
  s.insertAt(1, 88.9);
  s.print();

  s.deleteAt(2);
  s.print();
  cout << "-----------------------------" << endl;

  DList<int> d;
  cout << "Doubly linked list" << endl;
  d.print();

  d.insertAt(0, 123);
  d.insertAt(0, -346);
  d.insertAt(0, 78);
  d.print();

  d.insertAt(3, 797);
  d.insertAt(1, 88);
  d.print();

  d.deleteAt(5);
  d.insertAt(4, 45);
  d.print();

  return 0;
}
