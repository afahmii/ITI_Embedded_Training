/*
 * main.c
 *
 *  Created on: Aug 17, 2021
 *      Author: AbdElRahman
 */
#include "Datatypes.h"
#include "util/delay.h"
#include "MCAL/DIO_Interface.h"
#include "HAL/CLCD_Config.h"
#include "HAL/CLCD_Interface.h"

#define CODE_SELECT 1  /*1 for printing string,
 	 	 	 	 	 	 2 for string moves in a sine wave
 	 	 	 	 	 	 3 for Special Charcater to be displayed moving in a loop
 	 	 	 	 	 	 4 name in arabic
 	 	 	 	 	 	 5 special character as human *dancing* */


/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*											MAIN PROGRAM											*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/


#if CODE_SELECT == 1
/*											1. Printing String 										*/
/*--------------------------------------------------------------------------------------------------*/

void main(void){

/*									Local Variables Deceleration						  			*/

u8 CLCD_LocalStr[]={'a','b','d','e','l','r','a','h','m','a','n','\0'}; /*my name*/

/*										LCD PORTS Initialization									*/
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_EN_PIN,output);
	DIO_VidSetPortDirection(CLCD_DATA_PORT, output);
	CLCD_VidInit(); /*Initializes the LCD*/

	/* Test Code
	CLCD_VidGotoXY(1,8);
	ClCD_VidSendData('I');
	ClCD_VidSendData('T');
	ClCD_VidSendData('I');
	_delay_ms(500);
	CLCD_VidWriteSpecialChar(customChar,1,1,14);*/

/*												The Super Loop										*/
	while(1){
		CLCD_VidSendString(CLCD_LocalStr);
		_delay_ms(400);
		while(1);
	}
} /*End of Main*/


#elif CODE_SELECT == 2
/*									2. string moves in a sine wave									*/
/*--------------------------------------------------------------------------------------------------*/

void main(void){
/*									Local Variables Deceleration									*/
	u8 CLCD_LocalStr[]={'a','b','d','\0'}; /*my name*/
	u8 Local_StrSizeShift = (sizeof(CLCD_LocalStr))/(sizeof(CLCD_LocalStr[0]))-1;

/*										LCD PORTS Initialization									*/
		DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,output);
		DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,output);
		DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_EN_PIN,output);
		DIO_VidSetPortDirection(CLCD_DATA_PORT, output);
		CLCD_VidInit(); /*Initializes the LCD*/

/*												Super Loop											*/
	while(1){
			u8 i = 0;
				for (u8 j = 0; j<16;j++ )
				{
					CLCD_VidGotoXY(i,j);
					CLCD_VidSendString(CLCD_LocalStr);
					CLCD_VidLcdClear();
					j += Local_StrSizeShift;
					i ^= 1;
				}
		}
} /*End of Main*/


#elif CODE_SELECT == 3
/*									3. Special Char moves line by line								*/
/*--------------------------------------------------------------------------------------------------*/

void main(void){

/*									Local Variables Deceleration									*/
	u8 customChar[] = {0x04,0x0A,0x0E,0x07,0x06,0x04,0x04,0x0A}; /*Person*/

/*										LCD PORTS Initialization									*/
		DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,output);
		DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,output);
		DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_EN_PIN,output);
		DIO_VidSetPortDirection(CLCD_DATA_PORT, output);
		CLCD_VidInit(); /*Initializes the LCD*/

/*												The Super Loop										*/

	while(1){
		u8 i = 0;
			for (u8 j = 0; j<16;j++ )
			{
				CLCD_VidWriteSpecialChar(customChar,0,i,j);
				_delay_ms(200);
				CLCD_VidLcdClear();
			}
			i=1;
			for (u8 j = 15; j>0;j-- )
			{

				CLCD_VidWriteSpecialChar(customChar,0,i,j);
				_delay_ms(200);
				CLCD_VidLcdClear();
				//j==15? i ^= 1:0;

			}
	}
}/*End of Main*/


#elif CODE_SELECT == 4
/*												Name in Arabic										*/
/*--------------------------------------------------------------------------------------------------*/

void main(void){

/*									Local Variables Deceleration									*/

	u8 customChar1[] = {0x00,0x00,0x07,0x04,0x1F,0x00,0x00,0x00}; /*A*/
	u8 customChar2[] = {0x00,0x00,0x02,0x02,0x1F,0x00,0x08,0x00}; /*b*/
	u8 customChar3[] = {0x00,0x00,0x02,0x02,0x0F,0x00,0x00,0x00}; /*d*/
	u8 customChar4[] = {0x00,0x02,0x02,0x02,0x02,0x02,0x02,0x00}; /*a*/
	u8 customChar5[] = {0x00,0x02,0x02,0x02,0x02,0x02,0x0E,0x00}; /*l*/
	u8 customChar6[] = {0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x10}; /*r*/
	u8 customChar7[] = {0x00,0x00,0x0C,0x02,0x1F,0x00,0x00,0x00}; /*h*/
	u8 customChar8[] = {0x00,0x00,0x0E,0x0A,0x1F,0x00,0x00,0x00}; /*m*/
	u8 customChar9[] = {0x00,0x04,0x00,0x0A,0x0B,0x0A,0x04,0x00}; /*n*/

	u8* Local_NameinArabic[]= {customChar1,customChar2,customChar3,
								customChar4,customChar5,customChar6,
								customChar7,customChar8,customChar9};
	u8 Local_ArrLimit = ((sizeof(Local_NameinArabic))/(sizeof(Local_NameinArabic[0])));

/*										LCD PORTS Initialization									*/
		DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,output);
		DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,output);
		DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_EN_PIN,output);
		DIO_VidSetPortDirection(CLCD_DATA_PORT, output);
		CLCD_VidInit(); /*Initializes the LCD*/
/*												The Super Loop										*/
		while(1){
					for (u8 j = 0; j<Local_ArrLimit-1;j++ )
					{
						CLCD_VidWriteSpecialChar((Local_NameinArabic[j]),j,0,15-j);
						_delay_ms(100);
						}
					//CLCD_VidWriteSpecialChar((Local_NameinArabic[8]),8,0,15-8);
					while(1);/*Stop here*/
		}
}/*End of main*/


#elif CODE_SELECT == 5
/*									5. Special Character Dance										*/
/*--------------------------------------------------------------------------------------------------*/

void main(void){

/*									Local Variables Deceleration									*/
	u8 customChar1[] = {0x04,0x0A,0x0E,0x07,0x06,0x04,0x04,0x0A}; /*Person- boogie left*/
	u8 customChar2[] = {0x04,0x0A,0x0A,0x1C,0x0C,0x04,0x0A,0x11}; /*Person- boogie right*/
/*										LCD PORTS Initialization									*/
		DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,output);
		DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,output);
		DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_EN_PIN,output);
		DIO_VidSetPortDirection(CLCD_DATA_PORT, output);
		CLCD_VidInit(); /*Initializes the LCD*/

/*												The Super Loop										*/
		while(1){

			u8 i = 0;
						for (u8 j = 0; j<16;j++ )
						{
							CLCD_VidLcdClear();
							CLCD_VidWriteSpecialChar(customChar1,0,i,j);
							_delay_ms(200);
							CLCD_VidLcdClear();
							i ^= 1;
							CLCD_VidWriteSpecialChar(customChar2,0,i,j);
							_delay_ms(200);
							i ^= 1;

						}
		}
}
#else
	while(1);


#endif


