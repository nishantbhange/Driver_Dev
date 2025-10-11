/*
 * stm32f407xx.h
 *
 *  Created on: Sep 7, 2025
 *      Author: nisha
 */

#ifndef STM32F407XX_H_
#define STM32F407XX_H_
#include<stdint.h>
#include<stddef.h>

#define __vo volatile
#define __weak  __attribute__((weak))


#define NVIC_ISER0 ((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1 ((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2 ((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3 ((__vo uint32_t*)0xE000E10c)

#define NVIC_ICER0 ((__vo uint32_t*)0XE000E180)
#define NVIC_ICER1 ((__vo uint32_t*)0XE000E184)
#define NVIC_ICER2 ((__vo uint32_t*)0XE000E188)
#define NVIC_ICER3 ((__vo uint32_t*)0XE000E18c)

#define NVIC_IPR_BASE ((__vo uint32_t*)0xE000E400)
#define NVIC_ICPR_BASE ((__vo uint32_t*)0XE000E280)

#define IRQ_NO_1 1
#define IRQ_NO_2 2
#define IRQ_NO_3 3
#define IRQ_NO_4 4
#define IRQ_NO_5 5
#define IRQ_NO_6 6
#define IRQ_NO_7 7
#define IRQ_NO_8 8
#define IRQ_NO_9 9
#define IRQ_NO_10 10
#define IRQ_NO_11 11
#define IRQ_NO_12 12
#define IRQ_NO_13 13
#define IRQ_NO_14 14
#define IRQ_NO_15 15
#define IRQ_NO_16 16
#define IRQ_NO_17 17
#define IRQ_NO_18 18
#define IRQ_NO_19 19
#define IRQ_NO_20 20
#define IRQ_NO_21 21
#define IRQ_NO_22 22
#define IRQ_NO_23 23
#define IRQ_NO_40 40
#define IRQ_NO_35 35
#define IRQ_NO_36 36
#define IRQ_NO_51 51




#define IRQ_NO_EXTI0 IRQ_NO_6
#define IRQ_NO_EXTI1 IRQ_NO_7
#define IRQ_NO_EXTI2 IRQ_NO_8
#define IRQ_NO_EXTI3 IRQ_NO_9
#define IRQ_NO_EXTI4 IRQ_NO_10
#define IRQ_NO_EXTI5_9 IRQ_NO_23
#define IRQ_NO_EXTI15_10  IRQ_NO_40

#define IRQ_NO_SPI1 IRQ_NO_35
#define IRQ_NO_SPI2 IRQ_NO_36
#define IRQ_NO_SPI3 IRQ_NO_51


#define BITS_ENABLE_FOR_PRIORITY 4




#define SRAM_BASE 0x20000000U
#define SRAM1_SIZE 112*1024
#define SRAM2_BASE (SRAM_BASE+SRAM1_SIZE)
#define FLASH_BASE 0x08000000U
#define ROM_BASE 0x1FFF0000U
#define OTP_BASE  0x1FFF7800U

#define AHB1_BASE  0x40020000U
#define AHB2_BASE  0x50000000U
#define APB1_BASE  0x40000000U
#define APB2_BASE  0x40010000U

//AHB1 peripherals

#define GPIOA_BASE (AHB1_BASE+0x00)
#define GPIOB_BASE (AHB1_BASE+0x400)
#define GPIOC_BASE (AHB1_BASE+0x800)
#define GPIOD_BASE (AHB1_BASE+0xC00)
#define GPIOE_BASE (AHB1_BASE+0x1000)
#define GPIOF_BASE (AHB1_BASE+0x1400)
#define GPIOG_BASE (AHB1_BASE+0x1800)
#define GPIOH_BASE (AHB1_BASE+0x1C00)
#define GPIOI_BASE (AHB1_BASE+0x2000)
#define GPIOJ_BASE (AHB1_BASE+0x2400)
#define GPIOK_BASE (AHB1_BASE+0x2800)

