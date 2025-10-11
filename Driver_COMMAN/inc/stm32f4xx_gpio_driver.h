/*
 * stm32f4xx_gpio_driver.h
 *
 *  Created on: Sep 12, 2025
 *      Author: nisha
 */

#ifndef INC_STM32F4XX_GPIO_DRIVER_H_
#define INC_STM32F4XX_GPIO_DRIVER_H_
#include"stm32f407xx.h"
#include<stdio.h>
#include<stdint.h>

typedef struct {
	uint8_t Gpio_Pin_Number;
	uint8_t Gpio_Pin_Mode;
	uint8_t Gpio_Pin_Speed;
	uint8_t Gpio_Pin_PUPDcontrl;
	uint8_t Gpio_Pin_Optype;
	uint8_t Gpio_Pin_AltfnMode;

}Gpio_Pin_Config_t;

typedef struct {
	uint32_t Moder;
	uint32_t Otyper;
	uint32_t Ospeedr;
	uint32_t Pupdr;
	uint32_t Idr;
	uint32_t Odr;
	uint32_t Bsrr;
	uint32_t Lckr;
	uint32_t Afr[2];

}Gpio_Reg_Def;
typedef struct {
	Gpio_Reg_Def *pGPIOX;
	Gpio_Pin_Config_t Gpio_Pin_Config;
}Gpio_Handle_t;

 void Periph_Clk_Control(Gpio_Reg_Def *Gpiox,uint8_t EnorDI);
 void Gpio_Init(Gpio_Handle_t *Gpiox_Handle);
 void Gpio_Dinit(Gpio_Reg_Def *Gpiox);
 uint8_t Gpio_Read_Pin(Gpio_Reg_Def *Gpiox,uint8_t pin_number);
 uint16_t Gpio_Read_Port(Gpio_Reg_Def *Gpiox);
 void Gpio_Write_Pin(Gpio_Reg_Def *Gpiox,uint8_t pin_number,uint8_t EnorDi);
 void Gpio_Write_Port(Gpio_Reg_Def *Gpiox,uint16_t Value);
 void Gpio_Toggle_Pin(Gpio_Reg_Def *Gpiox,uint8_t pin_number);
 void Gpio_Irq_Config(uint8_t Irq_No,uint8_t Priority,uint8_t EnorDi);
 void Gpio_Irq_Handling(uint8_t pin_number);

#define GPIO_MODE_OP 0
#define GPIO_MODE_IP 1
#define GPIO_MODE_ATFN 2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE_IT_FT 3
#define GPIO_MODE_IT_RT 3
#define GPIO_MODE_IT_RFT 3

#define OTYPER_PUPL 0
#define OTYPER_OD 1

#define NO_PUPDR 0
#define PU 1
#define PD 2


#define LOW_SPEED 0
#define MED_SPEED 1
#define HIGH_SPEED 2
#define VERYHIGH_SPEED 3

#define GPIO_PIN_0 0
#define GPIO_PIN_1 1
#define GPIO_PIN_2 2
#define GPIO_PIN_3 3
#define GPIO_PIN_4 4
#define GPIO_PIN_5 5
#define GPIO_PIN_6 6
#define GPIO_PIN_7 7
#define GPIO_PIN_8 8
#define GPIO_PIN_9 9
#define GPIO_PIN_10 10
#define GPIO_PIN_11 11
#define GPIO_PIN_12 12
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_15 15

#endif /* INC_STM32F4XX_GPIO_DRIVER_H_ */
