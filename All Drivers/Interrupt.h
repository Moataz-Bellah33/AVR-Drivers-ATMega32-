/*
	***************************************************
				Interrupt Header File
	***************************************************
*/

#include "GPIO.h"
#include "avr/interrupt.h"

#ifndef Interrupt_H_
#define Interrupt_H_

/***************************   Timers Section   **************************************/
#define TMR0_OF_En() TIMSK |= 1<<TOIE0				//Enable Timer0 Over Flow
#define TMR0_OF_Dis() TIMSK &= ~(1<<TOIE0)			//Disable Timer0 Over Flow
#define TMR0_OC_En() TIMSK |= 1<<OCIE0				//Enable Timer0 Output Compare
#define TMR0_OC_Dis() TIMSK &= ~(1<<OCIE0)			//Disable Timer0 Output Compare
#define TMR1_OF_En() TIMSK |= 1<<TOIE1				//Enable Timer1 Over Flow
#define TMR1_OF_Dis() TIMSK &= ~(1<<TOIE1)			//Disable Timer1 Over Flow
#define TMR1_OCA_En() TIMSK |= 1<<OCIE1A			//Enable Timer1 Output Compare A
#define TMR1_OCA_Dis() TIMSK &= ~(1<<OCIE1A)		//Disable Timer1 Output Compare A
#define TMR1_OCB_En() TIMSK |= 1<<OCIE1B			//Enable Timer1 Output Compare B
#define TMR1_OCB_Dis() TIMSK &= ~(1<<OCIE1B)		//Disable Timer1 Output Compare B
#define TMR1_IC_En() TIMSK |= 1<<TICIE1				//Enable Timer1 Input Capture
#define TMR1_IC_Dis() TIMSK &= ~(1<<TICIE1)			//Disable Timer1 Input Capture
#define TMR2_OF_En() TIMSK |= 1<<TOIE2				//Enable Timer2 Over Flow
#define TMR2_OF_Dis() TIMSK &= ~(1<<TOIE2)			//Disable Timer2 Over Flow
#define TMR2_OC_En() TIMSK |= 1<<OCIE2				//Enable Timer2 Output Compare
#define TMR2_OC_Dis() TIMSK &= ~(1<<OCIE2)			//Disable Timer2 Output Compare

/***************************   External Interrupt Section   **************************************/
// Enabling/Disabling INT0,INT1,INT2
#define Ext_INT0_En() GICR |= 1<<INT0				//Enable External Interrupt INT0
#define Ext_INT0_Dis() GICR &= ~(1<<INT0)			//Disable External Interrupt INT0
#define Ext_INT1_En() GICR |= 1<<INT1				//Enable External Interrupt INT0
#define Ext_INT1_Dis() GICR &= ~(1<<INT1)			//Disable External Interrupt INT0
#define Ext_INT2_En() GICR |= 1<<INT2				//Enable External Interrupt INT0
#define Ext_INT2_Dis() GICR &= ~(1<<INT2)			//Disable External Interrupt INT0

// Control Triggering Option
#define Ext_INT0_Low_Lvl() do {MCUCR &= ~(1<<ISC01); MCUCR &= ~(1<<ISC00);}while(0)				//Triggering option of INT0 is Low Level (ISC01,ISC00)=(0,0)
#define Ext_INT0_Logc_Chng() do {MCUCR &= ~(1<<ISC01); MCUCR |= 1<<ISC00;}while(0)				//Triggering option of INT0 is any logical change (ISC01,ISC00)=(0,1)
#define Ext_INT0_Fall_Edg() do {MCUCR |= 1<<ISC01; MCUCR &= ~(1<<ISC00);}while(0)				//Triggering option of INT0 is Falling Edge (ISC01,ISC00)=(1,0)
#define Ext_INT0_Rise_Edg() do {MCUCR |= 1<<ISC01; MCUCR |= 1<<ISC00;}while(0)					//Triggering option of INT0 is Rising Edge (ISC01,ISC00)=(1,1)
#define Ext_INT1_Low_Lvl() do {MCUCR &= ~(1<<ISC11); MCUCR &= ~(1<<ISC10);}while(0)				//Triggering option of INT1 is Low Level (ISC11,ISC10)=(0,0)
#define Ext_INT1_Logc_Chng() do {MCUCR &= ~(1<<ISC11); MCUCR |= 1<<ISC10;}while(0)				//Triggering option of INT1 is any logical change (ISC11,ISC10)=(0,1)
#define Ext_INT1_Fall_Edg() do {MCUCR |= 1<<ISC11; MCUCR &= ~(1<<ISC10);}while(0)				//Triggering option of INT1 is Falling Edge (ISC11,ISC10)=(1,0)
#define Ext_INT1_Rise_Edg() do {MCUCR |= 1<<ISC11; MCUCR |= 1<<ISC10;}while(0)					//Triggering option of INT1 is Rising Edge (ISC11,ISC10)=(1,1)
#define Ext_INT2_Fall_Edg() MCUCSR &= ~(1<<ISC2)												//Triggering option of INT2 is Falling Edge (ISC2) = (0)
#define Ext_INT2_Rise_Edg() MCUCSR |= 1<<ISC2													//Triggering option of INT2 is Rising Edge (ISC2) = (1)



#endif