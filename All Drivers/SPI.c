/* 
	***********************************************************
				SPI Driver Functions Definition File
	***********************************************************
*/

#include "SPI.h"

void SPI_Master_Init()
{
	Pin_Direction(MISO_Port,MISO_Pin,INPUT);
	Pin_Direction(MOSI_Port,MOSI_Pin,OUTPUT);
	Pin_Direction(SCK_Port,SCK_Pin,OUTPUT);
	Pin_Direction(SS_Port,SS_Pin,SS_Master_Direction);
	SPI_Master_Mode();
	SPI_En();
	SPI_MSB_First();
	SPI_Clk_Pol_0();
	SPI_Clk_Pha_Lead();
	SPI_Clk_Nrml_128();

}
void SPI_Slave_Init()
{
	Pin_Direction(MISO_Port,MISO_Pin,OUTPUT);
	Pin_Direction(MOSI_Port,MOSI_Pin,INPUT);
	Pin_Direction(SCK_Port,SCK_Pin,INPUT);
	Pin_Direction(SS_Port,SS_Pin,INPUT);
	SPI_Slave_Mode();
	SPI_En();
	SPI_MSB_First();
	SPI_Clk_Pol_0();
	SPI_Clk_Pha_Lead();
}
void SPI_Write_C(uint8_t chrctr)
{
	if (SPI_Is_Master())
	{
		if (SS_Master_Direction)
		{
			Pin_Write(SS_Port,SS_Pin,LOW);
			SPDR = chrctr;
			while (!SPI_Is_Cmplt());
			Pin_Write(SS_Port,SS_Pin,HIGH);
		}
		else
		{
			SPDR = chrctr;
			while (!SPI_Is_Cmplt());
		}
	}
	else if (SPI_Is_Slave())
	{
		SPDR = chrctr;
		while ((SPSR&(1<<7))==0);
	}
}
void SPI_Wrire_S(uint8_t *str)
{
	uint8_t i=0;
	while (str[i] != 0)
	{
		SPI_Write_C(str[i]);
		i++;
	}
}
uint8_t SPI_Read()
{
	if (SPI_Is_Master())
	{
		if (SS_Master_Direction)
		{
			Pin_Write(SS_Port,SS_Pin,LOW);
			while (!SPI_Is_Cmplt());
			Pin_Write(SS_Port,SS_Pin,HIGH);
			return SPDR;
		}
		else
		{
			while (!SPI_Is_Cmplt());
			return SPDR;
		}
	}
	else if (SPI_Is_Slave())
	{
		while (!SPI_Is_Cmplt());
		return SPDR;
	}
}