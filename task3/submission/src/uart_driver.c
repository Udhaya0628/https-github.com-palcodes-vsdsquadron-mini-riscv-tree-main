#include <ch32v00x.h>
#include <debug.h>
#include "uart_driver.h"

void uart_driver_init(uint32_t baudrate)
{
    USART_Printf_Init(baudrate);
}

void uart_driver_send_char(char ch)
{
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);

    USART_SendData(USART1, ch);
}

void uart_driver_send_string(const char *str)
{
    while(*str)
    {
        uart_driver_send_char(*str++);
    }
}

char uart_driver_receive_char(void)
{
    while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

    return USART_ReceiveData(USART1);
}

int uart_driver_char_available(void)
{
    return USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET;
}