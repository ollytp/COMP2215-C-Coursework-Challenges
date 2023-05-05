#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

#define LED_PIN_BASE 0
#define LED_PIN_COUNT 29
#define BUTTON_PIN 20
#define BEEP_PIN 18
#define BEEP_FREQ 1000

void init_pwm(int pin, int freq, float duty) {
    // Set up PWM on specified pin
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_clkdiv(slice_num, 125.0f);
    pwm_set_wrap(slice_num, 1.0f / freq);
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(pin), duty);
    pwm_set_enabled(slice_num, true);
}

void beep(int duration_ms) {
    // Play a beep sound for the specified duration
    int slice_num = pwm_gpio_to_slice_num(BEEP_PIN);
    pwm_set_enabled(slice_num, true);
    sleep_ms(duration_ms);
    pwm_set_enabled(slice_num, false);
}

int main()
{
    stdio_init_all();

    // Set up LED pins
    for (int i = LED_PIN_BASE; i < LED_PIN_BASE + LED_PIN_COUNT; i++) {
        gpio_init(i);
        gpio_set_dir(i, GPIO_OUT);
    }

    // Set up button pin
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    // Set up beep pin
    init_pwm(BEEP_PIN, BEEP_FREQ, 0.5f);

    bool leds_on = false;

    // write your code here


    }

    return 0;
}
