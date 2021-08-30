/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: AbdElRahman
 */
#include "LIB/Datatypes.h"
#include "LIB/Bit_Operations.h"
#include <util/delay.h>

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/EXTI/EXTI_Config.h"
#include "MCAL/EXTI/EXTI_Private.h"
u8 toggle1 = 1;
u8 toggle2 = 1;
void EXTI0_Task(void){
	if(toggle1 == 1){
		DIO_VidSetPinValue(Port_A,Pin_2,high);
		toggle1 ^=1;
	}
	else
	{
		DIO_VidSetPinValue(Port_A,Pin_2,low);
				toggle1 ^=1;
	}
}
void EXTI1_Task(void){
	if(toggle2 == 1){
			DIO_VidSetPinValue(Port_A,Pin_3,high);
			toggle2 ^=1;
		}
		else
		{
			DIO_VidSetPinValue(Port_A,Pin_3,low);
					toggle2 ^=1;
		}
}


void main(void){
	/*Forcing Contact Between "EXTI_Task"s Function and The Pointers to Functions*/
	EXTI0_CallBack(EXTI0_Task);
	EXTI1_CallBack(EXTI1_Task);
	/*Blink LED*/
	DIO_VidSetPinDirection(Port_A,Pin_2,output);
	DIO_VidSetPinDirection(Port_A,Pin_3,output);
	DIO_VidSetPinDirection(Port_D,Pin_2,input); /*INT0 Pin*/
	DIO_VidSetPinValue(Port_D,Pin_2,high); /*Internal Pull-up Resistor*/
	DIO_VidSetPinDirection(Port_D,Pin_3,input); /*INT1 Pin*/
	DIO_VidSetPinValue(Port_D,Pin_3,high); /*Internal Pull-up Resistor*/
	GIE_VidEnable(); /*Global Interrupt Enable*/
	EXTI0_VidIntInit(); /*Falling Edge Config*/
	EXTI1_VidIntInit();	/*Falling Edge Config*/

	while(1){

	}/*End of Super Loop*/
}/*End of main*/


