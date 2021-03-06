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
#include <stdio.h>


/*HAL*/
#include "HAL/LCD/CLCD_Interface.h"
#include "HAL/LCD/CLCD_Config.h"

/*MCAL*/
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"

void main(void){
	/*Setting LCD Directions*/
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_EN_PIN,output);
	DIO_VidSetPortDirection(CLCD_DATA_PORT, output);
	CLCD_VidInit(); /*Initializes the LCD*/

	DIO_VidSetPinDirection(Port_A,Pin_0,input); /*ADC0 pin*/
	DIO_VidSetPinDirection(Port_C,Pin_1,output); /*For LED 1 */
	DIO_VidSetPinDirection(Port_C,Pin_2,output); /*For LED 2*/
	DIO_VidSetPinDirection(Port_C,Pin_3,output); /*For LED 3*/
	/*DIO_VidSetPortDirection(Port_C,output);*/
	ADC_VidInit();

	u8 read;
	u16 mv_read;
	u8 Local_u8CharArr[8];
	while(1){
		read = ADC_u8ReadChannel(ADC_0); /*Get ADC Values*/
		mv_read = ADC_f32LCDVoltConv(read);
		snprintf(Local_u8CharArr,7,"%d",mv_read);
		CLCD_VidSendString(Local_u8CharArr);
		_delay_ms(1000);
		CLCD_VidLcdClear();

	}
}
