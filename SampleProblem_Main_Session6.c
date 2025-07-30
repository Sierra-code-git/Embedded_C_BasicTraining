/*Here’s a simple Embedded C project that demonstrates a clean project structure and uses a Hardware Abstraction Layer (HAL). 
This example is for an ATmega328P microcontroller (used in Arduino Uno) and focuses on LED control using HAL.

Project Structure
/Embedded_LED_Project
│
├── main.c                  // Application logic
├── hal/
│   ├── gpio.h              // GPIO HAL header
│   └── gpio.c              // GPIO HAL implementation
├── Makefile                // Build configuration
*/

#include <util/delay.h>
#include "hal/gpio.h"

int main(void) {
    GPIO_init();  // Initialize GPIO

    while (1) {
        LED_toggle();     // Toggle LED
        _delay_ms(500);   // Delay
    }
}

