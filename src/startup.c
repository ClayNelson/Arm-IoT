#include <stdint.h>

// Stack top
extern uint32_t __stack_top;

// Forward declaration of main
int main(void);

// Reset handler
void Reset_Handler(void) {
    // Initialize data and bss sections
    extern uint32_t _sdata, _edata, _sidata;
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;

    while (dst < &_edata) {
        *dst++ = *src++;
    }

    extern uint32_t _sbss, _ebss;
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

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
    &__stack_top,       // Initial stack pointer
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
