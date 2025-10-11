#include<stdio.h>
#include<stdint.h>
#include<stm32f407xx.h>

void delay(void ){
	for(int i=0;i<100000;i++);
}

int main(){

	Gpio_Handle_t GPIO;
	GPIO.pGPIOX=GPIOA;
	GPIO.Gpio_Pin_Config.Gpio_Pin_Mode=GPIO_MODE_IT_FT;
	GPIO.Gpio_Pin_Config.Gpio_Pin_Number=GPIO_PIN_0;
	GPIO.Gpio_Pin_Config.Gpio_Pin_Optype=GPIO_OTYPER_PUPL;
	GPIO.Gpio_Pin_Config.Gpio_Pin_PUPDcontrl=GPIO_NO_PUPDR;
	GPIO.Gpio_Pin_Config.Gpio_Pin_Speed=GPIO_HIGH_SPEED;
    Gpio_Init(&GPIO);

        GPIO.pGPIOX=GPIOD;
    	GPIO.Gpio_Pin_Config.Gpio_Pin_Mode=GPIO_MODE_OP;
    	GPIO.Gpio_Pin_Config.Gpio_Pin_Number=GPIO_PIN_12;
        Gpio_Init(&GPIO);

        Gpio_Irq_Config(IRQ_NO_EXTI0, 2, Enable);

   while(1){}

	return 0;
}

void EXTI0_IRQHandler(void){
	Gpio_Irq_Handling(GPIO_PIN_0);
	Gpio_Toggle_Pin(GPIOD, GPIO_PIN_12);

}
