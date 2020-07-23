/*
 * StopWatch.h
 *
 *  Created on: 04.03.2013
 *      Author: rbondere
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

class StopWatch
{
  public:
    StopWatch();
    double elapsed() const;  // returns elapsed time since start in seconds
  private:
    double startTime;  // unit: seconds
};

#endif /* STOPWATCH_H_ */
