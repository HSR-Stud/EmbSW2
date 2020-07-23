/*
 * PulseDetector.cpp
 *
 *  (C) G. Danuser, HSR Hochschule Rapperswil, April 2020
 */

#include "./PulseDetector.h"

namespace algo
{

PulseDetector::PulseDetector(float thPos, float thNeg, unsigned int blanking)
// TODO: Initialize variables
//SOLUTION_BEGIN
 : thresholdPos(thPos),
   thresholdNeg(thNeg),
   blanking(blanking),
   state(State::checkForPosTransition),
   t(0)
//SOLUTION_END
{

}

void PulseDetector::process(float input, float& output)
{
	// TODO: Implement detection state machine
	// Note: To fire an event call --> getEventReceiver()->onAlgorithmEvent(AlgorithmEvReceiver::EvPulseDetected);
	//SOLUTION_BEGIN
	output = input;
	if (getEnabled())
	{
    switch (state)
    {
      case State::checkForPosTransition:
        if (input >= thresholdPos )
        {
          t = 0;
          state = State::checkForNegTransition;
        }
        break;
      case State::checkForNegTransition:
        if (input <= thresholdNeg)
        {
          if ( getEventReceiver() ) {
            getEventReceiver()->onAlgorithmEvent(EventReceiver::Event::pulseDetected);
          }
          state = State::checkForPosTransition;
        }
        else if (t >= blanking)
        {
          state = State::checkForPosTransition;
        }
        break;
    }

    ++t;
	}
  //SOLUTION_END
}

void PulseDetector::setThreshold(float value)
{
	thresholdPos = value;
	thresholdNeg = -1*value;
}

} /* namespace algo */
