// Datei: fiborek.cpp
// berechnet die Fibonacci-Zahl rekursiv
// misst Zeit mit Linux CPU Zeitfunktionen
// R. Bonderer, 04.03.2013

#include <iostream>
#include <iomanip>
#include <sys/resource.h>
#include <sys/types.h>

using namespace std;

// Funktionsprototypen
unsigned long fibonacci(unsigned int n);
// berechnet die Fibonacci-Zahl von n rekursiv
// return: Fibonacci-Zahl
  
int main(void)
{
  unsigned int zahl;
  unsigned long fibo;
  rusage tp;
  double start;   // Startzeit in Millisekunden
  double end;     // Endzeit
  
  cout << "n eingeben: ";
  cin >> zahl;

  getrusage(RUSAGE_SELF, &tp);
  start = static_cast<double>(tp.ru_utime.tv_sec) +
          static_cast<double>(tp.ru_utime.tv_usec)/1E6;

  fibo = fibonacci(zahl);

  getrusage(RUSAGE_SELF, &tp);
  end = static_cast<double>(tp.ru_utime.tv_sec) +
        static_cast<double>(tp.ru_utime.tv_usec)/1E6;

  cout << "Fibonacci(" << zahl << ") = " << fibo << endl;
  cout << fixed << setprecision(3) << "Dauer: " << end-start << " sec" << endl;
  return 0;
}

unsigned long fibonacci(unsigned int n)
{
  if (n == 1 || n == 2)
    return 1UL;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}  
