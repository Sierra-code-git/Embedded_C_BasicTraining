#include <avr/io.h>
#include "sensor.h"

void ADC_Init(void) {
    ADMUX = (1 << REFS0); // AVCC reference
    ADCSRA = (1 << ADEN) | (1 << ADPS2); // Enable ADC, prescaler 16
}

uint16_t ADC_Read(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); // Select channel
    ADCSRA |= (1 << ADSC); // Start conversion
    while (ADCSRA & (1 << ADSC)); // Wait
    return ADC;
}

float Read_Temperature(void) {
    uint16_t adc_val = ADC_Read(0); // LM35 on channel 0
    return (adc_val * 5.0 / 1024.0) * 100.0; // Convert to °C
}
