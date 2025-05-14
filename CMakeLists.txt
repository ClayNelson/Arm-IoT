cmake_minimum_required(VERSION 3.15)
project(Arm-IoT VERSION 1.0.0 LANGUAGES C ASM)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add CMSIS
include(FetchContent)
FetchContent_Declare(
    cmsis
    GIT_REPOSITORY https://github.com/ARM-software/CMSIS_5.git
    GIT_TAG        5.9.0
)
FetchContent_MakeAvailable(cmsis)

# Add executable
add_executable(${PROJECT_NAME}
    src/main.c
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${cmsis_SOURCE_DIR}/CMSIS/Core/Include
    ${cmsis_SOURCE_DIR}/CMSIS/Driver/Include
    ${cmsis_SOURCE_DIR}/CMSIS/RTOS2/Include
)

# Compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-m55 --specs=nosys.specs")

