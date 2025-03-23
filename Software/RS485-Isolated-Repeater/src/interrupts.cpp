#include "interrupts.hpp"
#include "definitions.hpp"
#include "rs485.hpp"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"

namespace Interrupts {
    void Initialize() {
        // Set handler for interrupts
        gpio_set_irq_callback(RxHandler);

        // Set pins which rises IRQ (Rx on rising and falling edges) 
        gpio_set_irq_enabled(Definitions::RS485RxPin, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true);
        gpio_set_irq_enabled(Definitions::RS485RxIsolatedPin, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true);
    }

    void RxHandler(uint gpio, uint32_t events) {
        if (gpio == Definitions::RS485RxPin) {
            // Rising edge
            if (events & GPIO_IRQ_EDGE_RISE) {
                if (RS485::GetState() == RS485::State::TransmitIsolated) {
                    RS485::SetTx(RS485::Bus::Isolated, true);
                }
                else {
                    // TODO: Handle error
                }
            }
            // Falling edge
            else if (events & GPIO_IRQ_EDGE_FALL) {
                // If we are in recieve on both buses, switch to transmit on isolated bus
                if (RS485::GetState() == RS485::State::RecieveOnly) {
                    RS485::SetState(RS485::State::TransmitIsolated);
                }
                else if (RS485::GetState() == RS485::State::TransmitIsolated) {
                    RS485::SetTx(RS485::Bus::Isolated, false);
                }
                else {
                    // TODO: Handle error
                }
            }
        }
        else if (gpio == Definitions::RS485RxIsolatedPin) {
            // Rising edge
            if (events & GPIO_IRQ_EDGE_RISE) {
                if (RS485::GetState() == RS485::State::TransmitNonIsolated) {
                    RS485::SetTx(RS485::Bus::NonIsolated, true);
                }
                else {
                    // TODO: Handle error
                }
            }
            // Falling edge
            else if (events & GPIO_IRQ_EDGE_FALL) {
                // If we are in recieve on both buses, switch to transmit on non-isolated bus
                if (RS485::GetState() == RS485::State::RecieveOnly) {
                    RS485::SetState(RS485::State::TransmitNonIsolated);
                }
                else if (RS485::GetState() == RS485::State::TransmitNonIsolated) {
                    RS485::SetTx(RS485::Bus::NonIsolated, false);
                }
                else {
                    // TODO: Handle error
                }
            }
        }
    }
}