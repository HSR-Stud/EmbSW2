//===================================================
// Name        : cipher.cpp
// Author      : Reto Bonderer
// Version     : 20190528
// Copyright   : (c) HSR R. Bonderer
// Description : find the key and decipher the ciphertext
//
// you may use the following knowledge for your attack:
// (1) key is 3 lowercase letters (a-z)
// (2) key is repeated as long as needed and xored byte by byte
// (3) the plaintext contains mixed cases, digits, punctuation and spaces
// (4) the plaintext is in English, the 10 most common letters in the English
//     language are, in order of decreasing frequency: 
//      e, t, a, o, i, n, s, h, r, d, l. 
//=======================================================

#include <cstdint>
#include <iostream>

using namespace std;

static const char ciphertext[] =
{
37, 28, 0, 13, 83, 17, 7, 30, 31, 7, 29, 30, 17, 83, 25, 6, 28, 5, 6, 83, 1, 1, 30, 2, 4, 10, 82, 9, 0, 82, 58, 28, 31, 13, 28, 82, 9, 29, 22, 72, 57, 7, 4, 26, 23, 28, 95, 82, 60, 27, 23, 72, 39, 0, 9, 20, 23, 12, 10, 82, 7, 21, 82, 58, 28, 31, 13, 28, 82, 9, 29, 22, 72, 57, 7, 4, 26, 23, 28, 83, 27, 27, 83, 29, 6, 22, 82, 7, 21, 82, 63, 26, 30, 4, 26, 19, 5, 83, 33, 0, 18, 25, 13, 0, 2, 13, 18, 0, 13, 84, 1, 72, 30, 29, 27, 7, 82, 14, 18, 31, 7, 6, 1, 72, 4, 29, 26, 24, 1, 70, 83, 38, 0, 22, 82, 24, 31, 19, 17, 83, 20, 7, 31, 30, 7, 4, 1, 72, 7, 26, 13, 83, 30, 1, 5, 23, 27, 83, 19, 6, 23, 82, 12, 22, 19, 28, 27, 1, 72, 28, 20, 72, 33, 29, 5, 22, 29, 72, 18, 28, 12, 83, 56, 29, 31, 27, 13, 7, 94, 72, 7, 5, 7, 83, 11, 7, 6, 28, 15, 83, 1, 28, 18, 0, 69, 16, 0, 7, 0, 1, 13, 23, 82, 4, 28, 4, 13, 1, 1, 72, 21, 0, 7, 30, 82, 14, 22, 7, 12, 26, 28, 15, 83, 20, 9, 30, 27, 4, 26, 23, 27, 83, 27, 6, 83, 36, 13, 1, 29, 6, 18, 92, 72, 39, 26, 13, 0, 23, 72, 5, 27, 7, 31, 23, 6, 7, 82, 12, 22, 30, 1, 20, 26, 28, 0, 82, 0, 18, 4, 13, 83, 4, 1, 28, 30, 13, 29, 6, 72, 22, 28, 12, 0, 94, 72, 50, 28, 12, 83, 27, 6, 83, 6, 0, 22, 27, 26, 83, 6, 26, 26, 7, 5, 3, 26, 72, 23, 27, 13, 72, 82, 4, 26, 25, 13, 83, 20, 1, 1, 23, 72, 18, 28, 12, 83, 2, 7, 4, 22, 13, 1, 94, 72, 36, 26, 1, 16, 26, 68, 83, 19, 27, 83, 6, 0, 22, 11, 72, 24, 27, 27, 0, 94, 72, 16, 29, 6, 0, 7, 5, 22, 72, 72, 7, 26, 13, 83, 1, 31, 22, 23, 28, 22, 1, 28, 83, 26, 7, 29, 23, 17, 83, 59, 27, 83, 30, 7, 18, 6, 0, 0, 29, 5, 22, 82, 1, 29, 82, 0, 26, 1, 72, 28, 5, 6, 83, 22, 13, 31, 27, 11, 26, 29, 29, 0, 28, 13, 0, 1, 68, 83, 51, 6, 23, 82, 1, 29, 82, 28, 27, 23, 72, 7, 19, 27, 7, 23, 72, 16, 29, 6, 21, 29, 29, 29, 22, 27, 83, 6, 0, 22, 82, 9, 3, 2, 13, 7, 27, 28, 22, 72, 72, 39, 26, 13, 1, 23, 14, 28, 0, 13, 83, 30, 7, 5, 23, 72, 30, 29, 12, 22, 0, 9, 7, 23, 4, 10, 72, 72, 31, 29, 6, 20, 82, 4, 28, 4, 13, 83, 22, 7, 7, 26, 72, 0, 29, 70, 83, 52, 26, 26, 19, 26, 83, 62, 9, 4, 0, 13, 29, 17, 13, 83, 90, 41, 16, 6, 72, 65, 94, 72, 32, 17, 13, 29, 23, 72, 69, 91, 72, 32, 2, 7, 24, 23, 6, 83, 16, 17, 83, 52, 26, 26, 19, 26, 83, 62, 9, 4, 0, 13, 29, 17, 13, 83, 16, 13, 21, 29, 26, 22, 82, 0, 22, 82, 5, 18, 0, 26, 26, 23, 27, 83, 32, 7, 30, 23, 7, 83, 29, 14, 21, 82, 28, 28, 82, 34, 6, 30, 1, 22, 6, 68, 83, 6, 0, 26, 1, 72, 0, 26, 7, 1, 6, 72, 0, 2, 13, 22, 17, 0, 83, 17, 7, 6, 28, 27, 22, 30, 27, 83, 6, 0, 22, 82, 17, 28, 7, 6, 20, 82, 4, 28, 4, 13, 1, 82, 28, 28, 82, 28, 22, 31, 24, 22, 0, 72, 27, 27, 27, 83, 19, 5, 28, 0, 7, 6, 1, 72, 3, 19, 27, 0, 27, 7, 29, 1, 70, 83, 59, 6, 83, 6, 0, 26, 1, 72, 2, 7, 7, 7, 23, 68, 83, 6, 0, 22, 82, 14, 1, 27, 9, 1, 82, 29, 0, 23, 27, 83, 6, 0, 22, 82, 13, 11, 19, 5, 3, 30, 13, 83, 29, 14, 83, 26, 7, 29, 23, 17, 95, 82, 31, 27, 27, 11, 27, 94, 72, 18, 30, 28, 27, 29, 29, 20, 26, 72, 23, 23, 4, 26, 17, 1, 28, 7, 27, 83, 6, 7, 83, 29, 29, 1, 82, 28, 18, 1, 28, 22, 82, 10, 6, 22, 27, 95, 82, 11, 18, 28, 72, 16, 19, 29, 0, 23, 72, 0, 23, 26, 26, 29, 29, 0, 82, 27, 7, 29, 5, 18, 17, 0, 83, 2, 9, 26, 28, 27, 83, 27, 14, 83, 5, 13, 83, 23, 9, 7, 82, 28, 28, 29, 72, 30, 7, 11, 27, 82, 28, 28, 29, 72, 2, 7, 1, 16, 25, 4, 10, 92, 72, 58, 28, 72, 7, 26, 13, 83, 1, 9, 30, 23, 72, 4, 19, 17, 95, 82, 31, 27, 27, 4, 22, 82, 26, 6, 1, 0, 26, 28, 15, 83, 27, 6, 7, 29, 72, 18, 82, 4, 28, 4, 1, 29, 21, 72, 1, 23, 4, 18, 6, 1, 28, 28, 27, 27, 27, 24, 83, 27, 27, 83, 6, 13, 30, 2, 28, 26, 28, 15, 95, 82, 1, 7, 85, 27, 83, 20, 9, 1, 82, 31, 26, 1, 13, 1, 82, 28, 28, 82, 10, 22, 82, 5, 28, 22, 13, 1, 19, 28, 22, 82, 31, 26, 6, 0, 83, 29, 29, 1, 82, 24, 18, 1, 27, 26, 29, 6, 0, 82, 1, 21, 82, 31, 22, 82, 31, 18, 28, 28, 83, 19, 72, 30, 19, 26, 1, 27, 9, 20, 23, 72, 7, 26, 9, 7, 82, 31, 26, 30, 4, 83, 23, 6, 23, 7, 26, 22, 82, 14, 28, 0, 72, 18, 82, 4, 26, 20, 13, 7, 27, 5, 22, 92, 72, 36, 26, 1, 31, 23, 72, 7, 26, 1, 0, 82, 1, 0, 82, 9, 31, 30, 72, 0, 29, 29, 29, 22, 72, 18, 22, 30, 26, 17, 13, 95, 82, 31, 22, 82, 11, 28, 7, 4, 23, 82, 9, 31, 1, 7, 83, 0, 13, 18, 22, 72, 7, 26, 1, 0, 82, 27, 27, 29, 26, 7, 82, 27, 22, 0, 5, 28, 28, 72, 18, 1, 72, 21, 29, 26, 22, 1, 0, 18, 22, 7, 4, 27, 6, 20, 82, 58, 28, 31, 13, 28, 82, 9, 29, 22, 72, 57, 7, 4, 26, 23, 28, 84, 1, 72, 84, 4, 1, 28, 30, 13, 29, 6, 72, 22, 28, 12, 0, 85, 72, 7, 26, 9, 7, 82, 11, 28, 31, 13, 83, 19, 27, 83, 19, 72, 1, 23, 27, 6, 30, 28, 83, 29, 14, 83, 6, 0, 22, 27, 26, 83, 85, 30, 26, 29, 4, 22, 28, 28, 83, 22, 13, 31, 27, 15, 27, 6, 27, 93, 85
};


