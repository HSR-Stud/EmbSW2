// Datei: fiborek.cpp
// berechnet die Fibonacci-Zahl rekursiv
// R. Bonderer, 04.03.2013

#include <iostream>
#include <ctime>

using namespace std;

// Funktionsprototypen
unsigned long fibonacci(unsigned int n);
// berechnet die Fibonacci-Zahl von n rekursiv
// return: Fibonacci-Zahl
  
int main(void)
{
  unsigned int zahl;
  unsigned long fibo;
  
  cout << "n eingeben: ";
  cin >> zahl;

  clock_t start = clock();
  fibo = fibonacci(zahl);
  clock_t end = clock();

  cout << "Fibonacci(" << zahl << ") = " << fibo << endl;
  cout << "Start: " << start << endl;
  cout << "End  : " << end << endl;
  cout << "Dauer: " << end-start << " Ticks" << endl;
  cout << "Dauer: " << static_cast<double>(end-start) / CLOCKS_PER_SEC
       << " sec" << endl;
  return 0;
}

unsigned long fibonacci(unsigned int n)
{
  if (n == 1 || n == 2)
    return 1UL;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}  
