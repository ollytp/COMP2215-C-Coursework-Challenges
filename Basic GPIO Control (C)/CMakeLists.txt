cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(led_toggle_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(led_toggle
    skeleton.c
)

pico_enable_stdio_usb(led_toggle 1)
pico_enable_stdio_uart(led_toggle 0)

target_link_libraries(led_toggle
        pico_stdlib
        )

pico_add_extra_outputs(led_toggle)

