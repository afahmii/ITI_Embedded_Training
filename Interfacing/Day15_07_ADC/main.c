/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: AbdElRahman
 */
#include "LIB/Datatypes.h"
#include "LIB/Bit_Operations.h"
#define F_CPU 8000000
#include <util/delay.h>

/*MCAL*/
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"


void main(void){
	DIO_VidSetPinDirection(Port_A,Pin_0,input); /*ADC0 pin*/
	DIO_VidSetPinDirection(Port_C,Pin_1,output); /*For LED 1 */
	DIO_VidSetPinDirection(Port_C,Pin_2,output); /*For LED 2*/
	DIO_VidSetPinDirection(Port_C,Pin_3,output); /*For LED 3*/
	/*DIO_VidSetPortDirection(Port_C,output);*/

	ADC_VidInit();
	u8 read;
	while(1){
		read = ADC_u8ReadChannel(ADC_0); /*Get ADC Values*/
		DIO_VidSetPortVal(Port_A,read); /*Display ADC Values at */
		if(read <100 ){
			DIO_VidSetPinValue(Port_C,Pin_3,low);
			DIO_VidSetPinValue(Port_C,Pin_2,low);
			DIO_VidSetPinValue(Port_C,Pin_1,high);
		}
		else if(read > 100 && read < 180){
			DIO_VidSetPinValue(Port_C,Pin_3,low);
			DIO_VidSetPinValue(Port_C,Pin_1,low);
			DIO_VidSetPinValue(Port_C,Pin_2,high);
		}
		else{
			DIO_VidSetPinValue(Port_C,Pin_1,low);
			DIO_VidSetPinValue(Port_C,Pin_2,low);
			DIO_VidSetPinValue(Port_C,Pin_3,high);
		}
	}
}
