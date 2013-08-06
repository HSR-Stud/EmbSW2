/*
 * main.cpp
 *
 *  Created on: 22.05.2013
 *      Author: mtrummer
 */

#include "ARMReg.h"
#include "ARMDisAsm.h"
#include <iostream>
using namespace std;

int main() {
	ARMReg reg;
	ARMDisAsm disasm(&reg);

	cout << "-----------------------------------------------------" << endl;
	reg.setActPCAdr((void*)0x20100150);
	reg.setCPSR(0x00);
	cout << "\nCalculate opcode: 0xEAFBFFAA" << endl;
	cout << "PC: " << reg.getActPCAdr() << endl;
	cout << "CPSR: " << reg.getCPSR() << endl;
	cout << "Next Adress must be:   0x20000000" << endl;
	cout << "Calculated address is: " << disasm.getNextPCAdr(0xEAFBFFAA) << endl;
	cout << "-----------------------------------------------------" << endl;

	reg.setActPCAdr((void*)0x20100150);
	reg.setCPSR(0x00);
	cout << "\nCalculate opcode: 0xEBFBFFAA" << endl;
	cout << "PC: " << reg.getActPCAdr() << endl;
	cout << "CPSR: " << reg.getCPSR() << endl;
	cout << "Next Adress must be:   0x20000000" << endl;
	cout << "Calculated address is: " << disasm.getNextPCAdr(0xEBFBFFAA) << endl;
	cout << "-----------------------------------------------------" << endl;

	reg.setActPCAdr((void*)0x21200150);
	reg.setCPSR(0x80);
	cout << "\nCalculate opcode: 0x1AFCFFAC" << endl;
	cout << "PC:   " << reg.getActPCAdr() << endl;
	cout << "CPSR: " << reg.getCPSR() << endl;
	cout << "Next Adress must be:   0x21140008" << endl;
	cout << "Calculated address is: " << disasm.getNextPCAdr(0x1AFCFFAC) << endl;
	cout << "-----------------------------------------------------" << endl;

	reg.setActPCAdr((void*)0x21200150);
	reg.setCPSR(0x80);
	cout << "Calculate opcode: 0xE3A00000" << endl;
	cout << "PC:   " << reg.getActPCAdr() << endl;
	cout << "CPSR: " << reg.getCPSR() << endl;
	cout << "Next Adress must be:   0x21200154" << endl;
	cout << "Calculated address is: " << disasm.getNextPCAdr(0xE3A00000) << endl;
	cout << "-----------------------------------------------------" << endl;
	return 0;
}
