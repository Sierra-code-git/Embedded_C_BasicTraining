#ifndef SAMPLEPROBLEM_SESSION4_H
#define SAMPLEPROBLEM_SESSION4_H

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

// ADC initialization and reading
void ADC_init(void);
uint16_t ADC_read(uint8_t channel);

// PWM initialization and motor control
void PWM_init(void);
void set_motor_speed(uint8_t speed);

// Button debounce
uint8_t is_button_pressed(void);

// LCD functions (assumed from lcd_i2c.h)
void lcd_init(void);
void lcd_clear(void);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_print(const char* str);
void lcd_print_int(uint8_t value);

#endif // SAMPLEPROBLEM_SESSION4_H
