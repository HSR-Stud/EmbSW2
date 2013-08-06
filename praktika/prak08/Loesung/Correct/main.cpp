/*
 * main.cpp
 *
 *  Created on: 12.04.2012
 *      Author: rbondere
 */

#include <iostream>
#include <iomanip>
using namespace std;

bool isPrime(int cand);


int main()
{
  cout << "Testfaelle:" << boolalpha << endl;

  cout << setw(5) << "#" << setw(8) << "cand" << setw(15) << "Erwartet" << setw(15) <<"Effektiv" << endl;
  cout << setw(5) << "1" << setw(8) << 1 << setw(15) << false << setw(15) << isPrime(1) << endl;
  cout << setw(5) << "2" << setw(8) << 2 << setw(15) << true << setw(15) << isPrime(2) << endl;
  cout << setw(5) << "3" << setw(8) << 4 << setw(15) << false << setw(15) << isPrime(4) << endl;
  cout << setw(5) << "4" << setw(8) << 31 << setw(15) << true << setw(15) << isPrime(31) << endl;
  cout << setw(5) << "5" << setw(8) << 15 << setw(15) << false << setw(15) << isPrime(15) << endl;

  return 0;
}

bool isPrime(int cand)
{
  int b = 2;
  bool p = true;
  if (cand < 2)
    return false;
  while (p && (b * b <= cand))
  {
    if (cand % b == 0)
      p = false;
    b++;
  }
  return p;
}
