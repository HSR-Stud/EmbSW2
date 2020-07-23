/*
 * Algorithm.h
 *
 *  Created on: 08.04.2015
 *      Author: phoerler
 */

#ifndef ALGOS_ALGORITHM_H_
#define ALGOS_ALGORITHM_H_

#include "./EventReceiver.h"

namespace algo
{

class Algorithm
{
  public:
    /**
     * Ctor
     */
    Algorithm() :
        enabled(false),
        evReceiver( nullptr )
    {
    }

    /**
     * Dtor
     */
    virtual ~Algorithm() = default;

    /**
     * Processing function of the algorithm. Normally, this function will be overwritten by the derived classes, otherwise the input is passed to the output directly.
     * @param[in] input input sample
     * @param[out] output output sample
     */
    virtual void process(float input, float& output)
    {
      output = input;
    }

    /**
     * Enable the algorithm
     * @param[in] val enable or disable the algorithm
     */
    void setEnabled(bool val)
    {
      enabled = val;
    }

    /**
     * Returns whether the algorithm is enabled or not.
     * @return returns whether the algorithm is enabled or not
     */
    bool getEnabled() const
    {
      return enabled;
    }

    /**
     * Stores the given object as receiver for algorithm events.
     * @param[in] receiver reference to the object which is called if an algorithm event occurred
     */
    void setEventReceiver(EventReceiver* receiver)
    {
      evReceiver = receiver;
    }

    /**
     * Removes the event receiver.
     */
    void clearEventReceiver()
    {
      evReceiver = nullptr;
    }

  protected:
    EventReceiver* getEventReceiver() const
    {
      return evReceiver;
    }

    /**
     * Convolves input buffer and filter with a given length at a running index.
     * @param[in] filter filter coefficients of length lf
     * @param[in] buffer sample buffer of length lf
     * @param[in] lf length of the sample and filter coefficient buffers
     * @return returns the result of the discrete convolution
     */
    static float convolve( const float filter[],
                           const float buffer[],
                           int lf,
                           int pos )
    {
      float sum = 0;
      int k;
      for (k = 0; k < lf; ++k)
      {
        sum += filter[k] * buffer[(lf + pos - k) % lf];
      }
      return sum;
    }

  private:
    bool enabled;
    EventReceiver* evReceiver;
};

} /* namespace algo */

#endif /* ALGOS_ALGORITHM_H_ */
