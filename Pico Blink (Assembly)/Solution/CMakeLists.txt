cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(blink_asm)

pico_sdk_init()

add_executable(blink_asm
    main.S
)

pico_add_extra_outputs(blink_asm)

target_link_libraries(blink_asm
    pico_stdlib
    hardware_gpio
)
