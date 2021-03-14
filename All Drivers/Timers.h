/*
	***************************************************
					Timers Header File
	***************************************************
*/

#include "GPIO.h"
#include "Interrupt.h"

#ifndef Timers_H_
#define Timers_H_

/*****************************************************************************************************************************************/
/**************************************************************** Timer0 Macros **********************************************************/
/*****************************************************************************************************************************************/

#define TMR0_Reset() do {TCCR0=0;TCNT0=0;OCR0=0;} while(0)	//Reset Timer0 and Clear all of its Registers
#define TMR0_Stop() TMR0_No_Clk()							//Stop Timer0

// Timer0 Data Registers "TCNT0" "OCR0"
#define TMR0_Vlu TCNT0			//TCNT0 Register to hold Timer1/counter0 value

#define TMR0_OC_Vlu OCR0		//OCR0 Register to hold Timer1/counter0 Output Compare value 		

// Timer0 Control Register "TCCR0"
#define TMR0_FOC() TCCR0 |= 1<<FOC0																			//Force Output Compare Match

#define TMR0_Nrml() do {TCCR0 &= ~(1<<WGM01);TCCR0 &= ~(1<<WGM00);}while(0)									//Timer0 works in Normal Mode
#define TMR0_PWM_Phs_Crrct() do {TCCR0 &= ~(1<<WGM01);TCCR0 |= 1<<WGM00;}while(0)							//Timer0 works in PWM,Phase Correct Mode
#define TMR0_CTC() do {TCCR0 |= 1<<WGM01;TCCR0 &= ~(1<<WGM00;}while(0)										//Timer0 works in Clear Time on Compare Match Mode
#define TMR0_Fst_PWM() do {TCCR0 |= 1<<WGM01;TCCR0 |= 1<<WGM00;}while(0)									//Timer0 works in Fast PWM Mode

#define TMR0_COM_Nrml() do {TCCR0 &= ~(1<<COM01);TCCR0 &= ~(1<<COM00);}while(0)								//Timer0 Compare Output Mode works in Normal Mode, OC0 Disconnected
#define TMR0_COM_Toggle() do {TCCR0 &= ~(1<<COM01);TCCR0 |= 1<<COM00;}while(0)								//Timer0 Compare Output Mode works in Toggle OC0 on Compare Match Mode
#define TMR0_COM_Clr() do {TCCR0 |= 1<<COM01;TCCR0 &= ~(1<<COM00);}while(0)									//Timer0 Compare Output Mode works in Clear OC0 on Compare Match Mode
#define TMR0_COM_Set() do {TCCR0 |= 1<<COM01;TCCR0 |= 1<<COM00;}while(0)									//Timer0 Compare Output Mode works in Set OC0 on Compare Match Mode

#define TMR0_No_Clk() do {TCCR0 &= ~(1<<CS02);TCCR0 &= ~(1<<CS01);TCCR0 &= ~(1<<CS00);}while(0)				//Timer0 Clock Select is : No Clock Source (Timer0 stopped)
#define TMR0_Clk_1() do {TCCR0 &= ~(1<<CS02);TCCR0 &= ~(1<<CS01);TCCR0 |= 1<<CS00;}while(0)					//Timer0 Clock Select is : Clock Source with No Prescaling
#define TMR0_Clk_8() do {TCCR0 &= ~(1<<CS02);TCCR0 |= 1<<CS01;TCCR0 &= ~(1<<CS00);}while(0)					//Timer0 Clock Select is : Clock/8
#define TMR0_Clk_64() do {TCCR0 &= ~(1<<CS02);TCCR0 |= 1<<CS01;TCCR0 |= 1<<CS00;}while(0)					//Timer0 Clock Select is : Clock/64
#define TMR0_Clk_256() do {TCCR0 |= 1<<CS02;TCCR0 &= ~(1<<CS01);TCCR0 &= ~(1<<CS00);}while(0)				//Timer0 Clock Select is : Clock/256
#define TMR0_Clk_1024() do {TCCR0 |= 1<<CS02;TCCR0 &= ~(1<<CS01);TCCR0 |= 1<<CS00;}while(0)					//Timer0 Clock Select is : Clock/1024
#define TMR0_Ext_Clk_Falling() do {TCCR0 |= 1<<CS02;TCCR0 |= 1<<CS01;TCCR0 &= ~(1<<CS00);}while(0)			//Timer0 Clock Select is : External clock source on T0, Falling Edge
#define TMR0_Ext_Clk_Rising() do {TCCR0 |= 1<<CS02;TCCR0 |= 1<<CS01;TCCR0 |= 1<<CS00;}while(0)				//Timer0 Clock Select is : External clock source on T0, Rising Edge

