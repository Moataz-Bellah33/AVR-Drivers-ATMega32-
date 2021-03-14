/* 
	************************************************
			LCD LM016L Driver | Header File
	************************************************
*/
#include "GPIO.h"
#include "util/delay.h"

#ifndef LCD_H_
#define LCD_H_

#define LCD_DATA_PORT PC //AVR Data port of LCD, Px as x is the port letter
#define LCD_CMD_PORT PD  //AVR Command port of LCD, Px as x is the port letter
#define LCD_RS_PIN 0	 //AVR RS Pin of Command port
#define LCD_E_PIN 1		 //AVR Enable Pin of Command port
#define LCD_MODE 4		 //4 for 4-bit mode, 8 for 8-bit mode 
#define LCD_DPORT_NIBBLE 4 //0 for low nibble, 4 for high nibble

#if (LCD_MODE != 4)&(LCD_MODE != 8)
#error "Wrong LCD Mode"
#endif
#if (LCD_DPORT_NIBBLE != 0)&(LCD_DPORT_NIBBLE != 4)
#error "Wrong LCD Data Port Nibble"
#endif

#define delay_us(d) _delay_ms(d)

#define LCD_Clr_Screen() LCD_CMD(0x01)
#define LCD_Home() LCD_CMD(0x02)
#define LCD_Shft_Crsr_Left() LCD_CMD(0x04)
#define LCD_Shft_Crsr_Right() LCD_CMD(0x06)
#define LCD_Dsply_Right() LCD_CMD(0x05)
#define LCD_Dsply_Left() LCD_CMD(0x07)
#define LCD_Dsply_Off_Crsr_Off() LCD_CMD(0x08)
#define LCD_Dsply_Off_Crsr_On() LCD_CMD(0x0A)
#define LCD_Dsply_On_Crsr_Off() LCD_CMD(0x0C)
#define LCD_Dsply_On_Crsr_Blnk() LCD_CMD(0x0E)
#define LCD_Dsply_OFF_Crsr_Blnk() LCD_CMD(0xOF)
#define LCD_Shft_Crsr_Pos_Left() LCD_CMD(0x10)
#define LCD_Shft_Crsr_Pos_Right() LCD_CMD(0x14)
#define LCD_All_Dsply_Right() LCD_CMD(0x18)
#define LCD_All_Dsply_Left() LCD_CMD(0x1C)

void LCD_Init ();
void LCD_CMD (uint8_t cmd);
void LCD_Put_C (uint8_t chrctr);
uint8_t LCD_Put_S (uint8_t * str);
void LCD_GoTo_XY (uint8_t x, uint8_t y);




#endif