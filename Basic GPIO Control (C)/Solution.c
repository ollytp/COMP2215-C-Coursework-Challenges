#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BUTTON_PIN 20
#define LED_START_PIN 0
#define LED_END_PIN 28

bool led_on = false;

void toggle_leds() {
    led_on = !led_on;
    for (int pin = LED_START_PIN; pin <= LED_END_PIN; pin++) {
        if (pin != BUTTON_PIN) {
            gpio_put(pin, led_on);
        }
    }
}

int main() {
    stdio_init_all();

    for (int pin = LED_START_PIN; pin <= LED_END_PIN; pin++) {
        if (pin != BUTTON_PIN) {
            gpio_init(pin);
            gpio_set_dir(pin, GPIO_OUT);
        }
    }

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    while (true) {
        if (!gpio_get(BUTTON_PIN)) {
            toggle_leds();
            sleep_ms(500);
        }
    }

    return 0;
}
