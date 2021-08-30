/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *      Author: AbdElRahman
 */
#include "LIB/Bit_Operations.h"
#include "LIB/Datatypes.h"
#include <util/delay.h>
#include "stdio.h"
#include <stdlib.h>

#include "MCAL/DIO/DIO_Interface.h"

#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Timer/Timer_Interface.h"

#include "HAL/LCD/CLCD_Interface.h"
#include "HAL/LCD/CLCD_Config.h"

#define Code_Select 2



#if Code_Select == 1
/*			Servo PWM			*/

extern st_TIMER1_INIT timer1_init;
extern st_TIMER1_CompareMatch timer1_comparematch;
extern st_TIMER1_CompareValue timer1_compareval;
void main (void){

	ADC_VidInit();									/*Initializes ADC*/
	DIO_VidSetPinDirection(Port_A,Pin_4,input); 	/*ADC4 pin as input*/

	DIO_VidSetPinDirection(Port_D,Pin_5,output); 				/*Timer1 OC1A output pin*/
	GIE_VidDisable();											/* Disable All Maskable interrupts*/
	TIMER1_VidInit(&timer1_init);								/*Initialize timer*/
	TIMER1_VidSetCompareMatchOutputMode(&timer1_comparematch);	/*Set Timer1 Compare output mode*/
	TIMER1_VidSetTopOVF(20000);									/*Set ICR1 TOP Value "OVERFLOW Value"*/
	TIMER1_VidSetCompareVal(&timer1_compareval);				/*Set OCR1A Compare Match Value*/
	static u16 Local_ADCReading;
	static s32 Local_Mapped ;
	while(1){
			Local_ADCReading = ADC_u8ReadChannel(ADC_4);
			Local_Mapped = ADC_VidMapping(Local_ADCReading,0,255,1000,2000);
			timer1_compareval.CompareMatchValue = Local_Mapped;
			TIMER1_VidSetCompareVal(&timer1_compareval);
			_delay_us(3000);
			}
}



#elif Code_Select == 2

u16 Global_u16OnTime, Global_u16Duty;
void Timer1ICU_VidTaks1(void){
	DIO_VidSetPinValue(Port_B,Pin_2,high);
	static u16 Local_u8ICUSnap1, Local_u8ICUSnap2, Local_u8ICUSnap3;
	static u8 Local_u8Counter=0;
	if(Local_u8Counter ==0 ){
		Local_u8ICUSnap1 = TIMER1_VidICURead();
		Local_u8Counter = 1;
	}
	else if(Local_u8Counter ==1 ){
		Local_u8ICUSnap2 = TIMER1_VidICURead();
		Local_u8Counter = 2;
		Global_u16OnTime = Local_u8ICUSnap2 - Local_u8ICUSnap1;
		TIMER1_VidICU_TriggerStatus(TIMER1_ICU_Falling_Edge);

	}
	else if(Local_u8Counter ==2 ){
		Local_u8ICUSnap3 = TIMER1_VidICURead();
		Global_u16Duty = Local_u8ICUSnap3 - Local_u8ICUSnap1;
		Local_u8Counter = 0;
		//DIO_VidSetPinValue(Port_B,Pin_3,high);
		TIMER1_VidICU_INT_Status(TIMER1_ICU_INT_Disable);
	}
}
extern st_TIMER1_INIT timer1_init;
void main(void){

	u8 Local_u8OnTime[20]={0};
	u8 Local_u8Duty[20]={0};
	timer1_init.Timer_Mode = Normal;
	timer1_init.Interrupt_type = Over_FLOW_INT;
	timer1_init.Interrupt_status = TIMER1_INT_Disable;
	DIO_VidSetPinDirection(Port_B,Pin_2,output);
	//DIO_VidSetPinDirection(Port_B,Pin_3,output);
	/*Setting LCD Directions*/
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_EN_PIN,output);
	DIO_VidSetPortDirection(CLCD_DATA_PORT, output);
	TIMER1_ICU_SetCallBack(Timer1ICU_VidTaks1);
	TIMER1_VidInit(&timer1_init);				/*Initialize timer1*/
	GIE_VidEnable();
	TIMER1_VidICU_TriggerStatus(TIMER1_ICU_Rising_Edge);
	TIMER1_VidICU_INT_Status(TIMER1_ICU_INT_Enable);


	CLCD_VidInit(); /*Initializes the LCD*/



	while(1){
		CLCD_VidGotoXY(0,0);
		snprintf(Local_u8OnTime,20,"On Time = %i",Global_u16OnTime);
		CLCD_VidSendString(Local_u8OnTime);
		CLCD_VidGotoXY(1,0);
		snprintf(Local_u8Duty,20,"Duty = %i",Global_u16Duty);
		CLCD_VidSendString(Local_u8Duty);
		_delay_ms(1000);

	}
}

#endif
