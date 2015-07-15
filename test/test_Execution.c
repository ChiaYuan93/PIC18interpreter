#include "unity.h"
#include "Execution.h"

void setUp(void){}

void tearDown(void){}

void test_execute_addwf_should_stored_result_in_WREG(){
  ramMemory[WREG] = 0x17;
  ramMemory[0x01]  = 0x01;
  
  uint32_t addwf(uint16_t instruction);
  
  TEST_ASSERT_EQUAL(0X18, ramMemory[WREG]);
}

void test_execute_addwf_should_stored_result_in_file_register(){
  ramMemory[WREG] = 0x1f;
  ramMemory[0x01]  = 0x01;
  
  uint32_t addwf(uint16_t instruction);
  
  TEST_ASSERT_EQUAL(0X20, ramMemory[0x01]); 
}
