#include "gpio.hpp"
#include "definitions.hpp"
#include "hardware/gpio.h"

namespace GPIO {
    void Initialize() {
        // Initialize Isolated RS485 pins
        gpio_init(Definitions::RS485RxIsolatedPin);                 
        gpio_init(Definitions::RS485TxIsolatedPin);
        gpio_init(Definitions::RS485DirIsolatedPin);
        gpio_set_dir(Definitions::RS485RxIsolatedPin, GPIO_IN);
        gpio_set_dir(Definitions::RS485TxIsolatedPin, GPIO_OUT);
        gpio_set_dir(Definitions::RS485DirIsolatedPin, GPIO_OUT);
        
        // Initialize Non isolated RS485 pins
        gpio_init(Definitions::RS485RxPin);                 
        gpio_init(Definitions::RS485TxPin);
        gpio_init(Definitions::RS485DirPin);
        gpio_set_dir(Definitions::RS485RxPin, GPIO_IN);
        gpio_set_dir(Definitions::RS485TxPin, GPIO_OUT);
        gpio_set_dir(Definitions::RS485DirPin, GPIO_OUT);

        // Initialize LED pins
        gpio_init(Definitions::LedErrorPin);
        gpio_init(Definitions::LedToIsolatedPin);
        gpio_init(Definitions::LedFromIsolatedPin);
        gpio_set_dir(Definitions::LedErrorPin, GPIO_OUT);
        gpio_set_dir(Definitions::LedToIsolatedPin, GPIO_OUT);
        gpio_set_dir(Definitions::LedFromIsolatedPin, GPIO_OUT);
    }
}