/*****************************************************************************************************************************************/
/**************************************************************** Timer1 Macros **********************************************************/
/*****************************************************************************************************************************************/

#define TMR1_Reset() do {TCCR1A=0;TCCR1B=0;TCNT1=0;OCR1A=0;OCR1B=0;} while(0)	//Reset Timer1 and Clear all of its Registers
#define TMR1_Stop() TMR1_No_Clk()												//Stop Timer1

// Timer1 Data Registers "TCNT1" "OCR1A" "OCR1B"
#define TMR1_Vlu TCNT1					//TCNT1 Register to hold timer1/counter1 value
#define TMR1_Vlu_HIGH TCNT1H			//TCNT1H Register to hold timer1/counter1 High Byte value
#define TMR1_Vlu_LOW TCNT1L				//TCNT1L Register to hold timer0/counter0 value

#define TMR1_OC_A_Vlu OCR1A				//OCR1A Register to hold timer1/counter1 Output Compare channel A value
#define TMR1_OC_A_Vlu_High OCR1AH		//OCR1AH Register to hold timer1/counter1 Output Compare channel A High Byte value
#define TMR1_OC_A_Vlu_LOW OCR1AL		//OCR1AL Register to hold timer1/counter1 Output Compare channel A Low Byte value

#define TMR1_OC_B_Vlu OCR1B				//OCR1B Register to hold timer1/counter1 Output Compare channel B value
#define TMR1_OC_B_Vlu_High OCR1BH		//OCR1BH Register to hold timer1/counter1 Output Compare channel B High Byte value
#define TMR1_OC_B_Vlu_LOW OCR1BL		//OCR1BL Register to hold timer1/counter1 Output Compare channel B Low Byte value

// Timer1 Control Register "TCCR1A" "TCCR1B"
#define TMR1_FOC_A() TCCR1A |= 1<<FOC1A																										//Force Output Compare Match For channel A
#define TMR1_FOC_B() TCCR1A |= 1<<FOC1B																										//Force Output Compare Match For channel B

