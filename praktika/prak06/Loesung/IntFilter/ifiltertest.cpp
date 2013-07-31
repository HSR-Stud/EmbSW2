/*
 * ifiltertest.cpp
 * Integer version
 *
 *  Created on: 08.04.2011
 *      Author: rbondere
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ifilter.h"
using namespace std;

// usage: filter filter1.dat ecg.dat output.dat
// argv[0]: program name (filter)
// argv[1]: filter file
// argv[2]: raw data (input) file
// argv[3]: filtered data output file

int main(int argc,
         char** argv)
{
  istream* in = &cin;
  ostream* out = &cout;

  // we need 3 parameters
  if (argc == 4)
  {
    ifstream* fin = new ifstream(argv[2]);
    if (!fin->is_open())
    {
      cerr << "Error: failed to open " << argv[2];
      return 1;
    }
    in = fin;
    ofstream* fout = new ofstream(argv[3]);
    if (!fout->is_open())
    {
      cerr << "Error: failed to open " << argv[3];
      return 1;
    }
    out = fout;
  }
  else
  {
    cerr << "Usage: " << argv[0] << " filter input output" << endl;
    return 0;
  }

  // compute filter length lf
  int lf = getFilterSize(argv[1]);
  if (lf <= 0)
  {
    cerr << "Error: filter file empty or unreadable" << endl;
    return 1;
  }
  else if (lf % 2 == 0)
  {
    cerr << "Warning: filter has even number of elements" << endl;
    lf--;
  }
  // allocate buffers, lf elements is enough for both
  int* buffer = new int[lf]; // ring buffer
  int* filter = new int[lf];

  // drop comment lines
  while (in->peek() == '#')
  {
    string s;
    getline(*in, s);
  }

  // read filter data
  readFilter(argv[1], filter);
  //initialize buffer to 0
  for (int i = 0; i < lf; ++i)
  {
    buffer[i] = 0;
  }

  // store data in buffer and convolve
  int d;
  int n = 0;
  while (*in >> d)
  {
    buffer[n % lf] = d;

    // the first lf/2 elements cannot be used
    if (n >= lf / 2)
    {
      *out << convolve(filter, buffer, lf, n) << endl;
    }
    n++;
  }

  //compute remaining elements
  int stop = lf / 2;
  if (n < lf / 2)
    stop = n;
  for (int i = 0; i < stop; ++i)
  {
    buffer[(n + i) % lf] = 0;
    *out << convolve(filter, buffer, lf, n + i) << endl;
  }

  delete[] buffer;
  delete[] filter;
  if (argc == 4)
  {
    delete in;
    delete out;
  }
  return 0;
}

