/*
 * crc.h
 *
 * CRC8 simple implementation
 *
 *  Created on: 27.02.2013
 *      Author: phoerler
 */
 
 #include <stdint.h>
 
 class Crc {
 
  public:
    Crc(uint8_t poly = 0x07);
    ~Crc();
    
    uint8_t getCrc(const uint8_t buf[], unsigned long len) const;
  
  private:
    uint8_t poly;
    
 };
