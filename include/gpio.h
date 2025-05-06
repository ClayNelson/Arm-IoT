#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

// GPIO Pin states
typedef enum {
    GPIO_LOW = 0,
    GPIO_HIGH = 1
} gpio_state_t;

// GPIO Pin directions
typedef enum {
    GPIO_INPUT = 0,
    GPIO_OUTPUT = 1
} gpio_direction_t;

// GPIO initialization
void gpio_init(uint8_t pin, gpio_direction_t direction);

// Set GPIO pin state
void gpio_write(uint8_t pin, gpio_state_t state);

// Read GPIO pin state
gpio_state_t gpio_read(uint8_t pin);

#endif // GPIO_H
