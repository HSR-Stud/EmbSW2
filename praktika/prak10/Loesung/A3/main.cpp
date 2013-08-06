#include <cstdio>
struct Register
{
  uint32_t state :4;
  uint32_t flags :3;
  uint32_t unused :25;        // unused
};

int main(void)
{
  volatile Register r = {0};
  r.state = 15;
  printf("r = %#x\n",r);
  r.flags = 3;
  printf("r = %#x\n",r);
  ++r.flags;
  printf("r = %#x\n",r);
  r.flags &= 6;
  printf("r = %#x\n",r);
  
  return 0;
}

