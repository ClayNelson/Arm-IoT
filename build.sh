#!/bin/bash

# Compile the program
gcc -o blink src/main.c src/gpio.c -lpigpio

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    echo "Run the program with: sudo ./blink"
else
    echo "Compilation failed!"
fi
