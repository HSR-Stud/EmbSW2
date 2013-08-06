/*
 * ARMReg.cpp
 *
 *  Created on: 22.05.2013
 *      Author: mtrummer
 */


#include "ARMReg.h"

void ARMReg::setCPSR(int val)
{
	r[15] = val;
}

int ARMReg::getCPSR()
{
	return r[15];
}

void ARMReg::setActPCAdr(void* adr)
{
	pcAdr = adr;
}

void* ARMReg::getActPCAdr()
{
	return pcAdr;
}

int ARMReg::getValOfReg(int nr)
{
	return r[nr];
}
