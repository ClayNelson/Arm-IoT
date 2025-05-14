#include <stdint.h>

// Stack top
extern uint32_t _estack;

// Forward declaration of main
int main(void);

// Reset handler
void Reset_Handler(void) {
    // Initialize data and bss sections if needed
    // For now, just call main
    main();
    
    // If main returns, loop forever
    while(1);
}

// Default handler for other exceptions
void Default_Handler(void) {
    while(1);
}

// Vector table
__attribute__((section(".vectors")))
const void* vector_table[] = {
    &_estack,           // Initial stack pointer
    Reset_Handler,      // Reset handler
    Default_Handler,    // NMI
    Default_Handler,    // Hard Fault
    Default_Handler,    // MemManage
    Default_Handler,    // BusFault
    Default_Handler,    // UsageFault
    0,                 // Reserved
    0,                 // Reserved
    0,                 // Reserved
    0,                 // Reserved
    Default_Handler,    // SVCall
    Default_Handler,    // Debug Monitor
    0,                 // Reserved
    Default_Handler,    // PendSV
    Default_Handler     // SysTick
};
