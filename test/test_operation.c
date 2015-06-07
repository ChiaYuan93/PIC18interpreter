#include "stdio.h"
#include "unity.h"
#include "operation.h"
#include "interpreter.h"

void setUp(void){}

void tearDown(void){}

void test_op_MOVLW_move_10101011_to_WREG(void)
{
	TEST_ASSERT_EQUAL(0b10101011, op_MOVLW(0b10101011));
}

void test_op_MOVWF_move_11011110_to_00010010_file_register(void)
{
    WREG = 0b11011110;
	TEST_ASSERT_EQUAL(WREG, op_MOVWF(00010010));
}

void test_op_MOVLB_move_00000001_to_BSR(void)
{
    TEST_ASSERT_EQUAL(00000001, op_MOVLB(00000001));
}

void test_move_WREG_to_file_register(void)
{
    TEST_ASSERT_EQUAL(0b10101011, op_MOVLW(0b10101011));
	TEST_ASSERT_EQUAL(WREG, op_MOVWF(0));
}

void test_move_00010001_to_00010000_file_register_in_bank_1(void)
{
    op_MOVLB(0b00000001);
    op_MOVLW(0b00010001);
    TEST_ASSERT_EQUAL(WREG, op_MOVWF(0b00010000));
}

void test_move_0000000100000110_to_0x10_file_register_in_bank_6_should_return_0(void)
{
    op_MOVLB(0b0000000100000110);
    op_MOVLW(0b0000111000010001);
    TEST_ASSERT_EQUAL(0, op_MOVWF(0b0110111100010000));
}

void test_move_0x11_to_0x10_file_register_in_bank_5(void)
{
    op_MOVLB(0b0000000100000101);
    op_MOVLW(0b0000111000010001);
    TEST_ASSERT_EQUAL(WREG, op_MOVWF(0b0110111100010000));
}

void test_op_NOP_should_return_0(void)
{
    TEST_ASSERT_EQUAL(0, op_NOP());
}

void test_op_ADDLW_add_0x50_to_WREG_and_put_back_to_WREG(void)
{
    WREG = 0x20;
    TEST_ASSERT_EQUAL(WREG, op_ADDLW(0x50));
}

void test_op_ADDLW_add_0x40_to_WREG_and_put_back_to_WREG(void)
{
    WREG = 0x20;
    TEST_ASSERT_EQUAL(WREG, op_ADDLW(0x40));
}

void test_op_ANDLW_AND_0xAA_to_WREG_and_put_back_to_WREG(void)
{
    WREG = 0x10;
    TEST_ASSERT_EQUAL(WREG, op_ANDLW(0xAA));
}

void test_op_IORLW_inclusive_OR_0xBB_to_WREG_and_put_back_to_WREG(void)
{
    WREG = 0x10;
    TEST_ASSERT_EQUAL(WREG, op_IORLW(0xBB));
}

void test_op_MULLW_multiply_0xCC_to_WREG_and_put_back_to_WREG(void)
{
    WREG = 0x10;
    TEST_ASSERT_EQUAL(WREG, op_MULLW(0xCC));
}

void test_op_XORLW_exclusive_OR_0xDD_to_WREG_and_put_back_to_WREG(void)
{
    WREG = 0x10;
    TEST_ASSERT_EQUAL(WREG, op_XORLW(0xDD));
}




