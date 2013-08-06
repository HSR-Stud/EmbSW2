#include <cstdio>
struct A
{
  char c;
  int i;
};

int main(void)
{
  A myA = {'A', 34};
  printf("%c\n%d\n", myA.c, myA.i);

  A* pA = &myA;
  printf("%c\n%d\n", pA->c, pA->i);
  return 0;
}

