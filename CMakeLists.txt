cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME DiPan)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
include_directories(
    Core/Inc
    Hardware
    System
    User
)
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    Hardware/IMU.c
    Core/Src/main.c
    # Core/Inc headers
    Core/Inc/usart.h
    Core/Inc/tim.h
    Core/Inc/stm32f4xx_it.h
    Core/Inc/stm32f4xx_hal_conf.h
    Core/Inc/main.h
    Core/Inc/gpio.h
    Core/Inc/dma.h
    Core/Inc/can.h
    # Hardware headers
    Hardware/MyI2C.h
    Hardware/MPU6050_Reg.h
    Hardware/MPU6050.h
    Hardware/IMU.h
    Hardware/Timer.h
    Hardware/OLED_Font.h
    Hardware/OLED.h
    # System headers
    System/Delay.h
    # User headers
    User/dvc_serialplot.h
    User/dvc_motor.h
    User/drv_uart.h
    User/drv_motion.h
    User/drv_math.h
    User/drv_communication.h
    User/drv_can.h
    User/drv_bsp.h
    User/drv_act.h
    User/alg_pid.h
)
    # Core/Src sources
    Core/Src/usart.c
    Core/Src/tim.c
    Core/Src/system_stm32f4xx.c
    Core/Src/sysmem.c
    Core/Src/syscalls.c
    Core/Src/stm32f4xx_it.c
    Core/Src/stm32f4xx_hal_msp.c
    Core/Src/main.c
    Core/Src/gpio.c
    Core/Src/dma.c
    Core/Src/can.c
    # Hardware sources
    Hardware/Timer.c
    Hardware/OLED.c
    Hardware/MyI2C.c
    Hardware/MPU6050.c
    Hardware/IMU.c
    # System sources
    System/Delay.c
    # User sources
    User/drv_uart.c
    User/drv_motion.c
    User/drv_communication.c
    User/drv_can.c
    User/drv_bsp.c
    User/drv_act.c

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
