#include "gpio.h"
#include <stdio.h>

// Note: This is a simplified implementation for demonstration
// In a real project, this would interface with actual hardware

static gpio_state_t pin_states[64] = {GPIO_LOW}; // Track pin states
static gpio_direction_t pin_directions[64] = {GPIO_INPUT}; // Track pin directions

void gpio_init(uint8_t pin, gpio_direction_t direction) {
    if (pin < 64) {
        pin_directions[pin] = direction;
        pin_states[pin] = GPIO_LOW;
        printf("Initialized GPIO pin %d as %s\n", 
               pin, 
               direction == GPIO_INPUT ? "INPUT" : "OUTPUT");
    }
}

void gpio_write(uint8_t pin, gpio_state_t state) {
    if (pin < 64 && pin_directions[pin] == GPIO_OUTPUT) {
        pin_states[pin] = state;
        printf("Set GPIO pin %d to %s\n", 
               pin, 
               state == GPIO_HIGH ? "HIGH" : "LOW");
    }
}

gpio_state_t gpio_read(uint8_t pin) {
    if (pin < 64) {
        printf("Read GPIO pin %d: %s\n", 
               pin, 
               pin_states[pin] == GPIO_HIGH ? "HIGH" : "LOW");
        return pin_states[pin];
    }
    return GPIO_LOW;
}
