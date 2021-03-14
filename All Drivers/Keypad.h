/* 
	*********************************************************
						Keypad Header File
	*********************************************************
*/

#include "GPIO.h"

#ifndef Keypad_H_
#define Keypad_H_

#define Kypd_Port PA
#define Col_Size 4		// connected to low nibble of Keypad port
#define Row_Size 4		// connected to high nibble of Keypad port

uint8_t Get_Pressed_Key();

#endif