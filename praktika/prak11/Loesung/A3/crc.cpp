/*
 * crc.cpp
 *
 *  Created on: 27.02.2013
 *      Author: phoerler
 */

#include "crc.h"

Crc::Crc(uint8_t poly) {
  this->poly = poly;
}

Crc::~Crc() {
}

uint8_t Crc::getCrc(const uint8_t buf[], unsigned long len) const {

  uint8_t remainder = 0;
  //TODO unsigned long
  for (unsigned int byte = 0; byte < len; ++byte) {
  
    remainder ^= *(buf + byte);
    
    for (int bit = 8; bit > 0; --bit) {
    
      if (remainder & 0x80) {
        remainder = (remainder << 1) ^ poly;
      } else {
        remainder = (remainder << 1);
      }
    
    }
  
  }
  
  return remainder;
}
