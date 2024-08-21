
#include "stm32f446xx.h"
#include "GPIO.h"

static void GPIO_LedConfig();

int main(void)
{

	GPIO_LedConfig();

	GPIO_Write_Pin(GPIOB, GPIO_PIN_14 | GPIO_PIN_7, GPIO_Pin_Set);

	for(;;);

}

static void GPIO_LedConfig()
{
	GPIO_InitTypeDef_t GPIO_LedStruct = { 0} ;

	RCC_GPIOB_CLK_ENABLE(); // Clock is active

	GPIO_LedStruct.pinNumber = GPIO_PIN_14 | GPIO_PIN_7;
	GPIO_LedStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_LedStruct.Speed = GPIO_SPEED_LOW;
	GPIO_LedStruct.Otype = GPIO_OTYPE_PP;
	GPIO_LedStruct.PuPd = GPIO_PUPD_NOPULL;

	GPIO_Init(GPIOB, &GPIO_LedStruct); //CONFİG

}
