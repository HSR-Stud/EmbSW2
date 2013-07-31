/*
 * fpfilter.h
 *
 *  Created on: 25.03.2013
 *      Author: rbondere
 */

#ifndef FPFILTER_H_
#define FPFILTER_H_
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
                double buffer[]);

/*
 * Computes the convolution, i.e. the sum of products (MAC)
 * \param filter: filter data
 * \param buffer: buffer
 * \param lf: size of both arrays
 * \param pos: last element in buffer for the computation
 * \return result for data buffer point at pos-lf/2
 */
double convolve(const double filter[],
                const double buffer[],
                int lf,
                int pos);

#endif /* FPFILTER_H_ */
