class Rectangle
{
  public:
    Rectangle(double newA=0, double newB=0) : a(newA), b(newB) {}
    inline double getA() const;
    inline void setA(double newA);
    double getArea() const;
  private:
    double a;
    double b;
};

double Rectangle::getA() const
{
  return a;
}

inline void Rectangle::setA(double newA)
{
  a = newA;
}

inline double Rectangle::getArea() const
{ 
  return a*b;
}

