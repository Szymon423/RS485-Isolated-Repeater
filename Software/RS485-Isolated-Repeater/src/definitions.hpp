#pragma once
#include <pico/stdlib.h>

/// @brief Namespace for all definitions
namespace Definitions {
    // Define pins for isolated RS485 interface
    constexpr uint8_t RS485RxIsolatedPin = 0;
    constexpr uint8_t RS485TxIsolatedPin = 1;
    constexpr uint8_t RS485DirIsolatedPin = 2;

    // Define pins for non isolated RS485 interface
    constexpr uint8_t RS485RxPin = 5;
    constexpr uint8_t RS485TxPin = 6;
    constexpr uint8_t RS485DirPin = 7;

    // Define pins for LEDs
    constexpr uint8_t LedToIsolatedPin = 10;
    constexpr uint8_t LedFromIsolatedPin = 11;
    constexpr uint8_t LedErrorPin = 12 ;
}