/*
 * Embedded C Program Demonstrating Fundamental Concepts
 * Includes: Header inclusion, source structure, libraries, interfaces,
 * expressions, scope, operators, loops, conditionals, and data types.
 */

#include <avr/io.h>
#include <util/delay.h>

// Function prototype
void toggle_led(void);
int calculate_sum(int a, int b);
float compute_voltage(int adc_value);

int main(void) {
    // Data types and variable declarations
    int counter = 0;
    float voltage = 0.0;
    char status = 'N';

    // Set PB0 as output (LED), PB1 as input (Button)
    DDRB |= (1 << PB0);      // Output
    DDRB &= ~(1 << PB1);     // Input

    while (1) {
        // Conditional statement
        if (PINB & (1 << PB1)) {
            toggle_led();    // Function call
            counter++;       // Expression and operator
            status = 'Y';
        } else if (counter > 10) {
            PORTB &= ~(1 << PB0); // Turn off LED
            status = 'L';
        } else {
            status = 'N';
        }

        // Compute voltage from ADC value (simulated)
        voltage = compute_voltage(counter);

        _delay_ms(500);      // Loop delay
    }

    return 0;
}

// Function to toggle LED
void toggle_led(void) {
    PORTB ^= (1 << PB0);     // Bitwise XOR to toggle
}

// Function to calculate sum
int calculate_sum(int a, int b) {
    return a + b;            // Arithmetic operator
}

// Function to compute voltage from ADC value
float compute_voltage(int adc_value) {
    return (adc_value / 1024.0) * 5.0; // Expression with float
}
