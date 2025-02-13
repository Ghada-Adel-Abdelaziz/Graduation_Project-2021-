/*
 * stm32f4xx.h
 *
 *  Created on: Dec 30, 2020
 *      Author: Ghada & Toaa
 */

#ifndef STM32F4XXX_H_
#define STM32F4XXX_H_



#include <stdint.h>

#define __vol volatile

//ARM cortex M4 processor NVIC ISERx register address

//ISER interrupt enable register base address
#define NVIC_ISER0    ((__vol uint32_t*)0xE000E100)
#define NVIC_ISER1    ((__vol uint32_t*)0xE000E104)
#define NVIC_ISER2    ((__vol uint32_t*)0xE000E108)
#define NVIC_ISER3    ((__vol uint32_t*)0xE000E10C)

//ICER interrupt disable register base address
#define NVIC_ICER0    ((__vol uint32_t*)0xE000E180)
#define NVIC_ICER1    ((__vol uint32_t*)0xE000E184)
#define NVIC_ICER2    ((__vol uint32_t*)0xE000E188)
#define NVIC_ICER3    ((__vol uint32_t*)0xE000E18C)

//Interrupt priority register address
#define NVIC_IPR_BASE_ADDR   ((__vol uint32_t*)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED        4

/*base addresses for different memory*/

#define FLASH_BASEADDR   0X08000000U   //start address 112kb flash memory
#define SRAM1_BASEADDR   0X20000000U   //start address 112kb sram1 memory
#define SRAM2_BASEADDR   0X2001C000U   //start address 16kb sram2 memory
#define ROM_BASEADDR     0X1FFF0000U   //start address 30kb system memory

/* APB* AND AHB* peripheral base address */

#define APB1_PERIADDR    0X40000000U   //apb1 peripheral base address
#define APB2_PERIADDR    0X40010000U   //apb2 peripheral base address
#define AHB1_PERIADDR    0X40020000U   //ahb1 peripheral base address
#define AHB2_PERIADDR    0X50000000U   //ahb2 peripheral base address
#define AHB3_PERIADDR    0XA0000000U   //ahb3 peripheral base address

/* base address for all GPIO pins FROM A TO I */

#define GPIO_A_ADDR (AHB1_PERIADDR + 0X0000)
#define GPIO_B_ADDR (AHB1_PERIADDR + 0X0400)
#define GPIO_C_ADDR (AHB1_PERIADDR + 0X0800)
#define GPIO_D_ADDR (AHB1_PERIADDR + 0X0C00)
#define GPIO_E_ADDR (AHB1_PERIADDR + 0X1000)
#define GPIO_F_ADDR (AHB1_PERIADDR + 0X1400)
#define GPIO_G_ADDR (AHB1_PERIADDR + 0X1800)
#define GPIO_H_ADDR (AHB1_PERIADDR + 0X1C00)
#define GPIO_I_ADDR (AHB1_PERIADDR + 0X2000)

/* RCC base address */

#define RCC_BASEADDR (AHB1_PERIADDR + 0X3800)

/* Peripherals for APB1 bus */

#define TIM2_ADDR (APB1_PERIADDR + 0X0000)
#define TIM3_ADDR (APB1_PERIADDR + 0X0400)
#define TIM4_ADDR (APB1_PERIADDR + 0X0800)
#define TIM5_ADDR (APB1_PERIADDR + 0X0C00)
#define TIM6_ADDR (APB1_PERIADDR + 0X1000)
#define TIM7_ADDR (APB1_PERIADDR + 0X1400)
#define TIM12_ADDR (APB1_PERIADDR + 0X1800)
#define TIM13_ADDR (APB1_PERIADDR + 0X1C00)
#define TIM14_ADDR (APB1_PERIADDR + 0X2000)

#define RTC_BKP_ADDR  (APB1_PERIADDR + 0X2800)
#define WWDG_ADDR (APB1_PERIADDR + 0X2C00)
#define IWDG_ADDR (APB1_PERIADDR + 0X3000)
#define I2S2EXT_ADDR (APB1_PERIADDR + 0X3400)

#define SPI2_ADDR (APB1_PERIADDR + 0X3800)
#define SPI3_ADDR (APB1_PERIADDR + 0X3C00)

#define I2S3EXT_ADDR (APB1_PERIADDR + 0X4000)

