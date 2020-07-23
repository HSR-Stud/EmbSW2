#include <cstdio>
int main(void)
{
  const char* pc1 = "Hello World";
  const char* const pc2 = "World";
  printf("%s\n", pc1);
  printf("%s\n", pc2);
  return 0;
}

