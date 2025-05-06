#include <stdio.h>
#include "cmsis_compiler.h"

int main(void) {
    printf("ARM IoT Project Initialized\n");
    
    // Example of using CMSIS intrinsic
    __NOP(); // No Operation (useful for debugging)
    
    return 0;
}
