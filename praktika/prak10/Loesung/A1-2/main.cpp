#include <cstdio>
int main(void)
{
  int number = 34;
  int* pi = &number;
  printf("%p\n", pi);
  return 0;
}
