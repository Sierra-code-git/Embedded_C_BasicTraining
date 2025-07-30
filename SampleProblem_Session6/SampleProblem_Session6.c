#include "gpio.h"

#define LED_PIN PB0

void GPIO_init(void) {
    DDRB |= (1 << LED_PIN);  // Set LED pin as output
}

void LED_on(void) {
    PORTB |= (1 << LED_PIN); // Set LED pin high
}

void LED_off(void) {
    PORTB &= ~(1 << LED_PIN); // Set LED pin low
}

void LED_toggle(void) {
    PORTB ^= (1 << LED_PIN); // Toggle LED pin
}
