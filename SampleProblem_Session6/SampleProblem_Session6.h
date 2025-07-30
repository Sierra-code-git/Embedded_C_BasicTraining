#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>

void GPIO_init(void);
void LED_on(void);
void LED_off(void);
void LED_toggle(void);

#endif
