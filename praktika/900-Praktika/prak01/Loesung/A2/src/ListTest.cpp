//=====================================================
// Name        : ListTest.cpp
// Author      : Reto Bonderer
// Version     :
// Copyright   : (c) HSR R. Bonderer
// Description : List implementations
//=====================================================

#include <iostream>
#include "SList.h"
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

  return 0;
}