#define USART2_ADDR (APB1_PERIADDR + 0X4400)
#define USART3_ADDR (APB1_PERIADDR + 0X4800)
#define USART4_ADDR (APB1_PERIADDR + 0X4C00)
#define USART5_ADDR (APB1_PERIADDR + 0X5000)

#define I2C1_ADDR (APB1_PERIADDR + 0X5400)
#define I2C2_ADDR (APB1_PERIADDR + 0X5800)
#define I2C3_ADDR (APB1_PERIADDR + 0X5C00)

#define CAN1_ADDR (APB1_PERIADDR + 0X6400)
#define CAN2_ADDR (APB1_PERIADDR + 0X6800)

#define PWR_ADDR (APB1_PERIADDR + 0X7000)

#define DAC_ADDR (APB1_PERIADDR + 0X7400)

#define UART7_ADDR (APB1_PERIADDR + 0X7800)
#define UART8_ADDR (APB1_PERIADDR + 0X7C00)

/* Peripheral for APB2 bus */

#define TIM1_ADDR (APB2_PERIADDR + 0X0000)
#define TIM8_ADDR (APB2_PERIADDR + 0X0400)

#define USART1_ADDR (APB2_PERIADDR + 0X1000)
#define USART6_ADDR (APB2_PERIADDR + 0X1400)

#define ADC123_ADDR (APB2_PERIADDR + 0X2000)

#define SDIO_ADDR (APB2_PERIADDR + 0X2C00)

#define SPI1_ADDR (APB2_PERIADDR + 0X3000)
#define SPI4_ADDR (APB2_PERIADDR + 0X3400)

#define SYSCFG_ADDR (APB2_PERIADDR + 0X3800)

#define EXTI_ADDR (APB2_PERIADDR + 0X3C00)

#define TIM9_ADDR (APB2_PERIADDR + 0X4000)
#define TIM10_ADDR (APB2_PERIADDR + 0X4400)
#define TIM11_ADDR (APB2_PERIADDR + 0X4800)

#define SPI5_ADDR (APB2_PERIADDR + 0X5000)
#define SPI6_ADDR (APB2_PERIADDR + 0X5400)

#define SAI1_ADDR (APB2_PERIADDR + 0X5800)

#define LCD_TFT_ADDR (APB2_PERIADDR + 0X6800)

/*
//SPI1 REGISTER BASE ADDRESS
#define SPI_CR1 (SPI1_ADDR + 0X00)
#define SPI_CR2 (SPI1_ADDR + 0X04)
#define SPI_SR  (SPI1_ADDR + 0X08)
#define SPI_DR  (SPI1_ADDR + 0x0C)
#define SPI_CRCPR (SPI1_ADDR + 0X10)
#define SPI_RXCRCR (SPI1_ADDR + 0x14)
#define SPI_TXCRCR (SPI1_ADDR + 0x18)
#define SPI_I2SCFGR (SPI1_ADDR + 0X1C)
#define SPI_I2SPR (SPI1_ADDR + 0x20)
*/

/*GPIO peripheral structure definition*/



typedef struct
{
	__vol uint32_t MODER;               //GPIO port mode register
	__vol uint32_t OTYPER;              //GPIO port output type register
	__vol uint32_t OSPEEDR;             //GPIO port output speed register
	__vol uint32_t PUPDR;               //GPIO port pull-up/pull-down register
	__vol uint32_t IDR;                 //GPIO port input data register
	__vol uint32_t ODR;                 //GPIO port output data register
	__vol uint32_t BSRR;                //GPIO port bit set/reset register
	__vol uint32_t LCKR;                //GPIO port configuration lock register
	__vol uint32_t AFR[2];              //AFR[0] :GPIO alternate function low register AFR[1] :GPIO alternate function high register
}GPIO_regdef_t;


/*RCC peripheral structure definition*/

