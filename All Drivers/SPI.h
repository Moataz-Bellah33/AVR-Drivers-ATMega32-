/* 
	************************************************
				SPI Driver Header File
	************************************************
*/

#include "GPIO.h"
#include "Interrupt.h"

#ifndef SPI_H_
#define SPI_H_

/*****************************************************************************************************************/
/*************************************** General Definitions *****************************************************/
/*****************************************************************************************************************/
#define MISO_Port PB				//Define Port of "MISO" pin
#define MISO_Pin P6					//Define Pin of "MISO" pin
#define MOSI_Port PB				//Define Port of "MOSI" pin
#define MOSI_Pin P5					//Define Pin of "MOSI" pin
#define SCK_Port PB					//Define Port of "SCK" pin
#define SCK_Pin P7					//Define Pin of "SCK" pin
#define SS_Port PB					//Define Port of "SS" pin
#define SS_Pin P4					//Define Pin of "SS" pin
#define SS_Master_Direction 1		//Direction of SS Pin at Master Mode, 0 for Input,1 for Output

/*****************************************************************************************************************/
/*************************** Data and Control Registers Definitions and Functions ********************************/
/*****************************************************************************************************************/
//SPDR Register "SPI Data Register", To Hold Received and Transmitted Data
void SPI_Master_Init();
void SPI_Slave_Init();
void SPI_Write_C(uint8_t chrctr);
void SPI_Wrire_S(uint8_t *str);
uint8_t SPI_Read();

//SPCR Register "SPI Control Register"
#define SPI_Int_En() SPCR |= 1<<SPIE				//Enable SPI Interrupt
#define SPI_Int_Dis() SPCR &= ~(1<<SPIE)			//Disable SPI Interrupt
#define SPI_En() SPCR |= 0b01000000						//Enable SPI
#define SPI_Dis() SPCR &= ~(1<<SPE)					//Disable SPI
#define SPI_MSB_First() SPCR &= ~(1<<DORD)			//MSB of the data "B7" goes first
#define SPI_LSB_First() SPCR |= 1<<DORD				//LSB of the data "B0" goes first
#define SPI_Slave_Mode() SPCR &= ~(1<<MSTR)			//SPI Operates in Slave Mode
#define SPI_Master_Mode() SPCR |= 1<<MSTR			//SPI Operates in Master Mode
#define SPI_Is_Master() Bit_Is_Set(SPCR,MSTR)		//Check if SPI is Operating in Master Mode
#define SPI_Is_Slave() Bit_Is_Clear(SPCR,MSTR)		//Check if SPI is Operating in Slave Mode
#define SPI_Clk_Pol_0() SPCR &= ~(1<<CPOL)			//Clock Polarity (Base Value of the Clock when it's idle) is Low "0"
#define SPI_Clk_Pol_1() SPCR |= 1<<CPOL				//Clock Polarity (Base Value of the Clock when it's idle) is High "1"
#define SPI_Clk_Pha_Lead() SPCR &= ~(1<<CPHA)		//Clock Phase, Sample on Leading (First) Clock Edge
#define SPI_Clk_Pha_Trail() SPCR |= 1<<CPHA			//Clock Phase, Sample on Trailing (Second) Clock Edge
#define SPI_Clk_Nrml_4() do{SPSR &= ~(1<<SPI2X);SPCR &= ~(1<<SPR1);SPCR &= ~(1<<SPR0);}while(0)			//SPI is in Normal Speed and Clock Rate = Focs/4
#define SPI_Clk_Nrml_16() do{SPSR &= ~(1<<SPI2X);SPCR &= ~(1<<SPR1);SPCR |= 1<<SPR0;}while(0)			//SPI is in Normal Speed and Clock Rate = Focs/16
#define SPI_Clk_Nrml_64() do{SPSR &= ~(1<<SPI2X);SPCR |= 1<<SPR1;SPCR &= ~(1<<SPR0);}while(0)			//SPI is in Normal Speed and Clock Rate = Focs/64
#define SPI_Clk_Nrml_128() do{SPSR &= ~(1<<SPI2X);SPCR |= 1<<SPR1;SPCR |= 1<<SPR0;}while(0)				//SPI is in Normal Speed and Clock Rate = Focs/128
#define SPI_Clk_Dbl_2() do{SPSR |= 1<<SPI2X;SPCR &= ~(1<<SPR1);SPCR &= ~(1<<SPR0);}while(0)				//SPI is in Double Speed and Clock Rate = Focs/2
#define SPI_Clk_Dbl_8() do{SPSR |= 1<<SPI2X;SPCR &= ~(1<<SPR1);SPCR |= 1<<SPR0;}while(0)				//SPI is in Double Speed and Clock Rate = Focs/8
#define SPI_Clk_Dbl_32() do{SPSR |= 1<<SPI2X;SPCR |= 1<<SPR1;SPCR &= ~(1<<SPR0);}while(0)				//SPI is in Double Speed and Clock Rate = Focs/32
#define SPI_Clk_Dbl_64() do{SPSR |= 1<<SPI2X;SPCR |= 1<<SPR1;SPCR |= 1<<SPR0;}while(0)					//SPI is in Double Speed and Clock Rate = Focs/64

//SPSR Register "SPI Status Register"
#define SPI_Is_Cmplt() Bit_Is_Set(SPSR,SPIF)					//Check if SPI Complete Transferring Data
#define SPI_Data_Is_Collided() Bit_Is_Set(SPSR,WCOL)			//Check if There's Data Collision happened (When Writing On Data Register "SPDR" During Data Transfer)

#endif