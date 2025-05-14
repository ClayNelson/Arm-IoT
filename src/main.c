#include <stdint.h>

// GPIO register definitions for Corstone-300
#define GPIO_BASE       0x40100000
#define GPIO_DATA       (GPIO_BASE + 0x000)
#define GPIO_DIR        (GPIO_BASE + 0x400)
#define LED_PIN         0

// GPIO registers
volatile uint32_t* const gpio_data = (uint32_t*)GPIO_DATA;
volatile uint32_t* const gpio_dir = (uint32_t*)GPIO_DIR;

// Simple delay function
static void delay(volatile uint32_t count) {
    while (count--) {
        __asm("nop");
        __asm("nop");
    }
}

int main(void) {
    // Set LED pin as output
    *gpio_dir |= (1U << LED_PIN);
    
    while (1) {
        // Toggle LED
        *gpio_data ^= (1U << LED_PIN);
        delay(500000);
    }
    
    return 0;
}
