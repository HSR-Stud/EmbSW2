typedef uint8_t Crc;
enum {crcWidth = 8 * sizeof(Crc),
  crcTopBit = 1 << (crcWidth - 1)};

Crc crcFast(const uint8_t message[], unsigned int nBytes)
{
  Crc remainder = 0;
  uint8_t data;
  for (unsigned int byte = 0; byte < nBytes; ++byte)
  {
    data = message[byte] ^ remainder;
    remainder = crcTable[data];
  }
  return remainder;
}