#define TMR1_Nrml() do {TCCR1B &= ~(1<<WGM13);TCCR1B &= ~(1<<WGM12);TCCR1A &= ~(1<<WGM11);TCCR1A &= ~(1<<WGM10);}while(0)					//Timer1 works in Normal Mode
#define TMR1_PWM_Phs_Crrct_8bit() do {TCCR1B &= ~(1<<WGM13);TCCR1B &= ~(1<<WGM12);TCCR1A &= ~(1<<WGM11);TCCR1A |= 1<<WGM10;}while(0)		//Timer1 works in PWM,Phase Correct 8-bit Mode
#define TMR1_PWM_Phs_Crrct_9bit() do {TCCR1B &= ~(1<<WGM13);TCCR1B &= ~(1<<WGM12);TCCR1A |= 1<<WGM11;TCCR1A &= ~(1<<WGM10);}while(0)		//Timer1 works in PWM,Phase Correct 9-bit Mode
#define TMR1_PWM_Phs_Crrct_10bit() do {TCCR1B &= ~(1<<WGM13);TCCR1B &= ~(1<<WGM12);TCCR1A |= 1<<WGM11;TCCR1A |= 1<<WGM10;}while(0)			//Timer1 works in PWM,Phase Correct 10-bit Mode
#define TMR1_CTC_OC() do {TCCR1B &= ~(1<<WGM13);TCCR1B |= 1<<WGM12;TCCR1A &= ~(1<<WGM11);TCCR1A &= ~(1<<WGM10);}while(0)					//Timer1 works in Clear Timer on Compare Match Mode On OCR1A
#define TMR1_Fst_PWM_8bit() do {TCCR1B &= ~(1<<WGM13);TCCR1B |= 1<<WGM12;TCCR1A &= ~(1<<WGM11);TCCR1A |= 1<<WGM10;}while(0)					//Timer1 works in Fast PWM 8-bit Mode
#define TMR1_Fst_PWM_9bit() do {TCCR1B &= ~(1<<WGM13);TCCR1B |= 1<<WGM12;TCCR1A |= 1<<WGM11;TCCR1A &= ~(1<<WGM10);}while(0)					//Timer1 works in Fast PWM 9-bit Mode
#define TMR1_Fst_PWM_10bit() do {TCCR1B &= ~(1<<WGM13);TCCR1B |= 1<<WGM12;TCCR1A |= 1<<WGM11;TCCR1A |= 1<<WGM10;}while(0)					//Timer1 works in Fast PWM 10-bit Mode
#define TMR1_PWM_Phs_Freq_Crrct_IC() do {TCCR1B |= 1<<WGM13;TCCR1B &= ~(1<<WGM12);TCCR1A &= ~(1<<WGM11);TCCR1A &= ~(1<<WGM10);}while(0)		//Timer1 works in PWM,Phase and Frequency Correct Mode On ICR1
#define TMR1_PWM_Phs_Freq_Crrct_OC() do {TCCR1B |= 1<<WGM13;TCCR1B &= ~(1<<WGM12);TCCR1A &= ~(1<<WGM11);TCCR1A |= 1<<WGM10;}while(0)		//Timer1 works in PWM,Phase and Frequency Correct Mode On OCR1A
#define TMR1_PWM_Phs_Crrct_IC() do {TCCR1B |= 1<<WGM13;TCCR1B &= ~(1<<WGM12);TCCR1A |= 1<<WGM11;TCCR1A &= ~(1<<WGM10);}while(0)				//Timer1 works in PWM,Phase Correct Mode On ICR1
#define TMR1_PWM_Phs_Crrct_OC() do {TCCR1B |= 1<<WGM13;TCCR1B &= ~(1<<WGM12);TCCR1A |= 1<<WGM11;TCCR1A |= 1<<WGM10;}while(0)				//Timer1 works in PWM,Phase Correct Mode On OCR1A
#define TMR1_CTC_IC() do {TCCR1B |= 1<<WGM13;TCCR1B |= 1<<WGM12;TCCR1A &= ~(1<<WGM11);TCCR1A &= ~(1<<WGM10);}while(0)						//Timer1 works in Clear Timer on Compare Match Mode On ICR1
#define TMR1_Fst_PWM_IC() do {TCCR1B |= 1<<WGM13;TCCR1B |= 1<<WGM12;TCCR1A |= 1<<WGM11;TCCR1A &= ~(1<<WGM10);}while(0)						//Timer1 works in Fast PWM Mode On ICR1
#define TMR1_Fst_PWM_OC() do {TCCR1B |= 1<<WGM13;TCCR1B |= 1<<WGM12;TCCR1A |= 1<<WGM11;TCCR1A |= 1<<WGM10;}while(0)							//Timer1 works in Fast PWM Mode On OCR1A

#define TMR1_COM_A_Nrml() do {TCCR1A &= ~(1<<COM1A1);TCCR1A &= ~(1<<COM1A0);}while(0)														//Timer1 Compare Output Mode channel A works in Normal Mode, OC1A Disconnected
#define TMR1_COM_A_Toggle() do {TCCR1A &= ~(1<<COM1A1);TCCR1A |= 1<<COM1A0;}while(0)														//Timer1 Compare Output Mode channel A works in Toggle OC1A on Compare Match Mode
#define TMR1_COM_A_Clr() do {TCCR1A |= 1<<COM1A1;TCCR1A &= ~(1<<COM1A0);}while(0)															//Timer1 Compare Output Mode channel A works in Clear OC1A on Compare Match Mode
#define TMR1_COM_A_Set() do {TCCR1A |= 1<<COM1A1;TCCR1A |= 1<<COM1A0;}while(0)																//Timer1 Compare Output Mode channel A works in Set OC1A on Compare Match Mode
#define TMR1_COM_B_Nrml() do {TCCR1A &= ~(1<<COM1B1);TCCR1A &= ~(1<<COM1B0);}while(0)														//Timer1 Compare Output Mode channel B works in Normal Mode, OC1B Disconnected
#define TMR1_COM_B_Toggle() do {TCCR1A &= ~(1<<COM1B1);TCCR1A |= 1<<COM1B0;}while(0)														//Timer1 Compare Output Mode channel B works in Toggle OC1B on Compare Match Mode
#define TMR1_COM_B_Clr() do {TCCR1A |= 1<<COM1B1;TCCR1A &= ~(1<<COM1B0);}while(0)															//Timer1 Compare Output Mode channel B works in Clear OC1B on Compare Match Mode
#define TMR1_COM_B_Set() do {TCCR1A |= 1<<COM1B1;TCCR1A |= 1<<COM1B0;}while(0)																//Timer1 Compare Output Mode channel B works in Set OC1B on Compare Match Mode

