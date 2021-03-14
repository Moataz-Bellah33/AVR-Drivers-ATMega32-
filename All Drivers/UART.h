/* 
	*********************************************
			UART Driver Header File
	*********************************************
*/

#include "GPIO.h"
#include "Interrupt.h"

#ifndef UART_H_
#define UART_H_

/*****************************************************************************************************************/
/*************************************** General Definitions *****************************************************/
/*****************************************************************************************************************/
#define Rx_Port PD										//USART Rx Port
#define Rx_Pin P0										//USART Rx Pin
#define Tx_Port PD										//USART Tx Port
#define Tx_Pin P1										//USART Tx Pin
#define XCK_Port PB										//USART Synchronous XCk Port
#define XCK_Pin P0										//USART Synchronous XCk Pin
#define Baud_Rate 9600									//Baud Rate Value of UART Communication
#define F_osc 8000000UL									//CPU Frequency
#define UART_Nrml_Spd_Vlu (F_osc/16/Baud_Rate-1)		//Equation Of UART Normal Speed in Receiving and Transmitting to Load in UBRR Register
#define UART_Dbl_Spd_Vlu (F_osc/8/Baud_Rate-1)			//Equation Of UART Double Speed in Receiving and Transmitting to Load in UBRR Register
#define Asynch_Synch_Mode 0								//Define USART Mode, 0 for Asynchronous, 1 for Synchronous
#define Nrml_Dbl_Speed_Mode 0							//Define UART Speed Mode, 0 for Normal Speed, 1 for Double Speed

/*****************************************************************************************************************/
/*************************** Data and Control Registers Definitions and Functions ********************************/
/*****************************************************************************************************************/
//UBRR Register "Specify UART Speed"
#define UART_Nrml_Speed() do {UCSRA &= ~(1<<U2X);UBRRL=(uint8_t)(UART_Nrml_Spd_Vlu);UBRRH=(uint8_t)(UART_Nrml_Spd_Vlu>>8);}while(0)		//UART in Normal Speed Mode
#define UART_Dbl_Speed() do {UCSRA |= 1<<U2X;UBRRL=(uint8_t)(UART_Dbl_Spd_Vlu);UBRRH=(uint8_t)(UART_Dbl_Spd_Vlu>>8);}while(0)			//UART in Double Speed Mode

//UDR Register "UART Received or Transmitted Data"
void UART_Init();
uint8_t UART_Read();
void UART_Write_C(uint8_t chrctr);
void UART_Write_S(uint8_t *str);
void UART_Stop();

//UCSRA Register "Control Register A"
#define UART_Rx_Is_Cmplt Bit_Is_Set(UCSRA,RXC)					//Check if Data has been Received
#define UART_Tx_Is_Cmplt Bit_Is_Set(UCSRA,TXC)					//Check if Data has been Transmitted
#define UART_DR_Is_Ready Bit_Is_Set(UCSRA,UDRE)					//Check if Data Register "UDR" is empty and ready to receive new data
#define UART_Frame_Is_Err Bit_Is_Set(UCSRA,FE)					//Check if There is a Frame Error in Receiving the next character
#define UART_Data_Is_OR Bit_Is_Set(UCSRA,DOR)					//Check if There is Data OverRun
#define UART_Parity_Is_Err Bit_Is_Set(UCSRA,PE)					//Check if There is Parity Error Occured in Received Data 
#define UART_Mul_Proc_En() UCSRA |= 1<<MPCM						//Enable Multi-Processor Communication Mode
#define UART_Mul_Proc_Dis() UCSRA &= ~(1<<MPCM)					//Disable Multi-Processor Communication Mode

