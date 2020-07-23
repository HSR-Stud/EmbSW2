/*
 * StackTest.cpp
 *
 *  Created on: 05.03.2020
 *      Author: rbondere
 */

#include <iostream>
#include <string>
#include "StackUI.h"
using namespace std;

int main()
{
  string theType = "";

  cout << "\n\nElementType (int, double, char): ";
  cin >> theType;
  if (theType == "int")
  {
    StackUI<int> sUI;
    sUI.dialog();
  }
  else if (theType == "double")
  {
    StackUI<double> sUI;
    sUI.dialog();
  }
  else if (theType == "char")
  {
    StackUI<char> sUI;
    sUI.dialog();
  }
  else
    cout << "Illegal input" << endl;

  cout << "Bye" << endl;

  return 0;
}
