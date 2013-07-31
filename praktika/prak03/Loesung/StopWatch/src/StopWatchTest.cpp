//============================================================================
// Name        : StopWatchTest.cpp
// Author      : Reto Bonderer
// Version     :
// Copyright   : (c) HSR R. Bonderer
// Description : Test program for Stopwatch (Linux style)
//============================================================================

#include <iostream>
#include "StopWatch.h"
using namespace std;

int main()
{
  StopWatch w;

  for(long i=0; i<100000000; ++i)
  {}
  cout << w.elapsed() << endl;

  for(long i=0; i<100000000; ++i)
  {}
  cout << w.elapsed() << endl;



  return 0;
}
