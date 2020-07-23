/*
 * FIR.cpp
 *
 *  (C) G. Danuser, HSR Hochschule Rapperswil, April 2020
 */

#include "./FIR.h"

namespace algo
{

FIR::FIR(const float* coeffs, unsigned int length) :
    coeffs(coeffs, coeffs+length), // pointer are treated as iterator
    length(length)
{
  states.resize(length, 0.0f);
  p = states.data();
}

void FIR::process(float input, float& output)
{
  if (getEnabled())
  {
    // TODO: Implement FIR filtering algorithm here.
    //SOLUTION_BEGIN

    *p = input;

    output = 0.0;
    int i;
    for (i = 0; i < length-1; ++i)
    {
      output += coeffs[i] * (*p++);
      if (p >= (states.data() + length)) //circular buffer implementation in SW
        p = states.data();
    }
    output += coeffs[i] * (*p);

    //SOLUTION_END
  }
  else
  {
    output = input; //set output value as input value --> "block short circuit"
  }
}

} /* namespace algo */