typedef struct
{
	__vol uint32_t CR;                     //RCC clock control register
	__vol uint32_t PLLCFGR;                //RCC PLL configuration register
	__vol uint32_t CFGR;                   //RCC clock configuration register
	__vol uint32_t CIR;                    //RCC clock interrupt register
	__vol uint32_t AHB1RSTR;               //RCC AHB1 peripheral reset register
	__vol uint32_t AHB2RSTR;               //RCC AHB2 peripheral reset register
	__vol uint32_t AHB3RSTR;               //RCC AHB3 peripheral reset register
	uint32_t reserved1;
	__vol uint32_t APB1RSTR;               //RCC APB1 peripheral reset register
	__vol uint32_t APB2RSTR;               //RCC APB2 peripheral reset register
	uint32_t reserved2[2];
	__vol uint32_t AHB1ENR;                //RCC AHB1 peripheral clock enable register
	__vol uint32_t AHB2ENR;                //RCC AHB2 peripheral clock enable register
	__vol uint32_t AHB3ENR;                //RCC AHB3 peripheral clock enable register
	uint32_t reserved3;
	__vol uint32_t APB1ENR;                //RCC APB1 peripheral clock enable register
	__vol uint32_t APB2ENR;                //RCC APB2 peripheral clock enable register
	uint32_t reserved4[2];
	__vol uint32_t AHB1LPENR;               //RCC AHB1 peripheral clock enable in low power mode register
	__vol uint32_t AHB2LPENR;               //RCC AHB2 peripheral clock enable in low power mode register
	__vol uint32_t AHB3LPENR;               //RCC AHB3 peripheral clock enable in low power mode register
	uint32_t reserved5;
	__vol uint32_t APB1LPENR;               //RCC APB1 peripheral clock enable in low power mode register
	__vol uint32_t APB2LPENR;               //RCC APB2 peripheral clock enabled in low power mode
	uint32_t reserved6[2];
	__vol uint32_t BDCR;                    //RCC Backup domain control register
	__vol uint32_t CSR;                     //RCC clock control & status register
	uint32_t reserved7[2];
	__vol uint32_t SSCGR;                   //RCC spread spectrum clock generation register
	__vol uint32_t PLLI2SCFGR;              //RCC PLLI2S configuration register
}RCC_regdef_t;


//peripheral structure definition for EXTI

typedef struct
{
	__vol uint32_t IMR;
	__vol uint32_t EMR;
	__vol uint32_t RTSR;
	__vol uint32_t FTSR;
	__vol uint32_t SWIER;
	__vol uint32_t PR;
}EXTI_regdef_t;

//peripheral structure definition for

typedef struct
{
	__vol uint32_t MEMRMP;
	__vol uint32_t PMC;
	__vol uint32_t EXTICR[4];
	 uint32_t RESERVED1[2];
	__vol uint32_t CMPCR;
	 uint32_t RESERVED2[2];
	__vol uint32_t CFGR;
}SYSCFG_regdef_t;

//SPI peripheral structure definition

typedef struct
{
	__vol uint32_t SPI_CR1;
	__vol uint32_t SPI_CR2;
	__vol uint32_t SPI_SR;
	__vol uint32_t SPI_DR;
	__vol uint32_t SPI_CPCPR;
	__vol uint32_t SPI_RXCRCR;
	__vol uint32_t SPI_TXCRCR;
	__vol uint32_t SPI_I2SCFGR;
	__vol uint32_t SPI_I2SPR;
}SPI_RegDef_t;

/*
 * UART peripheral structure definition
 */

typedef struct
{
	__vol uint32_t USART_SR;
	__vol uint32_t USART_DR;
	__vol uint32_t USART_BRR;
	__vol uint32_t USART_CR1;
	__vol uint32_t USART_CR2;
	__vol uint32_t USART_CR3;
	__vol uint32_t USART_GTPR;
}USART_RegDef_t;

/*GPIO defintion */

#define GPIOA    ((GPIO_regdef_t*)GPIO_A_ADDR)
#define GPIOB    ((GPIO_regdef_t*)GPIO_B_ADDR)
#define GPIOC    ((GPIO_regdef_t*)GPIO_C_ADDR)
#define GPIOD    ((GPIO_regdef_t*)GPIO_D_ADDR)
#define GPIOE    ((GPIO_regdef_t*)GPIO_E_ADDR)
#define GPIOF    ((GPIO_regdef_t*)GPIO_F_ADDR)
#define GPIOG    ((GPIO_regdef_t*)GPIO_G_ADDR)
#define GPIOH    ((GPIO_regdef_t*)GPIO_H_ADDR)
#define GPIOI    ((GPIO_regdef_t*)GPIO_I_ADDR)

/* SPI definition */

#define SPI1    ((SPI_RegDef_t*)SPI1_ADDR)
#define SPI2    ((SPI_RegDef_t*)SPI2_ADDR)
#define SPI3    ((SPI_RegDef_t*)SPI3_ADDR)

/* USART definition */

#define USART1  ((USART_RegDef_t*)USART1_ADDR)
#define USART2  ((USART_RegDef_t*)USART2_ADDR)
#define USART3  ((USART_RegDef_t*)USART3_ADDR)
#define USART4  ((USART_RegDef_t*)USART4_ADDR)
#define USART5  ((USART_RegDef_t*)USART5_ADDR)
#define USART6  ((USART_RegDef_t*)USART6_ADDR)


