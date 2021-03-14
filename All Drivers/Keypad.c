/* 
	*********************************************************
				Keypad Functions Definition File
	*********************************************************
*/

#include "Keypad.h"

uint8_t Kypd_Map[Row_Size][Col_Size] = {
										{'7','8','9','*'},
										{'4','5','6','/'},
										{'7','8','9','-'},
										{'C','0','=','+'}
									   };
uint8_t Get_Pressed_Key()
{
	uint8_t row,col;
	(*(volatile uint8_t *)(Kypd_Port+1)) = 0xF0;	//Make Keypad port output for high nibble and input for low nibble
	(*(volatile uint8_t *)(Kypd_Port+2)) = 0xFF;	//Apply 1 on all pins of Keypad port
	while(1)
	{
		for (row=0;row<Row_Size;row++)
		{
			(*(volatile uint8_t *)(Kypd_Port+2)) &= ~(1<<(row+4));
			for (col=0;col<Col_Size;col++)
			{
				if (Bit_Is_Clear(Kypd_Port,col))
				{
					while (Bit_Is_Clear(Kypd_Port,col));
					return Kypd_Map[row][col];
				}
			}
			(*(volatile uint8_t *)(Kypd_Port+2)) = 0xFF;
		}
	}
	
}