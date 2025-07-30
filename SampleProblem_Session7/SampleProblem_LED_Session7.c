#include <avr/io.h>
#include "led.h"

#define LED_PIN PB0

void LED_Init(void) {
    DDRB |= (1 << LED_PIN);  // Set PB0 as output
}

void LED_Toggle(void) {
    PORTB ^= (1 << LED_PIN); // Toggle PB0
}

void LED_On(void) {
    PORTB |= (1 << LED_PIN); // Set PB0 HIGH
}

void LED_Off(void) {
    PORTB &= ~(1 << LED_PIN); // Set PB0 LOW
}