/*RCC DEFINITION*/

#define RCC     ((RCC_regdef_t*)RCC_BASEADDR)

//EXTI DEFINITION
#define EXTI   ((EXTI_regdef_t*)EXTI_ADDR)

//system configuration definition
#define SYSCFG  ((SYSCFG_regdef_t*)SYSCFG_ADDR)

//GPIO clock enable macro
#define GPIOA_PCLK_EN  (RCC -> AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN  (RCC -> AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN  (RCC -> AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN  (RCC -> AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN  (RCC -> AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN  (RCC -> AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN  (RCC -> AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN  (RCC -> AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN  (RCC -> AHB1ENR |= (1 << 8))


/************* NEW *********************/
#define GPIO_PCLK_EN   RCC->AHB1ENR
#define NUM_OF_GPIO		9
/***************************************/


//GPIO clock disable macro
#define GPIOA_PCLK_DI  (RCC -> AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI  (RCC -> AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI  (RCC -> AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI  (RCC -> AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI  (RCC -> AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI  (RCC -> AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI  (RCC -> AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI  (RCC -> AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI  (RCC -> AHB1ENR &= ~(1 << 8))

/*I2C peripheral clock enable MACRO (3 I2C)
#define I2C1_PCLK_EN  (RCC -> APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN  (RCC -> APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN  (RCC -> APB1ENR |= (1 << 23))
*/
/*I2C peripheral clock disable macros

#define I2C1_PCLK_DI  (RCC -> APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI  (RCC -> APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI  (RCC -> APB1ENR &= ~(1 << 23))
*/

//UART peripheral clock enable MACRO (4 USART / 2 UART)
#define USART1_PCLK_EN  (RCC -> APB2ENR |= (1 << 4))
#define USART2_PCLK_EN  (RCC -> APB1ENR |= (1 << 17))
#define USART3_PCLK_EN  (RCC -> APB1ENR |= (1 << 18))
#define USART4_PCLK_EN  (RCC -> APB1ENR |= (1 << 19))
#define USART5_PCLK_EN  (RCC -> APB1ENR |= (1 << 20))
#define USART6_PCLK_EN  (RCC -> APB2ENR |= (1 << 5))


/*************** NEW **************************/

#define NUM_OF_UART		6
#define USART_PCLK_EN   RCC -> APB2ENR

/**********************************************/


//UART peripheral clock DISABLE MACRO
#define USART1_PCLK_DI  (RCC -> APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI  (RCC -> APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI  (RCC -> APB1ENR &= ~(1 << 18))
#define USART4_PCLK_DI  (RCC -> APB1ENR &= ~(1 << 19))
#define USART5_PCLK_DI  (RCC -> APB1ENR &= ~(1 << 20))
#define USART6_PCLK_DI  (RCC -> APB2ENR &= ~(1 << 5))


//SPI peripheral clock enable macro
#define SPI1_PCLK_EN   (RCC -> APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN   (RCC -> APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN   (RCC -> APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN   (RCC -> APB2ENR |= (1 << 13))  //DOUBT ABOUT ADDRESS


//SPI PERIPHERAL CLOCK DISABLE MACRO
#define SPI1_PCLK_DI   (RCC -> APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI   (RCC -> APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI   (RCC -> APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI   (RCC -> APB2ENR &= ~(1 << 13))  //DOUBT ABOUT ADDRESS

//Bit position macro for SPI register

//SPI control register 1

#define SPI_CR1_CPHA  0
#define SPI_CR1_CPOL  1
#define SPI_CR1_MSTR  2
#define SPI_CR1_BR    3
#define SPI_CR1_SPE   6
#define SPI_CR1_LSBFIRST  7
#define SPI_CR1_SSI   8
#define SPI_CR1_SSM   9
#define SPI_CR1_RXONLY  10
#define SPI_CR1_DFF   11
#define SPI_CR1_CRCNEXT  12
#define SPI_CR1_CRCEN  13
#define SPI_CR1_BIDIOE  14
#define SPI_CR1_BIDIMODE  15

//SPI control register 2

