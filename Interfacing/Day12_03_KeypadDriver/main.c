/*
 * main.c
 *
 *  Created on: Aug 18, 2021
 *      Author: AbdElRahman
 */
#include "LIB/Datatypes.h"
#include "LIB/Bit_Operations.h"

#include "MCAL/DIO_Interface.h"
#include "MCAL/DIO_Config.h"

#include "HAL/LCD/CLCD_Interface.h"
#include "HAL/LCD/CLCD_Config.h"

#include "HAL/Keypad/Keypad_Interface.h"
#include "HAL/Keypad/Keypad_config.h"

void main(void){
	/*Char Array to store and print*/
	u8 Local_u8CharArr[20];
	/* Variable to store Result*/
	u16 Local_u16Res =0;
	/*Setting LCD Directions*/
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_EN_PIN,output);
	DIO_VidSetPortDirection(CLCD_DATA_PORT, output);

	/*set Keypad Port Direction*/
	DIO_VidSetPinDirection(KPD_u8PORT,KPD_u8COLUMN_PIN0,output);
	DIO_VidSetPinDirection(KPD_u8PORT,KPD_u8COLUMN_PIN1,output);
	DIO_VidSetPinDirection(KPD_u8PORT,KPD_u8COLUMN_PIN2,output);
	DIO_VidSetPinDirection(KPD_u8PORT,KPD_u8COLUMN_PIN3,output);
	DIO_VidSetPinDirection(KPD_u8PORT,KPD_u8ROW_PIN0,input);
	DIO_VidSetPinDirection(KPD_u8PORT,KPD_u8ROW_PIN1,input);
	DIO_VidSetPinDirection(KPD_u8PORT,KPD_u8ROW_PIN2,input);
	DIO_VidSetPinDirection(KPD_u8PORT,KPD_u8ROW_PIN3,input);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW_PIN0,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW_PIN1,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW_PIN2,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW_PIN3,high);

	/*Initializes the LCD*/
	CLCD_VidInit();


	while(1){

/*
	u8 Local_u8KPDResult = KPD_u8GetPressedKey();
		if(Local_u8KPDResult != NOT_PRESSED){
			ClCD_VidSendData(Local_u8KPDResult);
		}
*/


	Local_u16Res = KPD_u16KPDCalc(Local_u8CharArr);

	}/*end of super loop*/
}/*end of main*/
