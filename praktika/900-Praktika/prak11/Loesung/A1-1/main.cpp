#include <cstdio>
int main(void)
{
  int table0[] = {1, 2, 3};
  const int table1[] = {1, 2, 3};
  static const int table2[] = {1, 2, 3};
  static int table3[] = {1, 2, 3};
  
  for(int i=0; i<3; ++i)
  {
    printf("%d\n", table0[i]);
    printf("%d\n", table1[2-i]);
    printf("%d\n", table2[i]+2);
    printf("%d\n", table3[2-i]);
  }
  return 0;
}

