/* 
	***********************************************************
			LCD LM016L Driver | Functions Definition File
	***********************************************************
*/

#include "LCD.h"

void LCD_Init ()
{
	delay_us(5000);
	// Making LCD Data Port Output
	if (LCD_MODE == 4) 
		(*(volatile uint8_t *)(LCD_DATA_PORT+1)) |= (0x0F << LCD_DPORT_NIBBLE); 
	else
		(*(volatile uint8_t *)(LCD_DATA_PORT+1)) = 0xFF;
	// Making LCD Command Pins Output
	(*(volatile uint8_t *)(LCD_CMD_PORT+1)) |= (1<<LCD_RS_PIN)|(1<<LCD_E_PIN);
	// initializing LCD for 4-bit mode
	if (LCD_MODE == 4)
	{
		LCD_CMD(0x33);
		LCD_CMD(0x32);
		LCD_CMD(0x28);
		LCD_CMD(0x0E);
		LCD_CMD(0x01);
	}
	// initializing LCD for 8-bit mode
	else if (LCD_MODE == 8)
	{
		LCD_CMD(0x38);
		LCD_CMD(0x0E);
		LCD_CMD(0x01);
	}
}
void LCD_CMD (uint8_t cmd)
{
	uint8_t i;
	(*(volatile uint8_t *)(LCD_CMD_PORT+2)) &= ~(1<<LCD_RS_PIN);
	//send command in 4-bit mode
	if (LCD_MODE==4)
	{
		for (i=0;i<2;i++)
		{	
			(*(volatile uint8_t *)(LCD_DATA_PORT+2)) = ((*(volatile uint8_t *)(LCD_DATA_PORT+2))|(0x0F<<LCD_DPORT_NIBBLE))&((cmd<<(i*4))|(~(0x0F<<LCD_DPORT_NIBBLE)));
			(*(volatile uint8_t *)(LCD_CMD_PORT+2)) |= 1<<LCD_E_PIN;
			delay_us(10);
			(*(volatile uint8_t *)(LCD_CMD_PORT+2)) &= ~(1<<LCD_E_PIN);
			delay_us(100);
		}
	}
	//send command in 8-bit mode
	if (LCD_MODE==8)
	{
		(*(volatile uint8_t *)(LCD_DATA_PORT+2)) = cmd;
		(*(volatile uint8_t *)(LCD_CMD_PORT+2)) |= 1<<LCD_E_PIN;
		delay_us(10);
		(*(volatile uint8_t *)(LCD_CMD_PORT+2)) &= ~(1<<LCD_E_PIN);
		delay_us(100);
	}
}
void LCD_Put_C (uint8_t chrctr)
{
	uint8_t i;
	(*(volatile uint8_t *)(LCD_CMD_PORT+2)) |= 1<<LCD_RS_PIN;
	//send Data in 4-bit mode
	if (LCD_MODE==4)
	{
		for (i=0;i<2;i++)
		{
			(*(volatile uint8_t *)(LCD_DATA_PORT+2)) = ((*(volatile uint8_t *)(LCD_DATA_PORT+2))|(0x0F<<LCD_DPORT_NIBBLE))&((chrctr<<(i*4))|(~(0x0F<<LCD_DPORT_NIBBLE)));
			(*(volatile uint8_t *)(LCD_CMD_PORT+2)) |= 1<<LCD_E_PIN;
			delay_us(10);
			(*(volatile uint8_t *)(LCD_CMD_PORT+2)) &= ~(1<<LCD_E_PIN);
			delay_us(100);
		}
	}
	//send Data in 8-bit mode
	if (LCD_MODE==8)
	{
		
		(*(volatile uint8_t *)(LCD_DATA_PORT+2)) = chrctr;
		(*(volatile uint8_t *)(LCD_CMD_PORT+2)) |= 1<<LCD_E_PIN;
		delay_us(10);
		(*(volatile uint8_t *)(LCD_CMD_PORT+2)) &= ~(1<<LCD_E_PIN);
		delay_us(100);

	}
}
uint8_t LCD_Put_S (uint8_t * str)
{
	uint8_t i=0;
	while (str[i] != 0)
	{
		LCD_Put_C(str[i]);
		i++;
	}
	return i;
}
void LCD_GoTo_XY (uint8_t x, uint8_t y)
{
	// Array of first element address in every line
	uint8_t Frst_Elmnt_Adr[]={0x80,0xC0};
	LCD_CMD(Frst_Elmnt_Adr[y-1]+ (x-1));
}
