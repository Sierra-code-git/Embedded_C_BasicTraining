#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "sensor.h"
#include "uart.h"

int main(void) {
    LED_Init();
    ADC_Init();
    UART_Init(9600);

    while (1) {
        LED_Toggle();
        _delay_ms(500);

        float temp = Read_Temperature();
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "Temp: %.2f C\r\n", temp);
        UART_SendString(buffer);
    }
}
