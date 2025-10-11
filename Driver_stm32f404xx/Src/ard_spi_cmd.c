#include<stdio.h>
#include<stdint.h>
#include<stm32f407xx.h>
#include<stm32f40xx_spi_driver.h>
#include<stm32f4xx_gpio_driver.h>
#define CMD_LED_CTRL 0x50
#define CMD_SENSOR_READ 0x51
#define CMD_LED_READ 0x52
#define CMD_PRINT 0x53
#define CMD_ID_READ 0x54
#define CMD_LED_CTRL 0x55

#define LED_ON 1
#define LED_OFF 0

#define ANALOG_PIN_0 0
#define ANALOG_PIN_1 1
#define ANALOG_PIN_2 2
#define ANALOG_PIN_3 3
#define ANALOG_PIN_4 4
#define LED_PIN 9



void Gpio_Pin_Config(Gpio_Handle_t GPIOX){

	GPIOX.Gpio_Pin_Config.Gpio_Pin_Mode=GPIO_MODE_ATFN;
	GPIOX.Gpio_Pin_Config.Gpio_Pin_AltfnMode=5;
	GPIOX.Gpio_Pin_Config.Gpio_Pin_Optype=GPIO_OTYPER_PUPL;
	GPIOX.Gpio_Pin_Config.Gpio_Pin_PUPDcontrl=GPIO_NO_PUPDR;
	GPIOX.Gpio_Pin_Config.Gpio_Pin_Speed=GPIO_HIGH_SPEED;

	GPIOX.Gpio_Pin_Config.Gpio_Pin_Number=GPIO_PIN_12;
	Gpio_Init(&GPIOX);

	GPIOX.Gpio_Pin_Config.Gpio_Pin_Number=GPIO_PIN_13;
	Gpio_Init(&GPIOX);

	GPIOX.Gpio_Pin_Config.Gpio_Pin_Number=GPIO_PIN_14;
	Gpio_Init(&GPIOX);

	GPIOX.Gpio_Pin_Config.Gpio_Pin_Number=GPIO_PIN_15;
	Gpio_Init(&GPIOX);


}
void Spi_Config(Spi_Handle_t SPI){
	SPI.Spi_Config.Spi_Device_Mode=SPI_MASTER_MODE;
	SPI.Spi_Config.Spi_Bus_Config=SPI_FULL_DUPLEX;
	SPI.Spi_Config.Spi_Sclk_Speed=SPI_CLK_SPEED_DIV_2;
	SPI.Spi_Config.Spi_Dff=SPI_8_BIT_DFF;
	SPI.Spi_Config.Spi_Cpha=SPI_CPHA_RESET;
	SPI.Spi_Config.Spi_Cpol=SPI_CPOL_RESET;
	SPI.Spi_Config.Spi_Ssm=SPI_SSM_EN;
	SPI.Spi_Config.Spi_Ssi=SPI_SSI_SET;
    Spi_Init(&SPI);
}

void Gpio_Button_init(void){

	Gpio_Handle_t GPIO;
		GPIO.pGPIOX=GPIOA;
		GPIO.Gpio_Pin_Config.Gpio_Pin_Mode=GPIO_MODE_IP;
		GPIO.Gpio_Pin_Config.Gpio_Pin_Number=GPIO_PIN_0;
		GPIO.Gpio_Pin_Config.Gpio_Pin_Optype=GPIO_OTYPER_PUPL;
		GPIO.Gpio_Pin_Config.Gpio_Pin_Speed=GPIO_HIGH_SPEED;
		GPIO.Gpio_Pin_Config.Gpio_Pin_PUPDcontrl=GPIO_NO_PUPDR;
		Gpio_Init(&GPIO);
}

int main(){

	Gpio_Handle_t GPIOX;
		GPIOX.pGPIOX=GPIOB;
	Gpio_Pin_Config(GPIOX);
	Gpio_Button_init();
	Spi_Handle_t SPI;
	SPI.Pspix=SPI2;

	while(1){
		while(!Gpio_Read_Pin(GPIOA, GPIO_PIN_0));
		Spi_Config(SPI);
		Spi_Ssoe_cntrl(SPI2,Enable);
		Spi_Periph_Cntrl(SPI2,Enable);





	}


	return 0;
}

