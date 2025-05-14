#include <stdio.h>
#include "cmsis_compiler.h"
#include "RTE_Components.h"
#include CMSIS_device_header
#include "cmsis_os2.h"
#include "Driver_GPIO.h"

#define LED0 0

// Access the GPIO driver
extern ARM_DRIVER_GPIO Driver_GPIO0;

int main(void) {
    // Initialize GPIO driver
    Driver_GPIO0.Initialize();
    Driver_GPIO0.PowerControl(ARM_POWER_FULL);
    
    // Configure LED pin as output
    Driver_GPIO0.SetDirection(LED0, ARM_GPIO_OUTPUT);
    
    printf("LED blinking started. Press Ctrl+C to exit.\n");
    
    while(1) {
        // Turn LED on
        Driver_GPIO0.SetValue(LED0, 1);
        printf("LED ON\n");
        osDelay(1000);  // Delay for 1 second
        
        // Turn LED off
        Driver_GPIO0.SetValue(LED0, 0);
        printf("LED OFF\n");
        osDelay(1000);  // Delay for 1 second
    }
    
    return 0;
}
