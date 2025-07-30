/*Task: Write a function in Embedded C that:
•	Sets bit 5 of a register.
•	Clears bit 2.
•	Toggles bit 7.
•	Returns 1 if bit 0 is set, else 0.
Here's a simple Embedded C function that performs the operations you described on an 8-bit register:*/
#include <stdint.h>

// Function to manipulate bits in a register
uint8_t manipulate_register(uint8_t reg) {
    reg |= (1 << 5);      // Set bit 5
    reg &= ~(1 << 2);     // Clear bit 2
    reg ^= (1 << 7);      // Toggle bit 7

    // Return 1 if bit 0 is set, else 0
    return (reg & (1 << 0)) ? 1 : 0;
}
