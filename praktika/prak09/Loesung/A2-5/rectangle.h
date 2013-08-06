class Rectangle
{
  public:
    Rectangle(double newA=0, double newB=0) : a(newA), b(newB) {}
    inline double getA() const;
    inline void setA(double newA);
    double getArea() const;
    double getB() const; // not inline
  private:
    double a;
    double b;
};

// include inline definitions
#include "rectangle.icc"

