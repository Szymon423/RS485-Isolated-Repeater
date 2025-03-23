#pragma once

/// @brief Class for handling RS485 communication
class RS485 {
public:
    /// @brief Enum with RS485 states
    enum class State : uint8_t {
        RecieveOnly,            // Recieve on both RS485 interfaces
        TransmitIsolated,       // Transmit on isolated, recieve on non-isolated RS485 interface
        TransmitNonIsolated     // Transmit on non-isolated, recieve on isolated RS485 interface
    };

    /// @brief Enum class with RS485 bus types
    enum class Bus : uint8_t {
        Isolated,       // Isolated RS485 interface
        NonIsolated     // Non-isolated RS485 interface
    };

private:
    static volatile State m_state;
    static volatile uint64_t m_last_change_time;

public:
    /// @brief Initialize RS485 communication
    static void Initialize();

    /// @brief Function to get RS485 state
    /// @return RS485 state
    static State GetState();

    /// @brief Function to set RS485 state
    /// @param state state to set
    static void SetState(const State state);

    /// @brief Function to set RS485 Tx state
    /// @param bus bus to set state on
    /// @param state state to set
    static void SetTx(Bus bus, bool state);
};