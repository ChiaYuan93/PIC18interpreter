#include "Execution.h"
#include <stdint.h>
#include <stdio.h>


char ramMemory[0x1000];
uint16_t File_Reg;

ExecutionEntry executionTable[256] = {
  [0x24] = {addwf},
  [0x25] = {addwf},
  [0x26] = {addwf},
  [0x27] = {addwf}, 
  
  // executionTable[(addwf>>8) & 0xff]
};

uint32_t addwf(uint16_t instruction){
  if(instruction < 0x26){
    ramMemory[WREG] = ramMemory[WREG] + ramMemory[File_Reg];
    return ramMemory[WREG];
  }
  else
    ramMemory[File_Reg] = ramMemory[WREG] + ramMemory[File_Reg];
    return ramMemory[File_Reg];
}