/*
 * StopWatch.cpp
 *
 *  Created on: 04.03.2013
 *      Author: rbondere
 */

#include "StopWatch.h"
#include <sys/resource.h>
#include <sys/types.h>

StopWatch::StopWatch()
{
  rusage tp;
  getrusage(RUSAGE_SELF, &tp);
  startTime = static_cast<double>(tp.ru_utime.tv_sec) +
              static_cast<double>(tp.ru_utime.tv_usec)/1E6;
}

double StopWatch::elapsed() const
{
  rusage tp;
  getrusage(RUSAGE_SELF, &tp);
  return static_cast<double>(tp.ru_utime.tv_sec) +
         static_cast<double>(tp.ru_utime.tv_usec)/1E6 - startTime;
}
