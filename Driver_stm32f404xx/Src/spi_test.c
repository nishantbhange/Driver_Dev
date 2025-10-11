#include<stdio.h>
#include<stdint.h>
#include"stm32f407xx.h"
#include<string.h>
//pb12 nss
//pb13 sck
//pb14 miso
//pb15 mosi
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
	char NB[]="ATMKBFJ";
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
uint8_t length=strlen(NB);
Spi_Send_Data(SPI2,&length,1);
Spi_Send_Data(SPI2,(uint8_t*)NB,strlen(NB));
while(SPI.Pspix->SPI_SR&(1<<7));
Spi_Periph_Cntrl(SPI2,Disable);
}

return 0;
}


