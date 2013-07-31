// Filename: "src/appmain.cpp", 22.3.2012 ple

#include <iostream>

#include "Prime.h"

using namespace std;

int main()
{
  int nr;
  
	cout << "Prime Application Program:" << endl;
  cout << "Input a number: ";
  cin >> nr;
	cout << endl;

  bool prime = isPrime(nr);
  
  if (prime) 
    cout << nr << " is a prime number." << endl;
  else
    cout << nr << " is not a prime number." << endl;

	return 0;
}
