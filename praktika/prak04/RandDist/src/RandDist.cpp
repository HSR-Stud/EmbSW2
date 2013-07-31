//============================================================================
// Name        : RandDist.cpp
// Author      : Reto Bonderer
// Version     :
// Copyright   : (c) HSR R. Bonderer
// Description : Uniform distribution
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  enum
  {
    minValue = 1, // minimal value for random numbers
    maxValue = 20, // maximal value for random numbers
    iterations = 20000
  // number of iterations
  };
  int histogram[maxValue - minValue + 1] = {0};
  int r;
  srand(time(0));
  for (int i = 0; i < iterations; ++i)
  {
    // r = rand() % (maxValue - minValue + 1) + minValue;
    // Modulo-Variante berücksichtigt nur LSBs. Kann zu schlechten (kaum
    // zufälligen) Folgen führen

    r = (int)((double)rand() / (RAND_MAX + 1.0) * (maxValue - minValue + 1)) + minValue;
    // '+ 1' ist notwendig, weil nach int konvertiert wird.
    // Vor Konversion gibt es dadurch bei [1,20] Zahlen im Bereich [0.0,20.0[
    // Nach Konversion werden nur die ganzzahligen Anteile verwendet
    // Das hinterste "+ minValue" muss ausserhalb des Typecasts sein,
    // andernfalls ergibt es ein Überhöhung bei 0, falls minValue < 0
    cout << setw(2) << r << " | ";
    ++histogram[r - minValue];
    for (int i = 0; i < maxValue - minValue + 1; i++)
      cout << histogram[i] << " ";
    cout << endl;
  }

  cout << "Soll: je " << iterations / (maxValue - minValue + 1) << endl;
  return 0;
}
