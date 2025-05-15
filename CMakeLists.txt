cmake_minimum_required(VERSION 3.12)
project(blink C)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Compiler flags
add_compile_options(
    -Wall
    -Wextra
    -g3
)

# Source files
set(SOURCES
    src/main.c
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})
