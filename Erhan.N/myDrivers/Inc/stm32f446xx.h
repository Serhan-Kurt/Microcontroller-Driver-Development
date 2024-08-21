
#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>


#define __IO volatile

#define SET_BIT(REG , BIT)		((REG) |=  (BIT))
#define CLEAR_BIT(REG , BIT)	((REG) &= ~(BIT))
#define READ_BIT(REG , BIT)		((REG) &   (BIT))
#define UNUSED(x)				(void)x

/*
 * 	Memory Base Address
 *
 */

#define FLASH_BASE_ADDR 		(0x08000000UL) /*Flash base address (up to 1MB) */
#define SRAM1_BASE_ADDR			(0x20000000UL) /*SRAM1 base address 128KB*/
#define SRAM2_BASE_ADDR			(0x2001C000UL) /*SRAM2 base address 16KB*/


/*
 * 	Peripheral Base Addresses
 *
 */

#define PERIPH_BASE_ADDR		(0x40000000UL)  					/*Base address for All Peripheral */

#define APB1_BASE_ADDR			(0x40000000UL)                       /* APB1 Bus domain base address    */
#define APB2_BASE_ADDR			(PERIPH_BASE_ADDR +  0x00010000UL)   /* APB2 Bus domain base address    */
#define AHB1_BASE_ADDR			(PERIPH_BASE_ADDR +  0x00020000UL)   /* AHB1 Bus domain base address    */
#define AHB2_BASE_ADDR			(PERIPH_BASE_ADDR +  0x10000000UL)   /* AHB2 Bus domain base address    */


/*
 * 	APB1 Base Addresses
 *
 */

#define TIM2_BASE_ADDR			(APB1_BASE_ADDR + 0x0000UL)			 /*   Timer 2 Base Address          */
#define TIM3_BASE_ADDR			(APB1_BASE_ADDR + 0x0400UL)			 /*   Timer 3 Base Address          */
#define TIM4_BASE_ADDR			(APB1_BASE_ADDR + 0x0800UL)			 /*   Timer 3 Base Address          */

#define SPI2_BASE_ADDR			(APB1_BASE_ADDR + 0x3800UL)			 /*   SPI 2 Base Address            */
#define SPI3_BASE_ADDR			(APB1_BASE_ADDR + 0x3C00UL)			 /*   SPI 3 Base Address            */

#define USART2_BASE_ADDR		(APB1_BASE_ADDR + 0x4400UL)			 /*   USART 2 Base Address          */
#define USART3_BASE_ADDR		(APB1_BASE_ADDR + 0x4800UL)			 /*   USART 3 Base Address          */
#define UART4_BASE_ADDR		    (APB1_BASE_ADDR + 0x4C00UL)	   	     /*   UART 4 Base Address           */
#define UART5_BASE_ADDR			(APB1_BASE_ADDR + 0x5000UL)	         /*   UART 5 Base Address           */

#define I2C1_BASE_ADDR			(APB1_BASE_ADDR + 0x5400UL)			 /*   I2C 1  Base Address           */
#define I2C2_BASE_ADDR			(APB1_BASE_ADDR + 0x5800UL)			 /*   I2C 2  Base Address           */
#define I2C3_BASE_ADDR			(APB1_BASE_ADDR + 0x5C00UL)			 /*   I2C 3  Base Address           */



/*
 * 	APB2 Base Addresses
 *
 */

#define TIM1_BASE_ADDR			(APB2_BASE_ADDR + 0x0000UL)			/*   Timer 1 Base Address           */
#define TIM8_BASE_ADDR			(APB2_BASE_ADDR + 0x0400UL)			/*   Timer 8 Base Address           */

#define USART1_BASE_ADDR		(APB2_BASE_ADDR + 0x1000UL)		    /*   USART 1 Base Address           */
#define USART6_BASE_ADDR		(APB2_BASE_ADDR + 0x1400UL)		    /*   USART 6 Base Address           */

#define SPI1_BASE_ADDR			(APB2_BASE_ADDR + 0x3000UL)			/*   SPI 1 Base Address             */
#define SPI4_BASE_ADDR			(APB2_BASE_ADDR + 0x3400UL)			/*   SPI 4 Base Address             */

#define SYSCFG_BASE_ADDR		(APB2_BASE_ADDR + 0x3800UL)			/*   SYSCFG  Base Address           */

#define EXTI_BASE_ADDR			(APB2_BASE_ADDR + 0x3C00UL)			/*   EXTI  Base Address             */


/*
 * 	AHB1 Base Addresses
 *
 */

