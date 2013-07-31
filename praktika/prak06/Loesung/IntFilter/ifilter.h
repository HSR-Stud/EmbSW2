/*
 * ifilter.h
 * Integer version
 *
 *  Created on: 26.03.2013
 *      Author: rbondere
 */

#ifndef IFILTER_H_
#define IFILTER_H_
/*
 * computes the filter length
 * \param filter: filename of the filter file
 * \return: number of filter coefficients
 */
int getFilterSize(const char* filter);

/*
 * Reads the filter coefficients from file and stores them in buffer
 * \param file: filename of the filter file
 * \param buffer: Data buffer, must be big enough
 */
void readFilter(const char* file,
                int buffer[]);

/*
 * Computes the convolution, i.e. the sum of products (MAC)
 * \param filter: filter data
 * \param buffer: buffer
 * \param lf: size of both arrays
 * \param pos: last element in buffer for the computation
 * \return result for data buffer point at pos-lf/2
 */
int convolve(const int filter[],
             const int buffer[],
             int lf,
             int pos);

#endif /* IFILTER_H_ */
