/*
 * EventReceiver.h
 *
 *  (C) G. Danuser, HSR Hochschule Rapperswil, April 2020
 */

#ifndef ALGO_EVENTRECEIVER_H_
#define ALGO_EVENTRECEIVER_H_

namespace algo
{

class EventReceiver
{
public:
  ///> Algorithm event type.
	enum class Event
	{
		unknown, ///< unknown event
		pulseDetected ///< pulse detected event
	};

	/**
	 * Is called on each algorithm event.
	 * @param ev event
	 */
	virtual void onAlgorithmEvent(const Event& ev) = 0;

	/**
	 * Dtor
	 */
	virtual ~EventReceiver() = default;
};

} /* namespace algo */

#endif /* ALGO_EVENTRECEIVER_H_ */
