#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include <stdint.h>

void uart_driver_init(uint32_t baudrate);

void uart_driver_send_char(char ch);

void uart_driver_send_string(const char *str);

char uart_driver_receive_char(void);

int uart_driver_char_available(void);

#endif