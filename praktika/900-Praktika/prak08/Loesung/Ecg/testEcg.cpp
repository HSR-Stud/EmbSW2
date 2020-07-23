//
// testEcg.cpp
//
// implements the tests for the Ecg class.
//
// (C) G. Danuser, HSR Hochschule Rapperswil, April 2020
//

#include <iostream>
#include <fstream>
#include <memory>

#include <gtest/gtest.h>

#include "./Ecg.h"

using namespace std;

TEST(EcgTest, DisabledTest)
{
  unique_ptr<ifstream> fEcgTestData = make_unique<ifstream>( "ecg.dat" );
  ASSERT_TRUE( fEcgTestData->is_open() );
  istream& in = *fEcgTestData;

  // drop comment lines
  while (in.peek() == '#')
  {
    string s;
    getline(in, s);
  }

  Ecg uut;
  uut.enableAlgo(Ecg::Algos::fir, false);
  uut.enableAlgo(Ecg::Algos::pulseDet, false);

  // store data in buffer and convolve
  float x;
  float y;
  float expY;
  bool state;
  bool expState;
  int cnt = 0;
  while ( in >> x )
  {
    uut.processSample( x, y, state );

    EXPECT_FLOAT_EQ( y, x );
    EXPECT_FALSE( state );
    ++cnt;
  }
  EXPECT_EQ(500, cnt); // check if all samples are processed
}
  
TEST(EcgTest, FirTest)
{
  unique_ptr<ifstream> fEcgTestData = make_unique<ifstream>( "ecg.dat" );
  ASSERT_TRUE( fEcgTestData->is_open() );
  istream& in = *fEcgTestData;

  // drop comment lines
  while (in.peek() == '#')
  {
    string s;
    getline(in, s);
  }

  unique_ptr<ifstream> fExpectedFirOutput = make_unique<ifstream>( "ecgExpected.dat" );
  ASSERT_TRUE( fExpectedFirOutput->is_open() );
  istream& expectedYIn = *fExpectedFirOutput;

  Ecg uut;
  uut.enableAlgo(Ecg::Algos::fir, true);
  uut.enableAlgo(Ecg::Algos::pulseDet, false);

  // store data in buffer and convolve
  float x;
  float y;
  float expY;
  bool state;
  bool expState;
  int cnt = 0;
  while ( in >> x &&
          expectedYIn >> expY )
  {
    uut.processSample( x, y, state );

    EXPECT_NEAR( y, expY, 1e-6 );
    EXPECT_FALSE( state );
    ++cnt;
  }
  EXPECT_EQ(500, cnt); // check if all samples are processed
}

TEST(EcgTest, PulseDetectorTest)
{
  unique_ptr<ifstream> fEcgTestData = make_unique<ifstream>( "ecg.dat" );
  ASSERT_TRUE( fEcgTestData->is_open() );
  istream& in = *fEcgTestData;

  // drop comment lines
  while (in.peek() == '#')
  {
    string s;
    getline(in, s);
  }

  unique_ptr<ifstream> fExpectedFirOutput = make_unique<ifstream>( "ecgExpected.dat" );
  ASSERT_TRUE( fExpectedFirOutput->is_open() );
  istream& expectedYIn = *fExpectedFirOutput;

  unique_ptr<ifstream> fExpectedState = make_unique<ifstream>( "stateExpected.dat" );
  ASSERT_TRUE( fExpectedState->is_open() );
  istream& expectedStateIn = *fExpectedState;

  Ecg uut;
  uut.enableAlgo(Ecg::Algos::fir, true);
  uut.enableAlgo(Ecg::Algos::pulseDet, true);

  // store data in buffer and convolve
  float x;
  float y;
  float expY;
  bool state;
  bool expState;
  int cnt = 0;
  while ( in >> x &&
          expectedYIn >> expY &&
          expectedStateIn >> expState )
  {
    uut.processSample( x, y, state );

    EXPECT_NEAR( y, expY, 1e-6 );
    EXPECT_EQ( state, expState );
    ++cnt;
  }
  EXPECT_EQ(500, cnt); // check if all samples are processed
}
