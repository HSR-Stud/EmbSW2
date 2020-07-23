/*
 * port.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef CSL_PORT_H_
#define CSL_PORT_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief The C2000 port control register.
 */
typedef volatile struct
{
    uint32_t ctrl;
    uint32_t sel[2];
    uint32_t mux[2];
    uint32_t dir;
    uint32_t pud;
} csl_PortCtrlRegs;

/**
 * @brief The C2000 port data register.
 */
typedef volatile struct
{
    const uint32_t dat;
    uint32_t set;
    uint32_t clear;
    uint32_t toggle;
} csl_PortDataRegs;

/**
 * @brief The port ID.
 */
typedef enum
{
  csl_portA,
  csl_portB
} csl_PortId;

/**
 * @brief The port data.
 */
typedef struct
{
    csl_PortCtrlRegs* ctrl;
    csl_PortDataRegs* data;
} csl_Port;

/**
 * @brief Initializes the C2000 port to the preset sample period.
 *
 * @param port port data
 * @param id port ID
 * @param initSamplePeriod initializes the sample period if set
 *
 * @note This function is called automatically by \ref csl_pinInit.
 * @pre @p port pointer must be valid, validity is not checked!
 */
void csl_portInit(csl_Port* port, csl_PortId id, bool initSamplePeriod);

#endif /* CSL_PORT_H_ */