#define GPIOA_BASE_ADDR			(AHB1_BASE_ADDR + 0x0000UL)			/*   GPIO A  Base Address 			*/
#define GPIOB_BASE_ADDR			(AHB1_BASE_ADDR + 0x0400UL)			/*   GPIO B  Base Address 			*/
#define GPIOC_BASE_ADDR			(AHB1_BASE_ADDR + 0x0800UL)			/*   GPIO C  Base Address 			*/
#define GPIOD_BASE_ADDR			(AHB1_BASE_ADDR + 0x0C00UL)			/*   GPIO D  Base Address 			*/
#define GPIOE_BASE_ADDR			(AHB1_BASE_ADDR + 0x1000UL)			/*   GPIO E  Base Address 			*/
#define GPIOF_BASE_ADDR			(AHB1_BASE_ADDR + 0x1400UL)			/*   GPIO F  Base Address 			*/
#define GPIOG_BASE_ADDR			(AHB1_BASE_ADDR + 0x1800UL)			/*   GPIO G  Base Address 			*/
#define GPIOH_BASE_ADDR			(AHB1_BASE_ADDR + 0x1C00UL)			/*   GPIO H  Base Address 			*/

#define RCC_BASE_ADDR			(AHB1_BASE_ADDR + 0x3800UL)			/*   RCC     Base Address 			*/


/*!
 * 	Peripheral Structure Definitions
 *
 */
 typedef struct
{
	__IO uint32_t MODER;		/*|< GPIO port mode register    			  Address Offset = 0x0000 */
	__IO uint32_t OTYPER;		/*|< GPIO port output type register    		  Address Offset = 0x0004 */
	__IO uint32_t OSPEEDER;		/*|< GPIO port output speed register  	      Address Offset = 0x0008 */
	__IO uint32_t PUPDR;		/*|< GPIO port pull-up/pull-down register     Address Offset = 0x000C */
	__IO uint32_t IDR;			/*|< GPIO port input data register  		  Address Offset = 0x0010 */
	__IO uint32_t ODR;			/*|< GPIO port output data register   		  Address Offset = 0x0014 */
	__IO uint32_t BSRR;			/*|< GPIO port bit set/reset register  	      Address Offset = 0x0018 */
	__IO uint32_t LCKR;			/*|< GGPIO port configuration lock register   Address Offset = 0x001C */
	__IO uint32_t AFR[2];		/*|< GPIO alternate function low register     Address Offset = 0x0020 */

}GPIO_TypeDef_t;

 typedef struct
 {
	 __IO uint32_t CR;					/*|< RCC clock control register   			  							Address Offset = 0x0000 */
	 __IO uint32_t PLLCFGR;				/*|< RCC PLL configuration register  			  						Address Offset = 0x0004 */
	 __IO uint32_t CFGR;				/*|< RCC clock configuration register   			  					Address Offset = 0x0008 */
	 __IO uint32_t CIR;					/*|< RCC clock interrupt register  			 		 					Address Offset = 0x000C */
	 __IO uint32_t AHB1RSTR;			/*|< RCC AHB1 peripheral reset register   			  					Address Offset = 0x0010 */
	 __IO uint32_t AHB2RSTR;			/*|< RCC AHB2 peripheral reset register   			  					Address Offset = 0x0014 */
	 __IO uint32_t AHB3RSTR;			/*|< RCC AHB3 peripheral reset register  			  					Address Offset = 0x0018 */
	 __IO uint32_t RESERVED0;			/*|< RESERVED Area				  			  							Address Offset = 0x001C */
	 __IO uint32_t APB1RSTR;			/*|< RCC APB1 peripheral reset register   			  					Address Offset = 0x0020 */
	 __IO uint32_t APB2RSTR;			/*|< RCC APB2 peripheral reset register   			  					Address Offset = 0x0024 */
	 __IO uint32_t RESERVED1[2];		/*|< RESERVED Area 				  			  							Address Offset = 0x0028 */
	 __IO uint32_t AHB1ENR; 			/*|< RCC AHB1 peripheral clock enable register   			  			Address Offset = 0x0030 */
	 __IO uint32_t AHB2ENR;				/*|< RCC AHB2 peripheral clock enable register  			  			Address Offset = 0x0034 */
	 __IO uint32_t AHB3ENR;				/*|< RCC AHB3 peripheral clock enable register   			  			Address Offset = 0x0038 */
	 __IO uint32_t RESERVED2;			/*|< RESERVED Area				  		  			  					Address Offset = 0x003C */
	 __IO uint32_t APB1ENR;				/*|< RCC APB1 peripheral clock enable register   			  			Address Offset = 0x0040 */
	 __IO uint32_t APB2ENR;				/*|< RCC APB2 peripheral clock enable register   			  			Address Offset = 0x0044 */
	 __IO uint32_t RESERVED3[2];		/*|< RESERVED Area				   			  							Address Offset = 0x0048 */
	 __IO uint32_t AHB1LPENR;			/*|< RCC AHB1 peripheral clock enable in low power mode register   	  	Address Offset = 0x0050 */
	 __IO uint32_t AHB2LPENR;			/*|< RCC AHB2 peripheral clock enable in low power mode register  	  	Address Offset = 0x0054 */
	 __IO uint32_t AHB3LPENR;			/*|< RCC AHB3 peripheral clock enable in low power mode register   		Address Offset = 0x0058 */
	 __IO uint32_t RESERVED4;			/*|< RCC clock control register   			  							Address Offset = 0x006C */
	 __IO uint32_t APB1LPENR;			/*|< RCC APB1 peripheral clock enable in low power mode register   		Address Offset = 0x0060 */
	 __IO uint32_t APB2LPENR;			/*|< RCC APB2 peripheral clock enable in low power mode register  		Address Offset = 0x0064 */
	 __IO uint32_t RESERVED5[2];		/*|< RESERVED Area				   			 			 				Address Offset = 0x0068 */
	 __IO uint32_t BDCR;				/*|< RCC Backup domain control register  			  					Address Offset = 0x0070 */
	 __IO uint32_t CSR;					/*|< RCC clock control & status register  			  					Address Offset = 0x0074 */
	 __IO uint32_t RESERVED6[2];		/*|< RESERVED Area				   			  							Address Offset = 0x0078 */
	 __IO uint32_t SSCGR;				/*|< RCC spread spectrum clock generation register  			  		Address Offset = 0x0080 */
	 __IO uint32_t PLLI2SCFGR;			/*|< RCC PLLI2S configuration register   			  					Address Offset = 0x0084 */
	 __IO uint32_t PLLSAICFGR;			/*|< RCC PLL configuration register   			  						Address Offset = 0x0088 */
	 __IO uint32_t DCKCFGR;				/*|< RCC dedicated clock configuration register   			  			Address Offset = 0x009C */
	 __IO uint32_t CKGATENR;			/*|< RCC clocks gated enable registerRCC clocks gated enable register   Address Offset = 0x0090 */
	 __IO uint32_t DCKCFGR2;			/*|< RCC dedicated clocks configuration register 2    			  		Address Offset = 0x0094 */




 }RCC_TypeDef_t;






