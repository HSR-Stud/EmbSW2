#include <cstdio>
int main(void)
{
  const int table1[] = {1, 2, 3};
  static const int table2[] = {1, 2, 3};
  static int table3[] = {1, 2, 3};
  printf("%d\n", table1[1]+2);
  printf("%d\n", table2[2]);
  printf("%d\n", table3[1]);
  return 0;
}

