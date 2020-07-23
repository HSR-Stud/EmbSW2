/*
 * crc.cpp
 *
 *  Created on: 31.03.2016
 *      Author: Reto Bonderer
 */

#include <iostream>
#include <iomanip>
#include "Crc.h"
using namespace std;

enum {crcWidth = 8 * sizeof(CrcType),
      crcTopBit = 1 << (crcWidth - 1)};

Crc::Crc(CrcType thePoly) :
  poly(thePoly)
{
  computeTable();
}

void Crc::computeTable() 
{
  CrcType remainder = 0;

  for (unsigned int i = 0; i < 256; ++i) 
  {
    remainder = i << (crcWidth - 8);
    for (unsigned int bit = 8; bit > 0; --bit) 
    {
      if (remainder & crcTopBit) 
      {
        remainder = (remainder << 1) ^ poly;
      } 
      else 
      {
        remainder <<= 1;
      }
    }
    crcTable[i] = remainder;
  }
}

CrcType Crc::getCrc(const uint8_t message[], unsigned int nBytes) const 
{
  CrcType remainder = 0;
  uint8_t data;
  
  for (unsigned int byte = 0; byte < nBytes; ++byte) 
  {
    data = message[byte] ^ (remainder >> (crcWidth - 8));
    remainder = crcTable[data] ^ (remainder << 8);
  }
  
  return remainder;
}
