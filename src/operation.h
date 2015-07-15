#ifndef operation_H
#define operation_H

#define MSB_4bits    0b0000111111111111
#define MSB_5bits    0b0000011111111111
#define MSB_6bits    0b0000001111111111
#define MSB_7bits    0b0000000111111111
#define MSB_8bits    0b0000000011111111

int BSR;                     //Bank select register
int WREG;                    //Working register
int REG0[255];               //File registers in bank 0
int REG1[255];               //File registers in bank 1
int REG2[255];               //File registers in bank 2
int REG3[255];               //File registers in bank 3
int REG4[255];               //File registers in bank 4
int REG5[255];               //File registers in bank 5

int op_MOVLW(int flash_Mem);
int op_MOVLB(int flash_Mem);
int op_MOVWF(int flash_Mem);
int op_ADDLW(int flash_Mem);
int op_ANDLW(int flash_Mem);
int op_IORLW(int flash_Mem);
int op_MULLW(int flash_Mem);
int op_XORLW(int flash_Mem);
int op_NOP();

#endif // operation_H
