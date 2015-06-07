#include "operation.h"
#include "interpreter.h"
#include "stdio.h"

//Move literal to WREG
int op_MOVLW(int flash_Mem)
{
    int temp = 0b0000000011111111;
    WREG = flash_Mem & temp;
    return WREG;
}

//Move literal to BSR<3:0>
int op_MOVLB(int flash_Mem)
{
    int temp = 0b0000000000001111;
    BSR = flash_Mem & temp;
    return BSR;
}

//Move WREG to file register
int op_MOVWF(int flash_Mem)
{
    int temp0 = 0b0000000011111111;
    int temp1 = 0b0000000100000000;
    int loc = flash_Mem & temp0;
    int a = flash_Mem & temp1;
    
    if(a == 0b0000000100000000)
    {
        switch(BSR)
        {
            case 1 : REG1[loc] = WREG; return REG1[loc] = WREG; break;
            case 2 : REG2[loc] = WREG; return REG2[loc] = WREG; break;
            case 3 : REG3[loc] = WREG; return REG3[loc] = WREG; break;
            case 4 : REG4[loc] = WREG; return REG4[loc] = WREG; break;
            case 5 : REG5[loc] = WREG; return REG5[loc] = WREG; break;
            default : return 0; break;
        }
    }
    else
    {
        REG0[loc] = WREG;
        return REG0[loc];
    }
}

//No operation
int op_NOP()
{
    return 0;
}