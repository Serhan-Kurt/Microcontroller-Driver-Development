
#include "GPIO.h"

/**
  * @brief GPIO_INIT, Configures the port and pin
  * @param GPIOx = GPIO Port Base Address
  *
  * @param GPIO_InitTypeDef_t = User Config Structre
  *
  *
  *	@retval Void
  */

void GPIO_Init(GPIO_TypeDef_t *GPIOx, GPIO_InitTypeDef_t *GPIO_ConfigStruct)
{
	uint32_t position;
	uint32_t fakePosition;
	uint32_t lastPosition;

	for(position = 0; position <16; position++)
	{

		fakePosition = (0x1U << position);
		lastPosition = (uint32_t)(GPIO_ConfigStruct->pinNumber) & fakePosition;

		if(fakePosition == lastPosition)
		{

			/* MODE CONFİG */

			uint32_t tempValue = GPIOx->MODER;

			tempValue &= ~(0x3U << (position*2) );
			tempValue |=  (GPIO_ConfigStruct->Mode << (position*2) );

			GPIOx->MODER = tempValue;

			if(GPIO_ConfigStruct->Mode == GPIO_MODE_OUTPUT || GPIO_ConfigStruct->Mode == GPIO_MODE_AF )
			{
				/* OUTPUT CONFİG */
				tempValue = GPIOx->OTYPER;
				tempValue &= ~(0X1U << position);
				tempValue |= (GPIO_ConfigStruct->Otype << position);
				GPIOx->OTYPER = tempValue;

				/* SPEED CONFİG */
				tempValue = GPIOx->OSPEEDER;
				tempValue &= ~(0x3U << (position*2) );
				tempValue |=  (GPIO_ConfigStruct->Speed << (position*2) );
				GPIOx->OSPEEDER = tempValue;
			}

			/* Push Pull CONFİG */
			tempValue = GPIOx->PUPDR;
			tempValue &= ~(0x3U << (position*2) );
			tempValue |=  (GPIO_ConfigStruct->PuPd << (position*2) );
			GPIOx->PUPDR = tempValue;
		}
	}
}


/**
  * @brief GPIO_Write_Pin, makes pin High or Low
  * @param GPIOx = GPIO Port Base Address
  *
  * @param pinNumber = GPIO Pin Numbers 0 - 15
  *
  * @param pinState = GPIO_Pin_Set OR GPIO_Pin_Reset
  *
  *	@retval Void
  */

void GPIO_Write_Pin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState)
{

	if (pinState == GPIO_Pin_Set)
	{
		GPIOx->BSRR = pinNumber;
	}
	else
	{
		GPIOx->BSRR = (pinNumber << 16u);
	}

}

/**
  * @brief GPIO_Read_Pin, reads the pin of GPIOx Port
  * @param GPIOx = GPIO Port Base Address
  *
  * @param pinNumber = GPIO Pin Numbers 0 - 15
  *
  *
  *
  *	@retval GPIO_PinState_t
  */
GPIO_PinState_t GPIO_Read_Pin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{
	GPIO_PinState_t bitStatus = GPIO_Pin_Reset;

	if ( (GPIOx ->IDR & pinNumber)  != GPIO_Pin_Reset )
	{
		bitStatus = GPIO_Pin_Set;
	}

	return bitStatus;
}

/**
  * @brief GPIO_LockPin , locks the pin of GPIOx Port
  * @param GPIOx = GPIO Port Base Address
  *
  * @param pinNumber = GPIO Pin Numbers 0 - 15
  *
  *
  *
  *	@retval void
  */
void GPIO_LockPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{
		uint32_t tempValue = (0x1U << 16U) | pinNumber;

		GPIOx->LCKR = tempValue;	//LCKR[16] = "1"	LCKRR[15:0] = DATA
		GPIOx->LCKR = pinNumber;	//LCKR[16] = "0"	LCKRR[15:0] = DATA
		GPIOx->LCKR = tempValue;	//LCKR[16] = "1"	LCKRR[15:0] = DATA
		tempValue = GPIOx->LCKR;		// Read Lock Register

}

