cmake_minimum_required(VERSION 3.15)
project(blink VERSION 1.0.0 LANGUAGES C ASM)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/startup.c
    src/main.c
)

# CPU-specific flags
set(CPU_FLAGS
    -mcpu=cortex-m55
    -mthumb
    -mfloat-abi=soft
)

# Compiler flags
add_compile_options(
    ${CPU_FLAGS}
    --specs=nosys.specs
    -ffunction-sections
    -fdata-sections
    -Wall
    -g3
)

# Linker flags
add_link_options(
    ${CPU_FLAGS}
    --specs=nosys.specs
    -nostartfiles
    -nodefaultlibs
    -nostdlib
    -Wl,--gc-sections
    -Wl,-Map=${PROJECT_NAME}.map
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Set linker script
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/gcc_arm.ld)
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})
target_link_options(${PROJECT_NAME} PRIVATE -T ${LINKER_SCRIPT})

