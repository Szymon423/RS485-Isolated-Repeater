#include "rs485.hpp"
#include "hardware/gpio.h"
#include "definitions.hpp"

// Initialize static members
volatile RS485::State RS485::m_state = RS485::State::RecieveOnly;
volatile uint64_t RS485::m_last_change_time = to_us_since_boot(get_absolute_time());

void RS485::Initialize() {
    SetState(RS485::State::RecieveOnly);
}

RS485::State RS485::GetState() {
    return static_cast<State>(m_state);
}

void RS485::SetState(const RS485::State state) {
    m_state = state;
    switch (state) {
        case RS485::State::RecieveOnly: {
            gpio_put(Definitions::RS485DirPin, false);
            gpio_put(Definitions::RS485DirIsolatedPin, false);
            break;
        }
        case RS485::State::TransmitIsolated: {
            gpio_put(Definitions::RS485DirPin, false);
            gpio_put(Definitions::RS485DirIsolatedPin, true);
            break;
        }
        case RS485::State::TransmitNonIsolated: {
            gpio_put(Definitions::RS485DirPin, true);
            gpio_put(Definitions::RS485DirIsolatedPin, false);
            break;
        }
        default: {
            gpio_put(Definitions::RS485DirPin, false);
            gpio_put(Definitions::RS485DirIsolatedPin, false);
            break;
        }
    }
}

void RS485::SetTx(RS485::Bus bus, bool state) {
    m_last_change_time = to_us_since_boot(get_absolute_time());
    switch (bus) {
        case RS485::Bus::Isolated: {
            gpio_put(Definitions::RS485TxIsolatedPin, state);
            break;
        }
        case RS485::Bus::NonIsolated: {
            gpio_put(Definitions::RS485TxPin, state);
            break;
        }
        default: {
            // TODO: handle error
            break;
        }
    }
}