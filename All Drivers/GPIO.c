/* 
	************************************************
			GPIO Driver Functions Definition
	************************************************
*/

#include "GPIO.h"

void Port_Direction(uint8_t base, uint8_t status )
{
	if (status == OUTPUT)
		(*(uint8_t volatile *)(base+1)) = 0xFF;
	else if (status == INPUT)
		(*(uint8_t volatile *)(base+1)) = 0;
}
void Pin_Direction(uint8_t base, uint8_t pin, uint8_t status )
{
	if (status == OUTPUT)
	(*(uint8_t volatile *)(base+1)) |= 1<<pin;
	else if (status == INPUT)
	(*(uint8_t volatile *)(base+1)) &= ~(1<<pin);
}
void Port_Write(uint8_t base, uint8_t value )
{
	(*(uint8_t volatile *)(base+2)) = value;
}
uint8_t Port_Read(uint8_t base )
{
	uint8_t result;
	result = (*(uint8_t volatile *)(base));
	return result;
}
void Pin_Write(uint8_t base, uint8_t pin, uint8_t value )
{
	if (value == HIGH)
	(*(uint8_t volatile *)(base+2)) |= 1<<pin;
	else if (value == LOW)
	(*(uint8_t volatile *)(base+2)) &= ~(1<<pin);
}
uint8_t Pin_Read(uint8_t base, uint8_t pin )
{
	if ((*(uint8_t volatile *)(base)) & (1<<pin))
		return 1;
	else
		return 0; 
}
void Pin_Toggle(uint8_t base, uint8_t pin)
{
	(*(uint8_t volatile *)(base+2)) ^= 1<<pin;
}
void Bit_Set(uint8_t reg, uint8_t bit)
{
	reg |= 1<<bit;
}
void Bit_Clear(uint8_t reg, uint8_t bit)
{
	reg &= ~(1<<bit);
}
void Bit_Toggle(uint8_t reg, uint8_t bit)
{
	reg ^= 1<<bit;
}
uint8_t Bit_Is_Set(uint8_t reg, uint8_t bit)
{
	if (reg & (1<<bit))
	return 1;
	else
	return 0;
}
uint8_t Bit_Is_Clear(uint8_t reg, uint8_t bit)
{
	if (reg & (1<<bit))
	return 0;
	else
	return 1;
}
