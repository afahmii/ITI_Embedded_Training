/*
 * UltraSonic_program.c
 *
 *  Created on: Sep 8, 2021
 *      Author: DELL
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER/Timer_interface.h"
#include "UltraSonic_config.h"

#include <util/delay.h>

u16 Global_u16TimerOverFlowCounter=0;

void Timer1_voidOverFlowISR()
{
	Global_u16TimerOverFlowCounter++;
}


void UltraSonic_voidInit()
{
	/* set the call back function of the OV interrupt with the defined function */
		TIMR1_OvF_SetCallBack(Timer1_voidOverFlowISR);
	/* setting up ultra-sonic sensor pin */
		DIO_VidSetPinDirection(UltraSonic_Port,TRIGGER_Pin,output);		/* trigger pin ------>>>>>>make a driver for it */
	/* initialize Timer 1 in normal mode */
		Timer1_16bit_vid_Init(Normal,UnitA_Normal_port_operation);

	/* Enable overflow interrupt for timer 1 */
		Timer_vid_Interrupt(timer1,Overflow_Int,Enable);
}


f64 UltraSonic_f64Read()
{

	f64 Local_u64TimerCountValue=0;
	f64 Local_f64Distance=0;
	u16 Local_u16ICU=0;


	/* Give 10 us trigger pulse on the trigger pin in the ultra-sonic */
	DIO_VidSetPinValue(UltraSonic_Port,TRIGGER_Pin,high);
	_delay_us(10);
	DIO_VidSetPinValue(UltraSonic_Port,TRIGGER_Pin,low);

	/* Capture on rising edge */
	Timer1_voidIcuCaptureOn(Enable_rising_edge_trigger);

	/* clear the timer over flow counter */
	Global_u16TimerOverFlowCounter = 0;

	/* Clear timer 1 counter register */
	Timer1_voidWriteTCTN1(0);

	/* Clear Input Capture Flag */
	Timer_voidClearFlag(Timer1_ICU_Flag);

	/* wait for the rising edge */
	WaitForFlagOfICU();

	/* Capture on falling edge */
		Timer1_voidIcuCaptureOn(Enable_falling_edge_trigger);
	/* Clear timer 1 counter register */
	Timer1_voidWriteTCTN1(0);

	/* Clear Input Capture Flag */
	Timer_voidClearFlag(Timer1_ICU_Flag);

	/* wait for the falling edge */
	WaitForFlagOfICU();

	/* get the ICU value  */
	Local_u16ICU = GetCaptureUnit();

	/* get the number of counts */
	Local_u64TimerCountValue = (f64)Local_u16ICU +(f64) (65535 * Global_u16TimerOverFlowCounter);
	/* 8MHz Timer freq, sound speed =343 m/s */
	Local_f64Distance = Local_u64TimerCountValue * (f64) 0.00214375;

	/* clear the ICU flAG */
	Timer_voidClearFlag(Timer1_ICU_Flag);

	/* return the distance */
	return Local_f64Distance;
}
