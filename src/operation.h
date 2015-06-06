#ifndef operation_H
#define operation_H

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
int op_NOP();

#endif // operation_H
