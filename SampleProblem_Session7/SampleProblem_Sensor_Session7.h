#ifndef SENSOR_H
#define SENSOR_H

void ADC_Init(void);
uint16_t ADC_Read(uint8_t channel);
float Read_Temperature(void);

#endif
