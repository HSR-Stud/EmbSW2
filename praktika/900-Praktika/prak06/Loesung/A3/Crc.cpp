/*
 * Crc.cpp
 *
 *  Created on: 25.03.2019
 *      Author: Reto Bonderer
 */

#include "Crc.h"

enum {crcWidth = 8 * sizeof(CrcType),
      crcTopBit = 1 << (crcWidth - 1)};

Crc::Crc(CrcType thePoly) :
  poly(thePoly)
{
}

CrcType Crc::getCrc(const uint8_t message[], unsigned int nBytes) const 
{
  CrcType remainder = 0;
  
  // modulo-2 division; byte by byte
  for (unsigned int byte = 0; byte < nBytes; ++byte) 
  {
    // XOR the next byte to the remainder
    remainder ^= (message[byte] << (crcWidth - 8));
    
    // modulo-2 division; bit by bit
    for (int bit = 8; bit > 0; --bit)
    {
      if (remainder & crcTopBit) 
      {
        remainder = (remainder << 1) ^ poly;
      } 
      else 
      {
        remainder = (remainder << 1);
      }
    }
  }
  return remainder;
}
