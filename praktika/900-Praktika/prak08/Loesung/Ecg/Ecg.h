/*
 * Ecg.h
 *
 *  (C) G. Danuser, HSR Hochschule Rapperswil, April 2020
 */

#ifndef ECG_H_
#define ECG_H_

#include <memory>

#include "algo/EventReceiver.h"
#include "algo/Algorithm.h"

class Ecg : public algo::EventReceiver
{
public:
  ///> Used algorithms
  enum class Algos
  {
    fir = 0, ///< FIR algorithm
    pulseDet ///< pulse detection algorithm
  };

  /**
   * Ctor
   */
	Ecg();

	/**
	 * Dtor
	 */
	~Ecg() override = default;

	// overrides EventReceiver::onAlgorithmEvent
	void onAlgorithmEvent(const algo::EventReceiver::Event& ev) override;

	/**
	 * Enables/disables the algorithm.
	 * @param[in] algo algorithm to enable/disable
	 * @param[in] en true to enable and false to disable the algorithm
	 */
	void enableAlgo(Algos algo, bool en);

	/**
	 * Sets the balanced photodetector (BPD) threshold.
	 * @param[in] value threshold
	 */
	void setBpdThreshold(float value);

	/**
	 * Processes a sample.
	 * @param[in] input input sample
	 * @param[out] output output sample
	 * @param[out] state pulse detector state (true: new pulse detected)
	 */
	void processSample(float input, float& output, bool& state);

private:

	enum { NR_OF_ALGOS = static_cast<int>(Algos::pulseDet)+1 };

	static const float sgFilterCoeffs[];
  static const unsigned int sgFilterLength;

	bool isNewPulseDetected;

	std::unique_ptr<algo::Algorithm> algos[NR_OF_ALGOS];
};

#endif /* ECG_H_ */
