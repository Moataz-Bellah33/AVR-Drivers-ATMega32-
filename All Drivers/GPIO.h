/* 
	*********************************************
			GPIO Driver Header File
	*********************************************
*/
#include "avr/io.h"
#include "GPDEF.h"

#ifndef GPIO_H_
#define GPIO_H_

void Port_Direction(uint8_t base, uint8_t status );
void Pin_Direction(uint8_t base, uint8_t pin, uint8_t status );
void Port_Write(uint8_t base, uint8_t value );
uint8_t Port_Read(uint8_t base );
void Pin_Write(uint8_t base, uint8_t pin, uint8_t value );
uint8_t Pin_Read(uint8_t base, uint8_t pin );
void Pin_Toggle(uint8_t base, uint8_t pin);
void Bit_Set(uint8_t reg, uint8_t bit);
void Bit_Clear(uint8_t reg, uint8_t bit);
void Bit_Toggle(uint8_t reg, uint8_t bit);
uint8_t Bit_Is_Set(uint8_t reg, uint8_t bit);
uint8_t Bit_Is_Clear(uint8_t reg, uint8_t bit);

#endif