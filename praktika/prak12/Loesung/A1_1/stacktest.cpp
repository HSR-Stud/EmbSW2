/*
 * StackTest.cpp
 *
 *  Created on: 09.05.2012
 *      Author: rbondere
 */

#include "stackUI.h"
using namespace std;

enum
{
  stackSize = 3
};

int main(void)
{
  StackUI<int, stackSize> sUI;
  sUI.dialog();
  StackUI<int, 4> sUI4;
  sUI4.dialog();

  return 0;
}
