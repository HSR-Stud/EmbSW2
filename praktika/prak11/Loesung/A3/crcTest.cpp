/*
 * crcTest.h
 *
 *  Created on: 27.02.2013
 *      Author: phoerler
 */
 
#include <iostream>
#include <fstream>
#include <iomanip>
#include "crc.h"

using namespace std;

int main(int argc, char* argv[]) {

  // Predefined data will be used if no file name has been passed.
  const uint8_t data[] = {0xd9, 0x51, 0x61};

  Crc crc;
  uint8_t crcValue;
  
  cout << "CRC-8 CCITT Bit um Bit, einfach aber ineffizient" << endl << endl;
  
  if (argc > 1) {
  
    // compute CRC of the passed file (argv[1])
    ifstream f;
    uint8_t* buf;
    unsigned long len;
    
    try {
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
    
      cout << "CRC-8 CCITT:        0x" << hex << setw(2) << setfill('0') << (int)crcValue << endl;  
      // TODO: showbase
      
      // free allocated memory
      delete[] buf;

    } catch (const exception& ex) {
      cerr << "Unable to read file '" << argv[1] << "'!" << endl;
    }
    
  } else {
  
    cout << "CRC-8 CCITT der einzelnen Datenbytes:" << endl;
    
    for (int i = 0; i < 3; ++i) {
    
      // compute CRC of the individual data byte
      crcValue = crc.getCrc(&data[i], 1);
      
      cout << "Byte " << setw(2) << setfill('0') << i << ": crc(" << "0x" << hex << setw(2) << setfill('0') << (int)data[i] << ") = ";
      cout << "0x" << hex << setw(2) << setfill('0') << (int)crcValue << endl << endl;
      
    }
    
    // compute CRC of all data bytes
    crcValue = crc.getCrc(data, 3);
    
    cout << "CRC-8 CCITT von allen Datenbytes:" << endl;
    cout << "crc(" << "0x" << hex << setw(2) << setfill('0') << (int)data[0] << (int)data[1] << (int)data[2] << ") = ";
    cout << "0x" << hex << setw(2) << setfill('0') << (int)crcValue << endl << endl;
  
  }
  
  
  return 0;
}
