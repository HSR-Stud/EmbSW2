//============================================================================
// Name        : CipherFreq.cpp
// Author      : Reto Bonderer
// Version     :
// Copyright   : (c) Reto Bonderer
// Description : Attacks based on the char frequencies
// you may use the following knowledge for your attack:
// (1) key is 3 lowercase letters (a-z)
// (2) key is repeated as long as needed and xored byte by byte
// (3) the plaintext contains mixed cases, digits, punctuation and spaces
// (4) the plaintext is in English, the 10 most common letters in the English
//     language are, in order of decreasing frequency: e, t, a, o, i, n, s, h, r, d, l.
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

static const char ciphertext[] =
// to long to show

struct CharFreq
{
  char ch;
  unsigned int count;
};

// counts frequencies of a ciphertext character for the (chrPos+1)th key character
void countFrequencies(const char* cText,        // ciphertext
                      unsigned int cNumber,     // cText size
                      unsigned int chrPos,      // position of key char (0..2)
                      CharFreq* f,              // array of char counters
                      unsigned int charNumber); // number of array elems in f

// returns the key character from the most frequent ciphertext character in f
char getKeyChar(const CharFreq* f,              // array of char counters
                unsigned int charNumber);       // number of array elems in f

// prints the first 'number' chars of the decrypted text
void printText(char first, char second, char third, const char* cText, unsigned int number);


int main(void)
{
  char key[3];

  cout << "Here is the key:" << endl;
  for (unsigned int k = 0; k < 3; ++k) // keylength = 3
  {
    CharFreq chFreq[256] = {{0, 0}};  // stores the frequencies of the chars

    // count freqs of (k+1)th key character
    countFrequencies(ciphertext, sizeof(ciphertext), k, chFreq, sizeof(chFreq)/sizeof(chFreq[0]));
    key[k] = getKeyChar(chFreq, sizeof(chFreq)/sizeof(chFreq[0]));
    cout << key[k];
  }

  cout << endl << endl << "Here is the full text:" << endl;
  printText(key[0], key[1], key[2], ciphertext, sizeof(ciphertext));

  return 0;
}

void countFrequencies(const char* cText, unsigned int cNumber, unsigned int chrPos,
                      CharFreq* f, unsigned int charNumber)
{
  unsigned int top = 0;  // index of next char to store
  for (unsigned int i = 0; i < cNumber; i+=3) // 3: keylength
  {
    unsigned int j;
    for (j = 0; j <= top; ++j)
    {
      if (cText[i+chrPos] == f[j].ch) // found entry
      {
        ++(f[j].count);
        break;
      }
    }
    if (j > top) // didn't find entry
    {
      f[top].ch = cText[i+chrPos];
      f[top].count = 1;
      ++top;
    }
  }
}

char getKeyChar(const CharFreq* f, unsigned int charNumber)
{
  // in fact: the most frequent character is the space character, 2nd is 'e' in English
  unsigned int count = f[0].count;
  unsigned int pos = 0;

  for (unsigned int i = 1; i < charNumber; ++i)
  {
    if (f[i].count > count)
    {
      count = f[i].count;
      pos = i;
    }
  }
  return f[pos].ch ^ 0x20; // space is the most frequent
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