#define TMR1_No_Clk() do {TCCR1B &= ~(1<<CS12);TCCR1B &= ~(1<<CS11);TCCR1B &= ~(1<<CS10);}while(0)											//Timer1 Clock Select is : No Clock Source (Timer1 stopped)
#define TMR1_Clk_1() do {TCCR1B &= ~(1<<CS12);TCCR1B &= ~(1<<CS11);TCCR1B |= 1<<CS10;}while(0)												//Timer1 Clock Select is : Clock Source with No Prescaling
#define TMR1_Clk_8() do {TCCR1B &= ~(1<<CS12);TCCR1B |= 1<<CS11;TCCR1B &= ~(1<<CS10);}while(0)												//Timer1 Clock Select is : Clock/8
#define TMR1_Clk_64() do {TCCR1B &= ~(1<<CS12);TCCR1B |= 1<<CS11;TCCR1B |= 1<<CS10;}while(0)												//Timer1 Clock Select is : Clock/64
#define TMR1_Clk_256() do {TCCR1B |= 1<<CS12;TCCR1B &= ~(1<<CS11);TCCR1B &= ~(1<<CS10);}while(0)											//Timer1 Clock Select is : Clock/256
#define TMR1_Clk_1024() do {TCCR1B |= 1<<CS12;TCCR1B &= ~(1<<CS11);TCCR1B |= 1<<CS10;}while(0)												//Timer1 Clock Select is : Clock/1024
#define TMR1_Ext_Clk_Falling() do {TCCR1B |= 1<<CS12;TCCR1B |= 1<<CS11;TCCR1B &= ~(1<<CS10);}while(0)										//Timer1 Clock Select is : External clock source on T1, Falling Edge
#define TMR1_Ext_Clk_Rising() do {TCCR1B |= 1<<CS12;TCCR1B |= 1<<CS11;TCCR1B |= 1<<CS10;}while(0)											//Timer1 Clock Select is : External clock source on T1 Rising Edge

#define TMR1_ICNC_En() TCCR1B |= 1<<ICNC1																									//Enable Input Capture Noise Canceler
#define TMR1_ICNC_Dis() TCCR1B &= ~(1<<ICNC1)																								//Disable Input Capture Noise Canceler
#define TMR1_ICES_Rising() TCCR1B |= 1<<ICES1																								//Input Capture is Capturing on the Rising Edge
#define TMR1_ICES_Falling() TCCR1B &= ~(1<<ICES1)																							//Input Capture is Capturing on the Falling Edge

/*****************************************************************************************************************************************/
/**************************************************************** Timer2 Macros **********************************************************/
/*****************************************************************************************************************************************/

#define TMR2_Reset() do {TCCR2=0;TCNT2=0;OCR2=0;ASSR=0;} while(0)	//Reset Timer2 and Clear all of its Registers
#define TMR2_Stop() TMR2_No_Clk()									//Stop Timer2

// Timer2 Data Registers "TCNT2" "OCR2"
#define TMR2_Vlu TCNT2			//TCNT2 Register to hold timer2/counter2 value

#define TMR2_OC_Vlu OCR2		//OCR2 Register to hold timer2/counter2 Output Compare value

// Timer2 Control Register "TCCR2"
#define TMR2_FOC() TCCR2 |= 1<<FOC2																			//Force Output Compare Match

