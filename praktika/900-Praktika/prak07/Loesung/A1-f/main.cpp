//#include <iostream>
#include "rectangle.h"
#include "rectangleB.h"
//using namespace std;

int main(void)
{
  Rectangle r(2.0, 5.0);
  volatile double d;
  d = r.getA();
  double area = r.getArea();
//  cout << "area = " << area << endl;
  d = getRectangleB(r);
   
  return 0;
}

