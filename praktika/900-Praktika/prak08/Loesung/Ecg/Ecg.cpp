/*
 * Ecg.cpp
 *
 *  (C) G. Danuser, HSR Hochschule Rapperswil, April 2020
 */

#include "./Ecg.h"

#include <cassert>

#include "algo/FIR.h"
#include "algo/PulseDetector.h"

using algo::FIR;
using algo::PulseDetector;

const float Ecg::sgFilterCoeffs[] =
{
		// TODO: Add the correct filter coefficients to get a robust derivation
		//SOLUTION_BEGIN
		-0.0833,
		0.6667,
		//SOLUTION_END
		0.0,
		//SOLUTION_BEGIN
		-0.6667,
		0.0833,
		//SOLUTION_END
};

const unsigned int Ecg::sgFilterLength = sizeof(sgFilterCoeffs) / sizeof(float);

Ecg::Ecg()
{
	algos[static_cast<int>(Algos::fir)] = std::make_unique<FIR>( sgFilterCoeffs, sgFilterLength );
	algos[static_cast<int>(Algos::pulseDet)] = std::make_unique<PulseDetector>(0.1, -0.1);

	algos[static_cast<int>(Algos::pulseDet)]->setEventReceiver(this);

	algos[static_cast<int>(Algos::fir)]->setEnabled(false);
	algos[static_cast<int>(Algos::pulseDet)]->setEnabled(false);
}

void Ecg::processSample(float input, float& output, bool& state)
{
  isNewPulseDetected = false;
	output = input;
	for (int i = 0; i < NR_OF_ALGOS; ++i)
	{
		if (algos[i] != 0)
		{
			algos[i]->process(output, output);
		}
	}
	state = isNewPulseDetected;
}

void Ecg::setBpdThreshold(float value)
{
	PulseDetector& pd = *static_cast<PulseDetector*>(algos[static_cast<int>(Algos::pulseDet)].get());
	pd.setThreshold(value);
}

void Ecg::onAlgorithmEvent(const EventReceiver::Event& ev)
{
	switch (ev)
	{
	case EventReceiver::Event::pulseDetected:
	  isNewPulseDetected = true;
		break;
	default:
		break;
	}
}

void Ecg::enableAlgo(Algos algo, bool en)
{
	switch (algo)
	{
	case Algos::fir:
		algos[static_cast<int>(Algos::fir)]->setEnabled( en );
		break;
	case Algos::pulseDet:
		algos[static_cast<int>(Algos::pulseDet)]->setEnabled( en );
		break;
	default:
		break;
	}
}
