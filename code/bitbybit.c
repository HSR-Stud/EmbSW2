typedef uint8_t Crc;
enum {crcWidth = 8 * sizeof(Crc),
  crcTopBit = 1 << (crcWidth - 1)};

Crc crcSlow(const uint8_t message[], unsigned int nBytes){
  Crc remainder = 0;
  Crc crcPoly = 0x07;
  for (unsigned int byte = 0; byte < nBytes; ++byte)
  {
    remainder ^= message[byte];
    for (unsigned int bit = 8; bit > 0; --bit)
    {
      if (remainder & crcTopBit)
        remainder = (remainder << 1) ^ crcPoly;
      else
        remainder = (remainder << 1);
    }
  }
  return remainder;
}
