cmake_minimum_required(VERSION 3.12)

# Set up ARM cross-compilation
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Specify cross-compilers
set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

# Set cross-compilation search paths
set(CMAKE_FIND_ROOT_PATH /usr/arm-linux-gnueabihf)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Project definition
project(blink C)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Enable verbose output
set(CMAKE_VERBOSE_MAKEFILE ON)

# Set build type to Debug for better debugging info
set(CMAKE_BUILD_TYPE Debug)

# Add compiler flags
add_compile_options(
    -Wall
    -Wextra
    -g3
    -O2
    -march=armv7-a
    -mfpu=neon
    -mfloat-abi=hard
    -fPIC
    --sysroot=/usr/arm-linux-gnueabihf
)

# Source files
set(SOURCES
    src/main.c
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add required libraries and linker flags
target_link_libraries(${PROJECT_NAME}
    -static-libgcc
    -Wl,--dynamic-linker=/lib/ld-linux-armhf.so.3
    -Wl,--no-as-needed
    -ldl
    -lc
)

# Set RPATH and other properties
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    INSTALL_RPATH "/lib/arm-linux-gnueabihf:/usr/lib/arm-linux-gnueabihf"
    BUILD_WITH_INSTALL_RPATH TRUE
    LINK_FLAGS "-Wl,-rpath-link,/lib/arm-linux-gnueabihf:/usr/lib/arm-linux-gnueabihf"
)

# Print configuration
message(STATUS "CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_C_COMPILER: ${CMAKE_C_COMPILER}")
message(STATUS "CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_SYSROOT: ${CMAKE_SYSROOT}")
message(STATUS "CMAKE_FIND_ROOT_PATH: ${CMAKE_FIND_ROOT_PATH}")
message(STATUS "INSTALL_RPATH: $<TARGET_PROPERTY:${PROJECT_NAME},INSTALL_RPATH>")
