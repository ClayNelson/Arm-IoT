cmake_minimum_required(VERSION 3.12)
project(blink C)

# Set the C compiler
set(CMAKE_C_COMPILER arm-none-eabi-gcc)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# CPU flags
set(CPU_FLAGS
    -march=armv8.1-m.main
    -mthumb
    -mfloat-abi=soft
)

# Compiler flags
add_compile_options(
    ${CPU_FLAGS}
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

# Set linker script
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/gcc_arm.ld)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Linker flags
target_link_options(${PROJECT_NAME} PRIVATE
    ${CPU_FLAGS}
    -nostartfiles
    -nodefaultlibs
    -nostdlib
    -Wl,--gc-sections
    -Wl,-N
    -Wl,-Map=${PROJECT_NAME}.map
    -T${LINKER_SCRIPT}
)

# Set linker script dependency
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})
