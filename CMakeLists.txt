cmake_minimum_required(VERSION 3.12)
project(blink C)

# Set the C compiler
set(CMAKE_C_COMPILER arm-none-eabi-gcc)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# CPU flags
set(CPU_FLAGS "-march=armv8-m.main -mthumb -mfloat-abi=soft")

# Compiler flags
add_compile_options(
    -ffunction-sections
    -fdata-sections
    -Wall
    -g3
    -ffreestanding
    -fno-builtin
)

# Source files
set(SOURCES
    src/main.c
    src/startup.c
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Set linker flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CPU_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_SOURCE_DIR}/gcc_arm.ld -nostartfiles -nodefaultlibs -nostdlib -Wl,--gc-sections -Wl,-Map=${PROJECT_NAME}.map ${CPU_FLAGS}")
