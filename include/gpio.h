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
int gpio_init(void);

// Set GPIO pin state
void gpio_write(int pin, int value);

// Read GPIO pin state
int gpio_read(int pin);

// Toggle GPIO pin state
void gpio_toggle(int pin);

// GPIO constants
#define GPIO_HIGH 1
#define GPIO_LOW  0

#endif // GPIO_H
