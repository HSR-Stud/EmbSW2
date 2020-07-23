/*
 * Crc.h
 *
 * CRC 8 bit simple implementation
 *
 *  Created on: 31.03.2016
 *      Author: Reto Bonderer
 */
#ifndef CRC_H_
#define CRC_H_
 
#include <stdint.h>
 
typedef uint8_t CrcType;

class Crc 
{
  public:
    Crc(CrcType thePoly = 0x07);
    CrcType getCrc(const uint8_t message[], unsigned int nBytes) const;
  private:
    CrcType poly;
};

 #endif // CRC_H_

