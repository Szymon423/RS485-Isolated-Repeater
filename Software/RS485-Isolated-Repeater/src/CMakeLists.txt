# Znajdź wszystkie pliki źródłowe w katalogu src
file(GLOB SOURCES
    "*.cpp"
    "*.hpp"
    "*.h"
)

# Utwórz bibliotekę z plików w katalogu src
add_library(repeater_lib STATIC
    ${SOURCES}
)

# Linkuj bibliotekę z Pico SDK
target_link_libraries(repeater_lib 
    pico_stdlib
    hardware_gpio
    hardware_timer
    hardware_clocks
    hardware_watchdog
    hardware_irq
)

# Dodaj katalog src jako katalog include dla biblioteki
target_include_directories(repeater_lib PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)