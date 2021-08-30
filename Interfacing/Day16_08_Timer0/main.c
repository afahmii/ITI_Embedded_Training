/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *      Author: AbdElRahman
 */
#include "LIB/Bit_Operations.h"
#include "LIB/Datatypes.h"
#include "util/delay.h"

#include "MCAL/DIO/DIO_Interface.h"

#include "MCAL/GIE/GIE_Interface.h"

#include "MCAL/Timer/Timer_Interface.h"

#define Code_Select 4
/*Counter Displayed on SSD Code*/
#if Code_Select == 1

void ISR_LEDToggle(void){
	static u16 Local_Counter = 0;
	static u8 state = 0;
	if(Local_Counter == 4000){
		state = !state;
		DIO_VidSetPinValue(Port_A,Pin_6,state);
		Local_Counter = 0;
	}
	else{
		Local_Counter++;
	}
}


void main (void){

	DIO_VidSetPinDirection(Port_A,Pin_6,output);
	TIMER0_SetCallBack(ISR_LEDToggle);
	GIE_VidEnable();
	TIMER0_VidInit();
	while(1){

	}
}
#elif Code_Select == 2
/*Two SSDs MultiPlixing Code*/

u8 Arr_DecToSeg[10] = {0b00111111,   /* 0 */
                       0b00000110,   /* 1 */
                       0b01011011,   /* 2 */
                       0b01001111,   /* 3 */
                       0b01100110,   /* 4 */
                       0b01101101,   /* 5 */
                       0b01111101,   /* 6 */
                       0b00000111,   /* 7 */
                       0b01111111,   /* 8 */
                       0b01101111    /* 9 */
					  };

void ISR_SevenSegmantCounter(void){
	/*ISR Info:
	 - Prescaler = 8, Tick time = 1MicroSecond, Register OV time = 256 MicroSeconds
	 - OV Happens every 0.25ms(Counter ++)
	 - Turn on first SSD after 20 ms(Counter = 80)
	 - Turn on second SSD after 40 ms(Counter = 160)
	 - Increment time after 1 sec (counter2 = 4000)
	 - Reset Local_Counters*/
	static u16 Local_Counter = 0;	/*Counter to switch between displays every 20ms*/
	static u16 Local_Counter2 = 0; 	/*Counter to Display Number Every 1 second*/
	static u8 Local_SevenSegCounter = 0 ;
	if(Local_Counter == 80){
		DIO_VidSetPinValue(Port_D,Pin_2,high);	/*Turn off first SSD*/
		DIO_VidSetPinValue(Port_D,Pin_3,low);	/*Turn on second SSD*/
		Local_Counter++;						/*Increment counter,Prevent stucking*/
		Local_Counter2++;						/*Increment counter2 to reach 1 sec*/

	}
	else if(Local_Counter ==160){
		DIO_VidSetPinValue(Port_D,Pin_3,high);	/*Turn off second SSD*/
		DIO_VidSetPinValue(Port_D,Pin_2,low);	/*Turn on first SSD*/
		Local_Counter2 ++;						/*Increment counter2 to reach 1 sec*/
		Local_Counter = 0; 						/*Reset Counter*/
	}
	else if(Local_Counter2 == 4000){
		DIO_VidSetPortVal(Port_C,Arr_DecToSeg[Local_SevenSegCounter]);	/*Count*/
		Local_SevenSegCounter++;										/*Inc Displayed Number*/
		if(Local_SevenSegCounter==10)									/*Reset Number*/
			Local_SevenSegCounter=0;
		Local_Counter2 =0 ;												/*Reset Counter*/
	}
	/*Always Inc Counters*/
	else{
		Local_Counter++;
		Local_Counter2++;
	}
}

extern st_TIMER timer_0;
void main (void){

	//DIO_VidSetPortDirection(Port_C,output);
	//DIO_VidSetPinDirection(Port_D,Pin_3,output);
	//DIO_VidSetPinDirection(Port_D,Pin_2,output);
	DIO_VidSetPinDirection(Port_B,Pin_3,output);
	//TIMER0_SetCallBack(ISR_SevenSegmantCounter);
	GIE_VidDisable();
	TIMER0_VidInit(&timer_0);
	while(1){

	}
}
#elif Code_Select == 3
/*			PWM				*/


extern st_TIMER0 timer_0;
void main (void){

	DIO_VidSetPinDirection(Port_B,Pin_3,output);
	GIE_VidDisable();
	TIMER0_VidInit(&timer_0);
	while(1){
		_delay_ms(1500);
		TIMER0_VidDutyCycleSelector_Normal(50);
		_delay_ms(1500);
		TIMER0_VidDutyCycleSelector_Normal(30);
	}
}
#elif Code_Select == 4
/*			Servo PWM			*/

extern st_TIMER1_INIT timer1_init;
extern st_TIMER1_CompareMatch timer1_comparematch;
extern st_TIMER1_CompareValue timer1_compareval;
void main (void){

	DIO_VidSetPinDirection(Port_D,Pin_5,output);
	GIE_VidDisable();
	TIMER1_VidInit(&timer1_init);
	TIMER1_VidSetCompareMatchOutputMode(&timer1_comparematch);
	TIMER1_VidSetTopOVF(20000);
	TIMER1_VidSetCompareVal(&timer1_compareval);


	while(1){
			for(u16 i = 750; i<2500; i++){
			timer1_compareval.CompareMatchValue = i;
			TIMER1_VidSetCompareVal(&timer1_compareval);
			_delay_us(3000);
			}
		}
}

#endif