#define SPI_CR2_RXDMAEN  0
#define SPI_CR2_TXDMAEN  1
#define SPI_CR2_SSOE     2
#define SPI_CR2_FRF      4
#define SPI_CR2_ERRIE    5
#define SPI_CR2_RXNEIE   6
#define SPI_CR2_TXEIE    7

//SPI status register

#define SPI_SR_RXNE    0
#define SPI_SR_TXE     1
#define SPI_SR_CHSIDE  2
#define SPI_SR_UDR     3
#define SPI_SR_CRCERR  4
#define SPI_SR_MODF  5
#define SPI_SR_OVR   6
#define SPI_SR_BSY   7
#define SPI_SR_FRE   8


//Bit position macro for USART status register

#define USART_SR_PE    0
#define USART_SR_FE    1
#define USART_SR_NF    2
#define USART_SR_ORE   3
#define USART_SR_IDLE  4
#define USART_SR_RXNE  5
#define USART_SR_TC    6
#define USART_SR_TXE   7
#define USART_SR_LBD   8
#define USART_SR_CTS   9

//Bit position macro for USART control register 1,2,3

#define USART_CR1_SBK     0
#define USART_CR1_RWU     1
#define USART_CR1_RE      2
#define USART_CR1_TE      3
#define USART_CR1_IDLEIE  4
#define USART_CR1_RXNEIE  5
#define USART_CR1_TCIE    6
#define USART_CR1_TXEIE   7
#define USART_CR1_PEIE    8
#define USART_CR1_PS      9
#define USART_CR1_PCE    10
#define USART_CR1_WAKE   11
#define USART_CR1_M    	 12
#define USART_CR1_UE     13
#define USART_CR1_OVER8  15

#define USART_CR2_ADD     0
#define USART_CR2_LBDL    5
#define USART_CR2_LBDIE   6
#define USART_CR2_LBCL    8
#define USART_CR2_CPHA    9
#define USART_CR2_CPOL    10
#define USART_CR2_CLKEN   11
#define USART_CR2_STOP    12
#define USART_CR2_LINEN   14

#define USART_CR3_EIE      0
#define USART_CR3_IREN     1
#define USART_CR3_IRLP     2
#define USART_CR3_HDSEL    3
#define USART_CR3_NACK     4
#define USART_CR3_SCEN     5
#define USART_CR3_DMAR     6
#define USART_CR3_DMAT     7
#define USART_CR3_RTSE     8
#define USART_CR3_CTSE     9
#define USART_CR3_CTSIE    10
#define USART_CR3_ONEBIT   11

//sysCFG PERIPHERAL CLOCK ENABLE MACRO
#define SYSCFG_PCLK_EN  (RCC->APB2ENR  |= (1 << 14))

//sysCFG PERIPHERAL CLOCK DISABLE MACRO
#define SYSCFG_PCLK_DI  (RCC -> APB2ENR &= ~(1 << 14))

//Macro to reset GPIO peripherals
#define GPIOA_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0));  }while(0)
#define GPIOB_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1));  }while(0)
#define GPIOC_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2));  }while(0)
#define GPIOD_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3));  }while(0)
#define GPIOE_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4));  }while(0)
#define GPIOF_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5));  }while(0)
#define GPIOG_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6));  }while(0)
#define GPIOH_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7));  }while(0)
#define GPIOI_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8));  }while(0)


/****************** NEW ******************************/

#define GPIO_RESET_REG   RCC->AHB1RSTR

/*******************************************************/


#define GPIO_BASEADDR_TO_CODE(x) ((x == GPIOA)?0:\
		                          (x == GPIOB)?1:\
		                          (x == GPIOC)?2:\
		                          (x == GPIOB)?3:\
		                          (x == GPIOA)?4:\
		                          (x == GPIOB)?5:\
		                          (x == GPIOA)?6:\
		                          (x == GPIOB)?7:0 )

//IRQ Number for stm32f407xx MCU

#define IRQ_NO_EXTI0    6
#define IRQ_NO_EXTI1    7
#define IRQ_NO_EXTI2    8
#define IRQ_NO_EXTI3    9
#define IRQ_NO_EXTI4    10
#define IRQ_NO_EXTI9_5  23
#define IRQ_NO_EXTI15_10  40


//Generic macros
#define ENABLE   1
#define DISABLE  0
#define SET   ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET  SET
#define GPIO_PIN_RESET  RESET
#define FLAG_SET    SET
#define FLAG_RESET  RESET


#include "GPIO.h"
#include "UART_Driver.h"
#include "RCC_Driver.h"


#endif /* STM32F4XXX_H_ */