#define CRC_BASE (AHB1_BASE+0x3000)
#define RCC_BASE (AHB1_BASE+0x3800)
#define FLASH_INTERFACE_REGISTER_BASE (AHB1_BASE+0x3C00)
#define BKPSRAM_BASE (AHB1_BASE+0x4000)
#define DMA1_BASE (AHB1_BASE+0x6000)
#define DMA2_BASE (AHB1_BASE+0x6400)
#define ETHERNET_MAC_BASE (AHB1_BASE+0x8000)
#define DMA2D_BASE (AHB1_BASE+0xB000)
#define USBOTG_HS_BASE (AHB1_BASE+0x20000)

//APB1 peripherals
#define SPI2_BASE (APB1_BASE+0x3800)
#define SPI3_BASE (APB1_BASE+0x3C00)
#define USART2_BASE (APB1_BASE+0x4400)
#define USART3_BASE (APB1_BASE+0x4800)
#define UART4_BASE (APB1_BASE+0x4C00)
#define UART5_BASE (APB1_BASE+0x5000)
#define I2C1_BASE (APB1_BASE+0x5400)
#define I2C2_BASE (APB1_BASE+0x5800)
#define I2C3_BASE (APB1_BASE+0x5C00)
#define USART7_BASE (APB1_BASE+0x7800)
#define USART8_BASE (APB1_BASE+0x7C00)

//APB2 peripherals

#define USART1_BASE (APB2_BASE+0x1000)
#define USART6_BASE (APB2_BASE+0x1400)
#define SPI1_BASE (APB2_BASE+0x3000)
#define SPI4_BASE (APB2_BASE+0x3400)
#define SYSCONFIG_BASE (APB2_BASE+0x3800)
#define EXTI_BASE (APB2_BASE+0x3C00)
#define SPI5_BASE (APB2_BASE+0x5000)
#define SPI6_BASE (APB2_BASE+0x5400)



typedef struct{
	uint32_t RCC_CR;
	uint32_t RCC_PLLCFGR;
	uint32_t RCC_CFGR;
	uint32_t RCC_CIR;
	uint32_t RCC_AHBRSTR[3];
	uint32_t Reserved;
	uint32_t RCC_APBRSTR[2];
	uint32_t Reserved4[2];
	uint32_t RCC_AHBENR[3];
	uint32_t Reserved1;
	uint32_t RCC_APBENR[2];
	uint32_t Reserved5[2];
	uint32_t RCC_AHBLPENR[3];
	uint32_t Reserved2;
	uint32_t RCC_APBLPENR[2];
	uint32_t Reserved6[2];
	uint32_t RCC_BDCR;
	uint32_t RCC_CSR;
	uint32_t Reserved3[2];
	uint32_t RCC_SSCGR;
	uint32_t RCC_PLLI2SCFGR;
	uint32_t  RCC_PLLSAICFGR;
	uint32_t RCC_DCKCFGR;


}Rcc_Reg_Def;

typedef struct{
	uint32_t EXTI_IMR;
	uint32_t EXTI_EMR;
	uint32_t EXTI_RTSR;
	uint32_t EXTI_FTSR;
	uint32_t EXTI_SWIER;
	uint32_t EXTI_PR;

}Exti_Reg_Def;


typedef struct{
 uint32_t SYSCFG_MEMRMP;
 uint32_t SYSCFG_PMC;
 uint32_t SYSCFG_EXTICR[4];
 uint32_t SYSCFG_CMPCR;

}Sysconfig_Reg_Def;

