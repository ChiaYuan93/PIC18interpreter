#include "Execution.h"
#include <stdint.h>


char ramMemory[0x1000];
int addwf;

// ExecutionEntry executionTable[256] = {
  // [0x24] = addwf,
  // [0x25] = addwf,
  // [0x26] = addwf,
  // [0x27] = addwf, 
  
  // executionTable[(addwf>>8) & 0xff]
// };


