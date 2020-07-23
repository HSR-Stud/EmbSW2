/*
 * FIR.h
 *
 *  (C) G. Danuser, HSR Hochschule Rapperswil, April 2020
 */

#ifndef ALGO_FIR_H_
#define ALGO_FIR_H_

#include <vector>

#include "./Algorithm.h"

namespace algo
{

class FIR : public Algorithm
{
public:
  /**
   * Ctor
   */
	FIR(const float* coeffs, unsigned int length);

	/**
	 * Dtor
	 */
	~FIR() override = default;

	// overrides Algorithm::process
	void process(float input, float& output) override;

private:
	std::vector<float> states;
	std::vector<float> coeffs;
	unsigned int length;
	float* p;

};

} /* namespace algo */

#endif /* ALGO_FIR_H_ */