#define TMR2_Nrml() do {TCCR2 &= ~(1<<WGM21);TCCR2 &= ~(1<<WGM20);}while(0)									//Timer2 works in Normal Mode
#define TMR2_PWM_Phs_Crrct() do {TCCR2 &= ~(1<<WGM21);TCCR2 |= 1<<WGM20;}while(0)							//Timer2 works in PWM,Phase Correct Mode
#define TMR2_CTC() do {TCCR2 |= 1<<WGM21;TCCR2 &= ~(1<<WGM20;}while(0)										//Timer2 works in Clear Timer on Compare Match Mode
#define TMR2_Fst_PWM() do {TCCR2 |= 1<<WGM21;TCCR2 |= 1<<WGM20;}while(0)									//Timer2 works in Fast PWM Mode

#define TMR2_COM_Nrml() do {TCCR2 &= ~(1<<COM21);TCCR2 &= ~(1<<COM20);}while(0)								//Timer2 Compare Output Mode works in Normal Mode, OC2 Disconnected
#define TMR2_COM_Toggle() do {TCCR2 &= ~(1<<COM21);TCCR2 |= 1<<COM20;}while(0)								//Timer2 Compare Output Mode works in Toggle OC2 on Compare Match Mode
#define TMR2_COM_Clr() do {TCCR2 |= 1<<COM21;TCCR2 &= ~(1<<COM20);}while(0)									//Timer2 Compare Output Mode works in Clear OC2 on Compare Match Mode
#define TMR2_COM_Set() do {TCCR2 |= 1<<COM21;TCCR2 |= 1<<COM20;}while(0)									//Timer2 Compare Output Mode works in Set OC2 on Compare Match Mode

#define TMR2_No_Clk() do {TCCR2 &= ~(1<<CS22);TCCR2 &= ~(1<<CS21);TCCR2 &= ~(1<<CS20);}while(0)				//Timer2 Clock Select is : No Clock Source (Timer2 stopped)
#define TMR2_Clk_1() do {TCCR2 &= ~(1<<CS22);TCCR2 &= ~(1<<CS21);TCCR2 |= 1<<CS20;}while(0)					//Timer2 Clock Select is : Clock Source with No Prescaling
#define TMR2_Clk_8() do {TCCR2 &= ~(1<<CS22);TCCR2 |= 1<<CS21;TCCR2 &= ~(1<<CS20);}while(0)					//Timer2 Clock Select is : Clock/8
#define TMR2_Clk_32() do {TCCR2 &= ~(1<<CS22);TCCR2 |= 1<<CS21;TCCR2 |= 1<<CS20;}while(0)					//Timer2 Clock Select is : Clock/32
#define TMR2_Clk_64() do {TCCR2 |= 1<<CS22;TCCR2 &= ~(1<<CS21);TCCR2 &= ~(1<<CS20);}while(0)				//Timer2 Clock Select is : Clock/64
#define TMR2_Clk_128() do {TCCR2 |= 1<<CS22;TCCR2 &= ~(1<<CS21);TCCR2 |= 1<<CS20;}while(0)					//Timer2 Clock Select is : Clock/128
#define TMR2_Clk_256() do {TCCR2 |= 1<<CS22;TCCR2 |= 1<<CS21;TCCR2 &= ~(1<<CS20);}while(0)					//Timer2 Clock Select is : Clock/256
#define TMR2_Clk_1024() do {TCCR2 |= 1<<CS22;TCCR2 |= 1<<CS21;TCCR2 |= 1<<CS20;}while(0)					//Timer2 Clock Select is : Clock/1024

//Timer2 Asynchronous Status Register "ASSR"
#define TMR2_Asynch_En() ASSR |= 1<<AS2						//Enable Asynchronous mode of Timer2
#define TMR2_Asynch_Dis() ASSR &= !(1<<AS2)					//Disable Asynchronous mode of Timer2
#define TMR2_Is_Busy() (ASSR&(1<<TCN2UB)) ? 1 : 0			//Check if Timer2 Value Register "TCNT2" is Busy, 1 is busy, 0 is not busy and ready to be used
#define TMR2_OC_Is_Busy() (ASSR&(1<<OCR2UB)) ? 1 : 0		//Check if Timer2 Output Compare Register "OCR2" is Busy, 1 is busy, 0 is not busy and ready to be used
#define TMR2_CR_Is_Busy() (ASSR&(1<<TCR2UB)) ? 1 : 0		//Check if Timer2 Control Register "TCCR2" is Busy, 1 is busy, 0 is not busy and ready to be used
	
#endif