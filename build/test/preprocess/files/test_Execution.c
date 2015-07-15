#include "Execution.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_execute_addwf_should_stored_result_in_WREG(){

  ramMemory[0xfe8] = 0x17;

  ramMemory[0x01] = 0x01;



  uint32_t addwf(uint16_t instruction);



  UnityAssertEqualNumber((_U_SINT)((0X18)), (_U_SINT)((ramMemory[0xfe8])), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT);

}



void test_execute_addwf_should_stored_result_in_file_register(){

  ramMemory[0xfe8] = 0x1f;

  ramMemory[0x01] = 0x01;



  uint32_t addwf(uint16_t instruction);



  UnityAssertEqualNumber((_U_SINT)((0X20)), (_U_SINT)((ramMemory[0x01])), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_INT);

}
