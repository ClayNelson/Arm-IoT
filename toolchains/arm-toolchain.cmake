set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Specify the cross compiler with full paths
set(CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabihf-g++)

# Set the target system root and search paths
set(CMAKE_FIND_ROOT_PATH /usr/arm-linux-gnueabihf)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Set ARM architecture and FPU flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=armv8-a -mfloat-abi=hard -mfpu=neon-fp-armv8")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=armv8-a -mfloat-abi=hard -mfpu=neon-fp-armv8")

# Set linker flags to ensure consistent FPU usage
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -march=armv8-a -mfloat-abi=hard -mfpu=neon-fp-armv8")
