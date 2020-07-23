#include <iostream>

#include "rectangle.h"
using namespace std;

int main(void)
{
  double a;
  double b;
  cout << "a und b eingeben: ";
  cin >> a >> b;
  Rectangle r(a, b);
  volatile double d;
  d = r.getA();
  volatile double area = r.getArea();
  cout << "area = " << area << endl;
    
  return 0;
}

