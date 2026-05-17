#include <ch32v00x.h>
#include <debug.h>

#define BLINKY_GPIO_PORT GPIOD
#define BLINKY_GPIO_PIN GPIO_Pin_6

int main(void)
{
    SystemCoreClockUpdate();
    Delay_Init();

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure = {0};

    GPIO_InitStructure.GPIO_Pin = BLINKY_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(BLINKY_GPIO_PORT, &GPIO_InitStructure);

    while (1)
    {
        GPIO_WriteBit(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN, Bit_SET);
        Delay_Ms(500);

        GPIO_WriteBit(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN, Bit_RESET);
        Delay_Ms(500);
    }
}