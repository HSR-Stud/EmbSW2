//============================================================================
// Name        : MListMain.cpp
// Author      : Reto Bonderer
// Version     :
// Copyright   : (c) HSR R. Bonderer
// Description : Measurement list main program
//============================================================================

#include <iostream>
#include "MeasureList.h"
using namespace std;

int main()
{
  MeasureList m;
  m.setTolerance(5);
  m.insertValue(9);
  m.insertValue(10);
  m.insertValue(11);
  m.print();
  cout << "Mean = " << m.getMean() << endl;
  m.exclude();
  m.print();
  m.exclude();
  m.print();
  m.insertValue(10.44);
  m.exclude();
  m.print();
  return 0;
}