#define GPIOA					( (GPIO_TypeDef_t *)(GPIOA_BASE_ADDR) )
#define GPIOB					( (GPIO_TypeDef_t *)(GPIOB_BASE_ADDR) )
#define GPIOC					( (GPIO_TypeDef_t *)(GPIOC_BASE_ADDR) )
#define GPIOD					( (GPIO_TypeDef_t *)(GPIOD_BASE_ADDR) )
#define GPIOE					( (GPIO_TypeDef_t *)(GPIOE_BASE_ADDR) )
#define GPIOF					( (GPIO_TypeDef_t *)(GPIOF_BASE_ADDR) )
#define GPIOG					( (GPIO_TypeDef_t *)(GPIOG_BASE_ADDR) )
#define GPIOH					( (GPIO_TypeDef_t *)(GPIOH_BASE_ADDR) )

#define RCC						( (RCC_TypeDef_t  *)(RCC_BASE_ADDR)   )


 /*
  * 	Bit Definitions
  *
  */


#define RCC_AHB1ENR_GPIOAEN_POS			(0U)									/*RCC AHB1ENR register GPIOAEN Bit Position*/
#define RCC_AHB1ENR_GPIOAEN_MASK		(0x1 << RCC_AHB1ENR_GPIOAEN_POS )		/*RCC AHB1ENR register GPIOAEN Bit Mask*/
#define RCC_AHB1ENR_GPIOAEN				(RCC_AHB1ENR_GPIOAEN_MASK)				/*RCC AHB1ENR register GPIOAEN Macro*/

#define RCC_AHB1ENR_GPIOBEN_POS			(1U)									/*RCC AHB1ENR register GPIOBEN Bit Position*/
#define RCC_AHB1ENR_GPIOBEN_MASK		(0x1 << RCC_AHB1ENR_GPIOBEN_POS )		/*RCC AHB1ENR register GPIOBEN Bit Mask*/
#define RCC_AHB1ENR_GPIOBEN				(RCC_AHB1ENR_GPIOBEN_MASK)				/*RCC AHB1ENR register GPIOBEN Macro*/

#define RCC_AHB1ENR_GPIOCEN_POS			(2U)									/*RCC AHB1ENR register GPIOCEN Bit Position*/
#define RCC_AHB1ENR_GPIOCEN_MASK		(0x1 << RCC_AHB1ENR_GPIOCEN_POS )		/*RCC AHB1ENR register GPIOCEN Bit Mask*/
#define RCC_AHB1ENR_GPIOCEN				(RCC_AHB1ENR_GPIOCEN_MASK)				/*RCC AHB1ENR register GPIOCEN Macro*/

#define RCC_AHB1ENR_GPIODEN_POS			(3U)									/*RCC AHB1ENR register GPIODEN Bit Position*/
#define RCC_AHB1ENR_GPIODEN_MASK		(0x1 << RCC_AHB1ENR_GPIODEN_POS )		/*RCC AHB1ENR register GPIODEN Bit Mask*/
#define RCC_AHB1ENR_GPIODEN				(RCC_AHB1ENR_GPIODEN_MASK)				/*RCC AHB1ENR register GPIODEN Macro*/






#include "RCC.h"

#endif /* INC_STM32F446XX_H_ */
