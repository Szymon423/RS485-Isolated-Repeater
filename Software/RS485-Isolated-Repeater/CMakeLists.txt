# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(RS485-Isolated-Repeater C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add src catalog directory
add_subdirectory(src)

# Add executable.
add_executable(RS485-Isolated-Repeater main.cpp )

pico_set_program_name(RS485-Isolated-Repeater "RS485-Isolated-Repeater")
pico_set_program_version(RS485-Isolated-Repeater "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(RS485-Isolated-Repeater 0)
pico_enable_stdio_usb(RS485-Isolated-Repeater 1)

# Add the standard library to the build
target_link_libraries(RS485-Isolated-Repeater
    pico_stdlib
    repeater_lib
    hardware_gpio
    hardware_timer
    hardware_clocks
    hardware_watchdog
    hardware_irq
)

# Add the standard include files to the build
target_include_directories(RS485-Isolated-Repeater PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${PROJECT_SOURCE_DIR}/src
)

# Add any user requested libraries
target_link_libraries(RS485-Isolated-Repeater 
    hardware_watchdog
)

pico_add_extra_outputs(RS485-Isolated-Repeater)