#include <stdio.h>
#include "cmsis_compiler.h"
#include "gpio.h"
#include <unistd.h>  // For sleep

#define LED_PIN 18   // Example GPIO pin for LED

int main(void) {
    printf("ARM IoT Project Initialized\n");
    
    // Initialize LED pin as output
    gpio_init(LED_PIN, GPIO_OUTPUT);
    
    // Blink LED 5 times
    for (int i = 0; i < 5; i++) {
        gpio_write(LED_PIN, GPIO_HIGH);
        sleep(1);  // Wait 1 second
        gpio_write(LED_PIN, GPIO_LOW);
        sleep(1);  // Wait 1 second
        
        __NOP();  // No Operation (useful for debugging)
    }
    
    return 0;
}
