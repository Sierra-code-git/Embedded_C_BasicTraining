/*Here’s a starter code template in Embedded C for your Light-Sensitive Motor Control System using an ATmega328P microcontroller.
 This template includes ADC for LDR, PWM for motor control, button input with debounce, and I2C LCD display setup.*/

//Starter Code Template
#include <avr/io.h>
#include <util/delay.h>
#include "lcd_i2c.h"  // Include your I2C LCD library

#define BUTTON_PIN PB1
#define MOTOR_PWM_PIN PD6

// Initialize ADC
void ADC_init() {
    ADMUX = (1 << REFS0); // AVcc reference
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // Enable ADC, prescaler 64
}

// Read ADC value
uint16_t ADC_read(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); // Select ADC channel
    ADCSRA |= (1 << ADSC); // Start conversion
    while (ADCSRA & (1 << ADSC));
    return ADC;
}

// Initialize PWM
void PWM_init() {
    DDRD |= (1 << MOTOR_PWM_PIN); // Set PWM pin as output
    TCCR0A = (1 << COM0A1) | (1 << WGM00) | (1 << WGM01); // Fast PWM, non-inverting
    TCCR0B = (1 << CS01); // Prescaler 8
}

// Set PWM duty cycle
void set_motor_speed(uint8_t speed) {
    OCR0A = speed;
}

// Debounce button
uint8_t is_button_pressed() {
    if (!(PINB & (1 << BUTTON_PIN))) {
        _delay_ms(50);
        if (!(PINB & (1 << BUTTON_PIN))) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    DDRB &= ~(1 << BUTTON_PIN); // Button as input
    PORTB |= (1 << BUTTON_PIN); // Enable pull-up

    ADC_init();
    PWM_init();
    lcd_init(); // Initialize I2C LCD
    lcd_clear();

    uint8_t motor_on = 0;

    while (1) {
        if (is_button_pressed()) {
            motor_on = !motor_on;
            lcd_clear();
            lcd_set_cursor(0, 0);
            lcd_print(motor_on ? "Motor: ON" : "Motor: OFF");
            _delay_ms(500); // Prevent multiple toggles
        }

        if (motor_on) {
            uint16_t light = ADC_read(0); // Read LDR on ADC0
            uint8_t speed = light / 4;    // Scale 10-bit to 8-bit
            set_motor_speed(speed);

            lcd_set_cursor(1, 0);
            lcd_print("Speed: ");
            lcd_print_int(speed);
        } else {
            set_motor_speed(0); // Turn off motor
        }

        _delay_ms(100);
    }
}
