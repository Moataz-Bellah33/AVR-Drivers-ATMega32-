/* 
	************************************************
			UART Driver Functions Definition
	************************************************
*/

#include "UART.h"

//UART Initialize
void UART_Init()
{
	Pin_Direction(Rx_Port,Rx_Pin,INPUT);				//Make Rx Pin Output
	Pin_Direction(Tx_Port,Tx_Pin,OUTPUT);				//Make Tx Pin Output
	if (Asynch_Synch_Mode == 0)							//If Asynchronous Mode
	{
		UART_Asynch_Mode();								//Enable Asynchronous Mode
		if (Nrml_Dbl_Speed_Mode == 0)
			UART_Nrml_Speed();							//Enable Normal Speed Mode
		else
			UART_Dbl_Speed();							//Enable Double Speed Mode
	}
	else												//Synchronous Mode
	{
		UART_Synch_Mode();								//Enable Synchronous Mode
		UART_Synch_Clk_Pol_Ris_Tx_Fal_Rx();				//For XCK Pin, Tx --> Rising Edge, Rx --> Falling Edge
	}
	UART_Rx_En();										//Enable Receiver
	UART_Tx_En();										//Enable Transmitter
	UART_Stop_Bit_1();									//1 stop bit
	UART_Parity_Dis();									//Disable Parity Check
	UART_Ch_Sz_8();										//8-bit Character Size
}
//UART Receive Character
uint8_t UART_Read()
{
	while(!UART_Rx_Is_Cmplt);							//Check Receiving is completed "RXC Flag"
	return UDR;											//Return Received Data in "UDR" Register
}
//UART Transmit Character
void UART_Write_C(uint8_t chrctr)
{
	while(!UART_DR_Is_Ready);							//Check Data Register is Empty and Ready "UDRE Flag"
	UDR = chrctr;										//Put Desired Character to be Transmitted in "UDR" Register
}
//UART Receive String
void UART_Write_S(uint8_t *str)
{
	uint8_t i = 0;
	while (str[i] != 0)									//Check the end of the String
	{
		UART_Write_C(str[i]);							//Transmit each character
		i++;
	}
}
//Stop UART
void UART_Stop()
{
	UCSRA = 0;
	UCSRB = 0;
	UCSRC = 0x80;										//0b10000000 As "URSEL" bit must be one to write to "UCSRC" Register
}