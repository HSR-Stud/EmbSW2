/*
 * crcTest.h
 *
 *  Created on: 31.03.2016
 *      Author: Reto Bonderer
 */
 
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Crc.h"

using namespace std;

int main(int argc, char* argv[]) 
{
  // Predefined data will be used if no file name has been passed.
  const uint8_t data[] = {0xd9, 0x51, 0x61};

  Crc crc(0x07);  // use CRC-8 CCITT
  CrcType crcValue;
  
  cout << "CRC-8 CCITT mit einer Byte-orientierten Lookup Tabelle" << endl << endl;

  if (argc > 1) 
  {
    // compute CRC of the passed file (argv[1])
    ifstream f;
    uint8_t* buf;
    unsigned int len;
    
    try 
    {
      f.open(argv[1], ios::in | ios::binary);
      
      // determine file size
      f.seekg(0, ios::end);
      len = f.tellg();
      f.seekg(0, ios::beg);
      
      // read file content into byte buffer
      buf = new uint8_t[len];
      f.read((char*)buf, len);
      f.close();

      cout << "Datei:             " << argv[1] << endl;
      cout << "Anzahl Datenbytes: " << len << endl;
      
      // calculate CRC of the whole byte buffer
      crcValue = crc.getCrc(buf, len);
    
      cout << "CRC-8 CCITT:       " << setfill('0') << hex << showbase << internal 
           << setw(4) << (int)crcValue << endl;  
      
      // free allocated memory
      delete[] buf;
    } 
    catch (const exception& ex)
    {
      cerr << "Unable to read file '" << argv[1] << "'!" << endl;
    }
  } 
  else 
  {
    cout << "CRC-8 CCITT der einzelnen Datenbytes:" << endl;
    
    for (unsigned int i = 0; i < sizeof(data)/sizeof(data[0]); ++i) 
    {
      // compute CRC of the individual data bytes
      crcValue = crc.getCrc(&data[i], 1);
      
      cout << "Byte " << dec << setfill('0') << setw(2) << i 
           << ": crc(" << showbase << hex << internal << setw(4) << (int)data[i] 
           << ") = " << setw(4) << (int)crcValue << endl;
    }

    // compute CRC of all data bytes
    crcValue = crc.getCrc(data, sizeof(data)/sizeof(data[0]));
    
    cout << "CRC-8 CCITT von allen Datenbytes:" << endl;
    cout << "crc(" << setfill('0') << showbase << hex << internal << setw(4);
    for (unsigned int i = 0; i < sizeof(data)/sizeof(data[0]); ++i) 
    {    
      cout << (int)data[i] << noshowbase << setw(2);
    }
    cout << ") = " << showbase << setw(4) << (int)crcValue << endl << endl;
  }
  return 0;
}
