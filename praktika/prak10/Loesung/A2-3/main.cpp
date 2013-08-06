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

  A& rA = myA;
  rA.i = 56;
  printf("%p\n%d\n",&rA, rA.i);
  return 0;
}

