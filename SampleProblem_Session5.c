/*Here’s an Embedded C example for power-efficient interrupt management using an ATmega328P microcontroller. 
This code puts the MCU into power-down sleep mode and wakes it up using an external interrupt (e.g., button press on INT0).*/

//Embedded C Code: Sleep and Wake-Up via Interrupt
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

#define LED_PIN PB0

// Interrupt Service Routine for INT0
ISR(INT0_vect) {
    // Wake-up logic: toggle LED
    PORTB ^= (1 << LED_PIN);
}

void setup_interrupt() {
    DDRB |= (1 << LED_PIN);     // Set LED pin as output
    PORTB &= ~(1 << LED_PIN);   // Turn off LED initially

    DDRD &= ~(1 << PD2);        // INT0 (PD2) as input
    PORTD |= (1 << PD2);        // Enable pull-up resistor

    EIMSK |= (1 << INT0);       // Enable INT0
    EICRA |= (1 << ISC01);      // Trigger on falling edge
    sei();                      // Enable global interrupts
}

int main(void) {
    setup_interrupt();

    while (1) {
        // Prepare for sleep
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        sleep_cpu();            // MCU sleeps until INT0 interrupt

        // MCU wakes up here after interrupt
        sleep_disable();        // Disable sleep to avoid accidental re-entry

        _delay_ms(500);         // Optional delay to debounce or visualize LED
    }
}