#define GPIOA  (Gpio_Reg_Def*)GPIOA_BASE
#define GPIOB  (Gpio_Reg_Def*)GPIOB_BASE
#define GPIOC  (Gpio_Reg_Def*)GPIOC_BASE
#define GPIOD  (Gpio_Reg_Def*)GPIOD_BASE
#define GPIOE  (Gpio_Reg_Def*)GPIOE_BASE
#define GPIOF  (Gpio_Reg_Def*)GPIOF_BASE
#define GPIOG  (Gpio_Reg_Def*)GPIOG_BASE
#define GPIOH  (Gpio_Reg_Def*)GPIOH_BASE
#define GPIOI  (Gpio_Reg_Def*)GPIOI_BASE
#define GPIOJ  (Gpio_Reg_Def*)GPIOJ_BASE
#define GPIOK  (Gpio_Reg_Def*)GPIOK_BASE


#define SPI1   (Spi_Reg_Def*)SPI1_BASE
#define SPI2   (Spi_Reg_Def*)SPI2_BASE
#define SPI3   (Spi_Reg_Def*)SPI3_BASE



#define RCC   ((Rcc_Reg_Def*)RCC_BASE)
#define EXTI   ((Exti_Reg_Def*)EXTI_BASE)
#define SYSCFG   ((Sysconfig_Reg_Def*)SYSCONFIG_BASE)


#define SYSCONFIG_PLCK_EN() (RCC->RCC_APBENR[1] |=(1<<14))



#define GPIOA_PCKL_EN()   (RCC->RCC_AHBENR[0] |=(1<<0))
#define GPIOB_PCKL_EN()  (RCC->RCC_AHBENR[0] |=(1<<1))
#define GPIOC_PCKL_EN()  (RCC->RCC_AHBENR[0] |=(1<<2))
#define GPIOD_PCKL_EN()  (RCC->RCC_AHBENR[0] |=(1<<3))
#define GPIOE_PCKL_EN()  (RCC->RCC_AHBENR[0] |=(1<<4))
#define GPIOF_PCKL_EN()  (RCC->RCC_AHBENR[0] |=(1<<5))
#define GPIOG_PCKL_EN()  (RCC->RCC_AHBENR[0] |=(1<<6))
#define GPIOH_PCKL_EN()  (RCC->RCC_AHBENR[0] |=(1<<7))
#define GPIOI_PCKL_EN()  (RCC->RCC_AHBENR[0] |=(1<<8))


#define USART1_PCLK_EN() (RCC->RCC_APBENR[1] |=(1<<4))
#define USART2_PCLK_EN() (RCC->RCC_APBENR[0] |=(1<<17))
#define USART3_PCLK_EN() (RCC->RCC_APBENR[0] |=(1<<18))
#define UART4_PCLK_EN() (RCC->RCC_APBENR[0] |=(1<<19))
#define UART5_PCLK_EN() (RCC->RCC_APBENR[0] |=(1<<20))
#define USART6_PCLK_EN() (RCC->RCC_APBENR[1] |=(1<<5))

#define SPI1_PCLK_EN() (RCC->RCC_APBENR[1] |=(1<<12))
#define SPI2_PCLK_EN() (RCC->RCC_APBENR[0] |=(1<<14))
#define SPI3_PCLK_EN() (RCC->RCC_APBENR[0] |=(1<<15))

#define SPI1_PCLK_DI() (RCC->RCC_APBENR[1] &=!(1<<12))
#define SPI2_PCLK_DI() (RCC->RCC_APBENR[0] &=!(1<<14))
#define SPI3_PCLK_DI() (RCC->RCC_APBENR[0] &=!(1<<15))


#define I2C1_PCLK_EN() (RCC->RCC_APBENR[0] |=(1<<21));
#define I2C2_PCLK_EN() (RCC->RCC_APBENR[0] |=(1<<22));
#define I2C3_PCLK_EN() (RCC->RCC_APBENR[0] |=(1<<23));



#define SET 1
#define RESET 0
#define Enable 1
#define Disable 0
#define GpioPinSET 1
#define  GpioPinRESET 0

#include"stm32f4xx_gpio_driver.h"
#include"stm32f40xx_spi_driver.h"



#endif /* STM32F407XX_H_ */
