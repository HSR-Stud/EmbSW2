class Rectangle
{
  public:
    Rectangle(double newA=0, double newB=0) : a(newA), b(newB) {}
    double getA() const {return a;}
    void setA(double newA) {a = newA;}
    double getArea() const;
  private:
    double a;
    double b;
};

