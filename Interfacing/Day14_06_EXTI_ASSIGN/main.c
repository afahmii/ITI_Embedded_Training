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
u8 toggle2 = 0;

void EXTI1_Task(void){
	toggle2 ^=1;
}


void main(void){
	/*Forcing Contact Between "EXTI_Task"s Function and The Pointers to Functions*/
	EXTI1_CallBack(EXTI1_Task);
	/*Blink LED*/
	DIO_VidSetPortDirection(Port_C,high);
	DIO_VidSetPinDirection(Port_D,Pin_3,input); /*INT1 Pin*/
	DIO_VidSetPinValue(Port_D,Pin_3,high); /*Internal Pull-up Resistor*/
	GIE_VidEnable(); /*Global Interrupt Enable*/
	EXTI1_VidIntInit();	/*Falling Edge Config*/

	while(1){
		if(toggle2 ==1){
			for(u8 i = 0; i<8;i++){
				DIO_VidSetPortVal(Port_C,0x00);
				DIO_VidSetPinValue(Port_C,i,high);
				_delay_ms(200);
				DIO_VidSetPinValue(Port_C,i,low);
				_delay_ms(200);
		}
			}
		else{
		DIO_VidSetPortVal(Port_C,0x00);
		_delay_ms(500);
		DIO_VidSetPortVal(Port_C,0xff);
		_delay_ms(500);
		}
	}/*End of Super Loop*/
}/*End of main*/


