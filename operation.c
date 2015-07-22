#include "operation.h"
#include "interpreter.h"
#include "stdio.h"

//Move literal to WREG
int op_MOVLW(int flash_Mem)
{
    WREG = flash_Mem & MSB_8bits;
    return WREG;
}

//Move literal to BSR<3:0>
int op_MOVLB(int flash_Mem)
{
    int MSB_12bits = 0b0000000000001111;
    BSR = flash_Mem & MSB_12bits;
    return BSR;
}

//Move WREG to file register
int op_MOVWF(int flash_Mem)
{
    int loc = flash_Mem & MSB_8bits;
    int temp = 0b0000000100000000;
    int a = flash_Mem & temp;
    
    if(a == 0b0000000100000000)
    {
        switch(BSR)
        {
            case 1 : REG1[loc] = WREG; return REG1[loc]; break;
            case 2 : REG2[loc] = WREG; return REG2[loc]; break;
            case 3 : REG3[loc] = WREG; return REG3[loc]; break;
            case 4 : REG4[loc] = WREG; return REG4[loc]; break;
            case 5 : REG5[loc] = WREG; return REG5[loc]; break;
            default : return 0; break;
        }
    }
    else
    {
        REG0[loc] = WREG;
        return REG0[loc];
    }
}

//Add literal and WREG
int op_ADDLW(int flash_Mem)
{
    flash_Mem &= MSB_8bits;
    WREG += flash_Mem;
    return WREG;
}

//AND literal with WREG
int op_ANDLW(int flash_Mem)
{
    flash_Mem &= MSB_8bits;
    WREG &= flash_Mem;
    return WREG;
}

//Inclusive OR literal with WREG
int op_IORLW(int flash_Mem)
{
    flash_Mem &= MSB_8bits;
    WREG |= flash_Mem;
    return WREG;
}

//Multiply literal with WREG
int op_MULLW(int flash_Mem)
{
    flash_Mem &= MSB_8bits;
    WREG *= flash_Mem;
    return WREG;
}

//Exclusive OR literal with WREG
int op_XORLW(int flash_Mem)
{
    flash_Mem &= MSB_8bits;
    WREG = ~(WREG | flash_Mem);
    return WREG;
}

//Clear file register
int op_CLRF(int flash_Mem)
{
    int loc = flash_Mem & MSB_8bits;
    int temp = 0b0000000100000000;
    int a = flash_Mem & temp;
    
    if(a == 0b0000000100000000)
    {
        switch(BSR)
        {
            case 1 : REG1[loc] = 0; return REG1[loc]; break;
            case 2 : REG2[loc] = 0; return REG2[loc]; break;
            case 3 : REG3[loc] = 0; return REG3[loc]; break;
            case 4 : REG4[loc] = 0; return REG4[loc]; break;
            case 5 : REG5[loc] = 0; return REG5[loc]; break;
            default : return 0; break;
        }
    }
    else
    {
        REG0[loc] = 0;
        return REG0[loc];
    }
}

int op_SETF(int flash_Mem)
{
    int loc = flash_Mem & MSB_8bits;
    int temp = 0b0000000100000000;
    int a = flash_Mem & temp;
    
    if(a == 0b0000000100000000)
    {
        switch(BSR)
        {
            case 1 : REG1[loc] = 0xFF; return REG1[loc]; break;
            case 2 : REG2[loc] = 0xFF; return REG2[loc]; break;
            case 3 : REG3[loc] = 0xFF; return REG3[loc]; break;
            case 4 : REG4[loc] = 0xFF; return REG4[loc]; break;
            case 5 : REG5[loc] = 0xFF; return REG5[loc]; break;
            default : return 0; break;
        }
    }
    else
    {
        REG0[loc] = 0xFF;
        return REG0[loc];
    }
}

//No operation
int op_NOP()
{
    return 0;
}