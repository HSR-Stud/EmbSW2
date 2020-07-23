/*
 * Crc.h
 *
 * CRC 8 bit lookup table implementation
 *
 *  Created on: 25.03.2019
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
    CrcType crcTable[256];
    void computeTable();
};

#endif // CRC_H_
