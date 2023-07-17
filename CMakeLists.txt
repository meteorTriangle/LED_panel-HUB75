cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)
set(PICO_SDK_PATH "${PICO_SDK_PATH}")
set(PICO_BOARD pico CACHE STRING "Board type")

project(HUB75 C CXX ASM)
add_library(HUB75 STATIC src/hub75.cpp)



target_include_directories(HUB75 PRIVATE
    ${PICO_SDK_PATH}
)

pico_sdk_init()

target_include_directories(HUB75 PUBLIC
    ./include
)

target_link_libraries(HUB75
        pico_stdlib
        hardware_gpio
        hardware_timer
        hardware_clocks
        )

add_subdirectory(example)