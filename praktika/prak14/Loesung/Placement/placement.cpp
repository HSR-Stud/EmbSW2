/*
 * placement.cpp
 *
 *  Created on: 13.05.2011
 *      Author: rbondere
 */
#include <stdint.h>
#include <new>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

struct FooStruct
{
    char str[5];
    int key;
};

enum
{
  bufSize = 128
};

int main(void)
{
  uint8_t buffer[bufSize] = {0};

  uint32_t* ia = new (&buffer[0]) uint32_t[3];
  ia[0] = 0x55;
  ia[1] = 0xa354f60b;
  ia[2] = 0x45da12;

  double& d = *new (&buffer[64]) double;
  d = 3.14159;

  FooStruct* fs = new (&buffer[80]) FooStruct[2];
  strcpy(fs[0].str, "HSR");
  fs[0].key = 0xa5a5a5;
  strcpy(fs[1].str, "IMES");
  fs[1].key = 0x456c;

  cout << "Memory Map" << endl;
  cout << "==========" << endl;
  cout << setw(6) << "Byte#" << setw(10) << "Content" << endl;
  cout << setw(6) << "------" << setw(20) << "-------------------" << endl;

  for (int i = 0; i < bufSize; i++)
  {
    cout << setw(6) << dec << i
         << setw(10) << hex << showbase << static_cast<uint32_t>(buffer[i])
         << setw(10) << buffer[i] << endl;
  }
  return 0;
}
