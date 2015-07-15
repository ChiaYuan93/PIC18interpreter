#ifndef Execution_H
#define Execution_H
#include <stdint.h>

#define WREG    0xfe8
#define PCL     0xff9
#define PCLATH  0xffa
#define PCLATU  0xffb


typedef struct{
  uint32_t(*executionTable)(uint16_t instruction);
} ExecutionEntry;

char ramMemory[0x1000];
uint32_t addwf(uint16_t instruction);

#endif // Execution_H
