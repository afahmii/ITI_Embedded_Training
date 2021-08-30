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
	/*Char Array to store operation*/
	u8 Local_u8CharArr[20] = {0};
	/*Array to store result*/
	u8 Local_u8ResultArr[10]= {0};
	/* Char to store Pressed Key*/
	u8 Local_u8Keypressed=0;
	/*Counter used to iterate the operation array*/
	u8 Global_u8Counter =0;
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
	/*Fetch the char value of the pressed key and store it in a Variable*/
	Local_u8Keypressed = KPD_u8GetPressedKey();
	/*check if the returned key value is valid*/
	if(Local_u8Keypressed != NOT_PRESSED){
		/*Display the pressed char on the lcd*/
		ClCD_VidSendData(Local_u8Keypressed);
		/*Store the operation in an array*/
		KPD_VidStoreOperation(Local_u8CharArr,Local_u8Keypressed,&Global_u8Counter);
	}



	if( Local_u8Keypressed == '='){
	CLCD_VidSendString(Local_u8CharArr);
	/*Doing Calculation on Array*/
	Local_u16Res = KPD_u16KPDCalc(Local_u8CharArr);

	/*Converting result into array of chars*/
	CLCD_VidSendNumber(Local_u8ResultArr,Local_u16Res);
	/*Displaying result*/
	CLCD_VidSendString(Local_u8ResultArr);
	}/*End of if*/
	}/*end of super loop*/
}/*end of main*/
