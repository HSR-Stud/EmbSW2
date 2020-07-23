#include <cstdio>

class A
{
  public:
    virtual void foo1() {printf("A::foo1()\n");}
    virtual void foo2() {printf("A::foo2()\n");}
    void foo3() {printf("A::foo3()\n");}
};

class B : public A
{
  public:
    virtual void foo1() {printf("B::foo1()\n");}
    virtual void foo4() {printf("B::foo4()\n");}
};


int main(void)
{
  A a;
  B b;
  a.foo1();
  a.foo2();
  a.foo3();
  
  b.foo1();
  b.foo2();
  b.foo3();
  b.foo4();
  
  return 0;
}

