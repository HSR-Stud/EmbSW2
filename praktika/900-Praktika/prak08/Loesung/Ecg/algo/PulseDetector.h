/*
 * PulseDetector.h
 *
 *  (C) G. Danuser, HSR Hochschule Rapperswil, April 2020
 */

#ifndef ALGO_PULSEDETECTOR_H_
#define ALGO_PULSEDETECTOR_H_

#include "./Algorithm.h"

namespace algo
{

class PulseDetector : public Algorithm {
public:

    /**
     * Ctor
     * @param[in] thPos positive going threshold
     * @param[in] thNeg negative going threshold
     * @param[in] blanking blanking number (default 3)
     */
	PulseDetector(float thPos, float thNeg, unsigned int blanking = 3);

	/**
	 * Dtor
	 */
	~PulseDetector() override = default;

	// overrides Algorithm::process
	void process(float input, float& output) override;

	/**
	 * Sets the pulse detection threshold.
	 * @param[in] value pulse detection threshold
	 */
	void setThreshold(float value);

private:

	float thresholdNeg;
	float thresholdPos;
	
  // TODO: Private declarations
  //SOLUTION_BEGIN
	enum class State
	{
		checkForNegTransition,
		checkForPosTransition
	};

	unsigned int blanking;
	unsigned int t;

	State state;
  //SOLUTION_END
};

} /* namespace algo */

#endif /* ALGO_PULSEDETECTOR_H_ */
