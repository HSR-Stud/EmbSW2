//============================================================================
// Name        : QuickSortFast.cpp
// Author      : Reto Bonderer
// Version     :
// Copyright   : (c) HSR R. Bonderer
// Description : Fast Quicksort
//============================================================================

#include <iostream>
#include "StopWatch.h"
#include "List.h"
using namespace std;

int main()
{
  int nr = 5000000;
  int threshold;
  /*
   cout << "Anzahl Listenelemente: ";
   cin >> nr;
   */
  cout << "Schwelle fuer Umschaltung nach Insertionsort: ";
  cin >> threshold;

  List myList(nr, threshold);
  myList.randomFill();

  StopWatch t;
  myList.quickSort(0, nr - 1);
  cout << "Unsortierte Liste sortiert in " << t.elapsed() << " sec" << endl;

  StopWatch t1;
  myList.quickSort(0, nr - 1);
  cout << "Sortierte Liste sortiert in   " << t1.elapsed() << " sec" << endl;

//  for (threshold = 0; threshold <= 500; threshold++)
//  {
//    List myList(nr, threshold);
//    myList.randomFill();
//
//    StopWatch t;
//    myList.quickSort(0, nr - 1);
//    cout << threshold <<" " << t.elapsed();
//
//    StopWatch t1;
//    myList.quickSort(0, nr - 1); // already sorted
//    cout << " " << t1.elapsed() << endl;
//  }


  cout << "Fertig" << endl;
  return 0;
}
