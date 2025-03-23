#pragma once
#include "pico/stdlib.h"

/// @brief Namespace for interrupt related functions
namespace Interrupts {
    /// @brief Initializes the interrupt controller
    void Initialize();

    /// @brief Function which handle interrupts
    /// @param gpio pin number which caused interrupt
    /// @param events even that caused interrupt
    void RxHandler(uint gpio, uint32_t events);
}