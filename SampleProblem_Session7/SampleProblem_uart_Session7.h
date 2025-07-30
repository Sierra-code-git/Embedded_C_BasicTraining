#ifndef UART_H
#define UART_H

void UART_Init(uint16_t baud);
void UART_SendChar(char c);
void UART_SendString(const char* str);

#endif
