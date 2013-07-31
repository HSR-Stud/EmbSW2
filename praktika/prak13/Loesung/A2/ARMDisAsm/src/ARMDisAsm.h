/*
 * ARMDisAsm.h
 *
 *  Created on: 22.05.2013
 *      Author: mtrummer
 */

#ifndef ARMDISASM_H_
#define ARMDISASM_H_

#include "ARMReg.h"

enum
{
	ARM_PSR_Z = (1<<30),
	ARM_PSR_C = (1<<29),
	ARM_PSR_N = (1<<31),
	ARM_PSR_V = (1<<28)
};

class ARMDisAsm
{
public:
	ARMDisAsm(ARMReg* reg);
	void* getNextPCAdr(int opcode);
private:
	unsigned int getCondResult(unsigned int opcode);
	int set24BitTo32Bit(int val);
	void* evalAdrMode1andGetAdr(unsigned int opcode);
	void* evalAdrMode2andGetAdr(unsigned int opcode);
	void* evalAdrMode4andGetAdrOfPC(unsigned int opcode);
	int asr(int val, int shift);
	int lsl(int val, int shift);
	int lsr(int val, int shift);
	int ror(int val, int shift);
	ARMReg* reg;
};


#endif /* ARMDISASM_H_ */
