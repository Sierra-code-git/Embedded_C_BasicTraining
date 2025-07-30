#ifndef SAMPLEPROBLEM_SESSION5_H
#define SAMPLEPROBLEM_SESSION5_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

// LED pin definition
#define LED_PIN PB0

// Interrupt setup
void setup_interrupt(void);

#endif // SAMPLEPROBLEM_SESSION5_H
