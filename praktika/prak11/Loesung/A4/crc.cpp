/*
 * crc.cpp
 *
 *  Created on: 27.02.2013
 *      Author: phoerler
 */

#include "crc.h"

Crc::Crc(uint8_t poly) {
  this->poly = poly;
  computeTable();
}

Crc::~Crc() {
}

// TODO oft offline berechnet
void Crc::computeTable() {
  uint8_t remainder = 0;
  
  for (int i = 0; i < 256; ++i) {
  
    remainder = i;
    
    for (int bit = 8; bit > 0; --bit) {
      
      if (remainder & 0x80) {
        remainder = (remainder << 1) ^ poly;
      } else {
        remainder <<= 1;
      }
      
    }
    
    crcTable[i] = remainder;
  
  }
  
}

uint8_t Crc::getCrc(const uint8_t buf[], unsigned long len) const {

  uint8_t remainder = 0;
  uint8_t data = 0;
  
  for (unsigned int byte = 0; byte < len; ++byte) {
  
    data = *(buf + byte) ^ remainder;
    remainder = crcTable[data]; // ^ (remainder << 8); // necessary if CRC width > 8
     
  }
  
  return remainder;
}
