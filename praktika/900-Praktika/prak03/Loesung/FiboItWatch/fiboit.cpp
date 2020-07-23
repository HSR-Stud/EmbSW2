// Datei: fiboit.cpp
// berechnet die Fibonacci-Zahl iterativ
// R. Bonderer, 04.03.2013

#include <iostream>
#include <iomanip>
#include <sys/resource.h>
#include <sys/types.h>
using namespace std;
 
unsigned long fibonacci(unsigned int n);

  
int main(void)
{
  unsigned int zahl;  
  unsigned long fibo;
  rusage tp;
  double start;   // Startzeit in Sekunden, Aufloesung in Mikrosekunden
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

  cout <<"Fibonacci(" << zahl << ")= " << fibo << endl;
  cout << fixed << setprecision(3) << "Dauer: " << end-start << " sec" << endl;
  return 0;
}

unsigned long fibonacci(unsigned int n)
{
  unsigned long fibMin1 = 1;
  unsigned long fibMin2 = 1;
  unsigned long fib = 1;
  
  if (n == 1 || n == 2)
    return fib;

  for (unsigned int i = 3; i <= n; ++i)
  {
    fib = fibMin2 + fibMin1;
    fibMin2 = fibMin1;
    fibMin1 = fib;
  }
  return fib;
}  
