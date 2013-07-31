//============================================================================
// Name        : ARMDisAsm.cpp
// Author      : mtrummer
// Version     :
// Description : ARM Disassembler for B and BL
//============================================================================

#include "ARMDisAsm.h"


ARMDisAsm::ARMDisAsm(ARMReg* reg) : reg(reg)
{

}


void* ARMDisAsm::getNextPCAdr(int opcode)
{
  void* pAdr = reg->getActPCAdr();
  void* ret = (void*)((int*)pAdr + 1);  //Add Four Bytes
  //SOLUTION_BEGIN

  //0b101 -> B, BL
  if (((opcode>>25)&0x07) == 0x05)
  {
  //B, BL has Adr Range (23..0)
    if (getCondResult(opcode) > 0)
	{
	  //+2 steht für addition von 8 Bytes
	  ret = (void*)((set24BitTo32Bit(opcode&0x00FFFFFF)>>2)+2+(int*)pAdr);
	}
  }

  //SOLUTION_END
  return ret;
}

//------------------------------------------------------------------------------
// Check opcode conditionflags
// param  opcode   opcode to check for conditionflags
// return          1-> if condition is true 0-> if condition is false
//------------------------------------------------------------------------------
unsigned int ARMDisAsm::getCondResult(unsigned int opcode)
{
  unsigned int CPSR = reg->getCPSR();
  switch ((opcode>>28)&0xF)
  {
  case 0: if    (CPSR & ARM_PSR_Z)  return 1;
          break;
  case 1: if  (!(CPSR & ARM_PSR_Z)) return 1;
          break;
  case 2: if    (CPSR & ARM_PSR_C)  return 1;
          break;
  case 3: if  (!(CPSR & ARM_PSR_C)) return 1;
          break;
  case 4: if    (CPSR & ARM_PSR_N)  return 1;
          break;
  case 5: if  (!(CPSR & ARM_PSR_N)) return 1;
          break;
  case 6: if    (CPSR & ARM_PSR_V)  return 1;
          break;
  case 7: if  (!(CPSR & ARM_PSR_V)) return 1;
          break;
  case 8: if (  (CPSR & ARM_PSR_C)  &&(!(CPSR & ARM_PSR_Z))) return 1;
          break;
  case 9: if ((!(CPSR & ARM_PSR_C)) ||  (CPSR & ARM_PSR_Z)) return 1;
          break;
  case 10:if  (((CPSR & ARM_PSR_N)  &&  (CPSR & ARM_PSR_V))  ||
		     ((!(CPSR & ARM_PSR_N)) &&  (!(CPSR & ARM_PSR_V)))) return 1;
          break;
  case 11:if  (((CPSR & ARM_PSR_N)  &&(!(CPSR & ARM_PSR_V))) ||
		     ((!(CPSR & ARM_PSR_N)) &&    (CPSR & ARM_PSR_V)))  return 1;
          break;
  case 12:if ((!(CPSR & ARM_PSR_Z)) ||(((CPSR & ARM_PSR_N)    &&
		        (CPSR & ARM_PSR_V)) || ((!(CPSR & ARM_PSR_N)) &&
		      (!(CPSR & ARM_PSR_V))))) return 1;
          break;
  case 13:if   ((CPSR & ARM_PSR_Z)  ||(((CPSR & ARM_PSR_N)    &&
		      (!(CPSR & ARM_PSR_V)))|| ((!(CPSR & ARM_PSR_N)) &&
		        (CPSR & ARM_PSR_V))))  return 1;
          break;
  case 14:return 1;
          break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Convert 24Bit signed extended two's complement to 30 Bit and shift
// left two bits to from a 32Bit value
// param  opcode   opcode to check for conditionflags
// return          1-> if condition is true 0-> if condition is false
//------------------------------------------------------------------------------
int ARMDisAsm::set24BitTo32Bit(int val)
{
  if ((val<<8) < 0) val |= 0xFF000000;
  val <<= 2;
  return val;
}

