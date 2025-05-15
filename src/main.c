#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define LED_PIN     18  // GPIO18, can be changed to any available GPIO pin
#define EXPORT_PATH "/sys/class/gpio/export"
#define GPIO_PATH   "/sys/class/gpio/gpio%d"
#define DIRECTION   "/direction"
#define VALUE       "/value"

int gpio_export(int pin) {
    int fd = open(EXPORT_PATH, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open export file");
        return -1;
    }

    char buffer[3];
    snprintf(buffer, sizeof(buffer), "%d", pin);
    if (write(fd, buffer, strlen(buffer)) == -1) {
        perror("Failed to export GPIO");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}

int gpio_set_direction(int pin, const char* direction) {
    char path[50];
    snprintf(path, sizeof(path), GPIO_PATH DIRECTION, pin);

    int fd = open(path, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open direction file");
        return -1;
    }

    if (write(fd, direction, strlen(direction)) == -1) {
        perror("Failed to set direction");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}

int gpio_set_value(int pin, int value) {
    char path[50];
    snprintf(path, sizeof(path), GPIO_PATH VALUE, pin);

    int fd = open(path, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open value file");
        return -1;
    }

    char buffer = value ? '1' : '0';
    if (write(fd, &buffer, 1) == -1) {
        perror("Failed to write value");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}

int main(void) {
    printf("Starting LED blink program...\n");

    // Export GPIO
    if (gpio_export(LED_PIN) < 0) {
        fprintf(stderr, "Failed to export GPIO %d\n", LED_PIN);
        return 1;
    }

    // Give the system time to create the GPIO files
    sleep(1);

    // Set GPIO as output
    if (gpio_set_direction(LED_PIN, "out") < 0) {
        fprintf(stderr, "Failed to set GPIO direction\n");
        return 1;
    }

    printf("LED connected to GPIO%d will start blinking...\n", LED_PIN);

    // Blink LED
    while (1) {
        // Turn LED on
        if (gpio_set_value(LED_PIN, 1) < 0) {
            fprintf(stderr, "Failed to turn LED on\n");
            return 1;
        }
        printf("LED ON\n");
        sleep(1);

        // Turn LED off
        if (gpio_set_value(LED_PIN, 0) < 0) {
            fprintf(stderr, "Failed to turn LED off\n");
            return 1;
        }
        printf("LED OFF\n");
        sleep(1);
    }

    return 0;
}
