// File: "tests/PrimeTest.cpp", 11.04.2013 phoerler

#include <cppunit/extensions/HelperMacros.h>

#include "../src/prime.h"

class PrimeTest: public CppUnit::TestCase
// Testsuite "PrimeTest"
{
private:
	CPPUNIT_TEST_SUITE(PrimeTest);
		CPPUNIT_TEST(testIsPrime);
	CPPUNIT_TEST_SUITE_END();
  
public:
    void setUp() {
    }
    
    void tearDown() {
   	}
    
    void testIsPrime() {
        CPPUNIT_ASSERT(isPrime(1) == false);
        CPPUNIT_ASSERT(isPrime(2) == true);
        CPPUNIT_ASSERT(isPrime(4) == false);
        CPPUNIT_ASSERT(isPrime(31) == true);
        CPPUNIT_ASSERT(isPrime(15) == false);
    }
};

// Alle Tests der Klasse 'PrimeTest' in der Default-Registry registrieren:
CPPUNIT_TEST_SUITE_REGISTRATION(PrimeTest);
