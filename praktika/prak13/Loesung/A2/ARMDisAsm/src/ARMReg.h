/*
 * ARMReg.h
 *
 *  Created on: 22.05.2013
 *      Author: mtrummer
 */

#ifndef ARMREG_H_
#define ARMREG_H_


class ARMReg
{
public:

	int  getCPSR();
	void setCPSR(int val);
	void* getActPCAdr();
	void  setActPCAdr(void* adr);
	int getValOfReg(int nr);
private:
	int cpsr;
	void* pcAdr;
	int r[16];
};

#endif /* ARMREG_H_ */