// checks whether the key generates only valid plain chars from 'cText'
// 'number' chars are checked
// returns true: only valid chars
// returns false: else
bool checkKey(char first, char second, char third, const char* cText, unsigned int number);

// checks whether 'cand' is a valid plain char
// returns true: valid char
// returns false: else
bool checkChar(char cand);

// prints the first 'number' chars of the decrypted text 
void printText(char first, char second, char third, const char* cText, unsigned int number);


int main(void)
{
  // Find the key and decipher the ciphertext
  // find candidates
  cout << "Here are the candidates:" << endl;
  for (char first = 'a'; first <= 'z'; ++first)
  {
    for (char second = 'a'; second <= 'z'; ++second)
    {
      for (char third = 'a'; third <= 'z'; ++third)
      {
        if (checkKey(first, second, third, ciphertext, sizeof(ciphertext))) // valid
        {  // print first 60 characters
          cout << first << second << third << ": ";
          printText(first, second, third, ciphertext, 60);
        }
      }
    }
  }

  cout << endl << endl << "Here is the full text:" << endl;
  printText('h', 's', 'r', ciphertext, sizeof(ciphertext));

  return 0;
}

bool checkChar(char cand)
{
  return cand >= 32 && cand <= 122;
}

bool checkKey(char first, char second, char third, const char* cText, unsigned int number)
{
  char* pch = const_cast<char*>(cText);
  for (unsigned int i = 0; i < number/3; ++i)
  {
    char ch1 = first ^ *pch++;    
    char ch2 = second ^ *pch++;
    char ch3 = third ^ *pch++; 
    if (!checkChar(ch1) || !checkChar(ch2) || !checkChar(ch3)) 
      return false;
  }
  return true;
}

void printText(char first, char second, char third, const char* cText, unsigned int number)
{
  char* pch = const_cast<char*>(cText);
  for (unsigned int i = 0; i < number/3; ++i)
  {
    char ch1 = first ^ *pch++;    
    char ch2 = second ^ *pch++;
    char ch3 = third ^ *pch++; 

    cout << ch1 << ch2 << ch3;
  }
  cout << endl;
}

