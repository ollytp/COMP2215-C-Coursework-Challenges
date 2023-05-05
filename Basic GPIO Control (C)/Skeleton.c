#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BUTTON_PIN 20
#define LED_START_PIN 0
#define LED_END_PIN 28

bool led_on = false;

void toggle_leds() {
    // TODO: Toggle the `led_on` variable between true and false.

    // TODO: Set the state of the LED pins (excluding the BUTTON_PIN) based on the `led_on` variable.
}

int main() {
    // TODO: Initialize stdio

    // TODO: Initialize LED pins as output (excluding the BUTTON_PIN)

    // TODO: Initialize BUTTON_PIN as input with a pull-up resistor

    while (true) {
        // TODO: Check the state of BUTTON_PIN and call `toggle_leds()` when it's pressed.
        //       Add a delay to debounce the button.
    }

    return 0;
}
