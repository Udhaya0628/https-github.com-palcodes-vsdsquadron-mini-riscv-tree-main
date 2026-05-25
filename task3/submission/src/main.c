#include <ch32v00x.h>
#include <debug.h>
#include "uart_driver.h"

#define LED_PORT GPIOD
#define LED_PIN GPIO_Pin_6

void led_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure = {0};

    GPIO_InitStructure.GPIO_Pin = LED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(LED_PORT, &GPIO_InitStructure);
}

void led_on(void)
{
    GPIO_SetBits(LED_PORT, LED_PIN);
}

void led_off(void)
{
    GPIO_ResetBits(LED_PORT, LED_PIN);
}

void led_toggle(void)
{
    if(GPIO_ReadOutputDataBit(LED_PORT, LED_PIN))
    {
        led_off();
    }
    else
    {
        led_on();
    }
}

void print_menu(void)
{
    uart_driver_send_string("\r\n===== TASK 3 UART DRIVER DEMO =====\r\n");
    uart_driver_send_string("1 -> LED ON\r\n");
    uart_driver_send_string("0 -> LED OFF\r\n");
    uart_driver_send_string("t -> LED TOGGLE\r\n");
    uart_driver_send_string("h -> HELP MENU\r\n");
    uart_driver_send_string("Enter command: ");
}

int main(void)
{
    SystemCoreClockUpdate();
    Delay_Init();

    uart_driver_init(115200);

    led_init();

    uart_driver_send_string("\r\nTask 3 Started Successfully\r\n");

    print_menu();

    while(1)
    {
        if(uart_driver_char_available())
        {
            char cmd;

            cmd = uart_driver_receive_char();

            uart_driver_send_string("\r\nReceived: ");
            uart_driver_send_char(cmd);
            uart_driver_send_string("\r\n");

            if(cmd == '1')
            {
                led_on();
                uart_driver_send_string("Action: LED ON\r\n");
            }
            else if(cmd == '0')
            {
                led_off();
                uart_driver_send_string("Action: LED OFF\r\n");
            }
            else if(cmd == 't')
            {
                led_toggle();
                uart_driver_send_string("Action: LED TOGGLED\r\n");
            }
            else if(cmd == 'h')
            {
                print_menu();
            }
            else
            {
                uart_driver_send_string("Invalid command\r\n");
            }

            uart_driver_send_string("Enter command: ");
        }
    }
}