//UCSRB Register "Control Register B"
#define UART_Rx_Int_En() UCSRB |= 1<<RXCIE						//Enable Receive Complete Interrupt (of "RXC bit")
#define UART_Rx_Int_Dis() UCSRB &= ~(1<<RXCIE)					//Disable Receive Complete Interrupt (of "RXC bit")
#define UART_Tx_Int_En() UCSRB |= 1<<TXCIE						//Enable Transmit Complete Interrupt (of "TXC bit")
#define UART_Tx_Int_Dis() UCSRB &= ~(1<<TXCIE)					//Disable Transmit Complete Interrupt (of "TXC bit")
#define UART_DRE_Int_En() UCSRB |= 1<<UDRIE						//Enable USART Data Register Empty Interrupt (of "UDRE bit")
#define UART_DRE_Int_Dis() UCSRB &= ~(1<<UDRIE)					//Disable USART Data Register Empty Interrupt (of "UDRE bit")
#define UART_Rx_En() UCSRB |= 1<<RXEN							//Enable USART Receiver
#define UART_Rx_Dis() UCSRB &= ~(1<<RXEN)						//Disable USART Receiver
#define UART_Tx_En() UCSRB |= 1<<TXEN							//Enable USART Transmitter
#define UART_Tx_Dis() UCSRB &= ~(1<<TXEN)						//Disable USART Transmitter

//UCSRC Register "Control Register C", Must Set "URSEL" bit before any command to "UCSRC" Register
#define UART_Asynch_Mode() do {UCSRC |= 1<<URSEL;UCSRC &= ~(1<<UMSEL);}while(0)												//Operate On Asynchronous Mode
#define UART_Synch_Mode() do {UCSRC |= 1<<URSEL;UCSRC |= 1<<UMSEL;}while(0)													//Operate On Synchronous Mode
#define UART_Parity_Dis() do {UCSRC |= 1<<URSEL;UCSRC &= ~(1<<UPM1);UCSRC &= ~(1<<UPM0);}while(0)							//Parity Check Is Disabled
#define UART_Parity_Even() do {UCSRC |= 1<<URSEL;UCSRC |= 1<<UPM1;UCSRC &= ~(1<<UPM0);}while(0)								//Parity Check Is Even
#define UART_Parity_Odd() do {UCSRC |= 1<<URSEL;UCSRC |= 1<<UPM1;UCSRC |= 1<<UPM0;}while(0)									//Parity Check Is Odd
#define UART_Stop_Bit_1() do {UCSRC |= 1<<URSEL;UCSRC &= ~(1<<USBS);}while(0)												//1 Stop bit
#define UART_Stop_Bit_2() do {UCSRC |= 1<<URSEL;UCSRC |= 1<<USB);}while(0)													//2 Stop bit
#define UART_Ch_Sz_5() do {UCSRC |= 1<<URSEL;UCSRB &= ~(1<<UCSZ2);UCSRC &= ~(1<<UCSZ1);UCSRC &= ~(1<<UCSZ0);}while(0)		//Character Size is 5-bit
#define UART_Ch_Sz_6() do {UCSRC |= 1<<URSEL;UCSRB &= ~(1<<UCSZ2);UCSRC &= ~(1<<UCSZ1);UCSRC |= 1<<UCSZ0;}while(0)			//Character Size is 6-bit
#define UART_Ch_Sz_7() do {UCSRC |= 1<<URSEL;UCSRB &= ~(1<<UCSZ2);UCSRC |= 1<<UCSZ1;UCSRC &= ~(1<<UCSZ0);}while(0)			//Character Size is 7-bit
#define UART_Ch_Sz_8() do {UCSRC |= 1<<URSEL;UCSRB &= ~(1<<UCSZ2);UCSRC |= 1<<UCSZ1;UCSRC |= 1<<UCSZ0;}while(0)				//Character Size is 8-bit
#define UART_Ch_Sz_9() do {UCSRC |= 1<<URSEL;UCSRB |= 1<<UCSZ2;UCSRC |= 1<<UCSZ1;UCSRC |= 1<<UCSZ0;}while(0)				//Character Size is 9-bit
#define UART_Synch_Clk_Pol_Ris_Tx_Fal_Rx() do {UCSRC |= 1<<URSEL;UCSRC &= ~(1<<UCPOL);}while(0)								//For XCK Pin, Tx --> Rising Edge, Rx --> Falling Edge
#define UART_Synch_Clk_Pol_Fal_Tx_Ris_Rx() do {UCSRC |= 1<<URSEL;UCSRC |= 1<<UCPOL;}while(0)								//For XCK Pin, Tx --> Falling Edge, Rx --> Rising Edge

#endif

