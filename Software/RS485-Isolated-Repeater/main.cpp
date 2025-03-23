#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/watchdog.h"
#include "definitions.hpp"
#include "interrupts.hpp"
#include "gpio.hpp"
#include "rs485.hpp"

int main() {
    // Initialize the stdio system
    stdio_init_all();

    // Actions needed when reboot was caused by the watchdog
    if (watchdog_caused_reboot()) {
        // Do I need to make something here?
    }

    // Initlize the GPIO pins
    GPIO::Initialize();

    // Initialize interrupts
    Interrupts::Initialize();

    // Initialize RS485
    RS485::Initialize();

    // Enable the watchdog, requiring the watchdog to be updated every 100ms or the chip will reboot
    // TODO: second arg is pause on debug which means the watchdog will pause when stepping through code
    watchdog_enable(100, 1);
    
    // You need to call this function at least more often than the 100ms in the enable call to prevent a reboot
    watchdog_update();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
