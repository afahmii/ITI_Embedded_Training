/*
 * CLCD_program.c
 *
 *  Created on: Aug 17, 2021
 *      Author: DELL
 */
#include "../../lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "CLCD_config.h"
#include <util/delay.h>

void CLCD_VidSendCommand(u8 Copy_u8Command)
{
	/* Set RS pin as Low */
	DIO_VidSetPinValue(CLCD_CCTRL_PORT,CLCD_RS_PIN,low);

	/* Set RW pin as Low to write*/
	DIO_VidGetPinValue(CLCD_CCTRL_PORT,CLCD_RW_PIN,low);

	/* Send command to pins D0 to D7*/
	DIO_VidSetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/* Set enable pin */
	DIO_VidSetPinValue(CLCD_CCTRL_PORT,CLCD_E_PIN,high);

	/* delay */
	_delay_ms(3);

	/* Clear enable pin */
	DIO_VidSetPinValue(CLCD_CCTRL_PORT,CLCD_E_PIN,low);
}
void CLCD_VidSendData(u8 Copy_u8Command)
{
	/* Set RS pin as high */
	DIO_VidSetPinValue(CLCD_CCTRL_PORT,CLCD_RS_PIN,high);

	/* Set RW pin as Low to write*/
	DIO_VidGetPinValue(CLCD_CCTRL_PORT,CLCD_RW_PIN,low);

	/* Send command to pins D0 to D7*/
	DIO_VidSetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/* Set enable pin */
	DIO_VidSetPinValue(CLCD_CCTRL_PORT,CLCD_E_PIN,high);

	/* delay */
	_delay_ms(3);

	/* Clear enable pin */
	DIO_VidSetPinValue(CLCD_CCTRL_PORT,CLCD_E_PIN,low);
}
void CLCD_VidInit()
{
	DIO_VidSetPortDirection(CLCD_DATA_PORT,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_RS_PIN,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_RW_PIN,output);
	DIO_VidSetPinDirection(CLCD_CCTRL_PORT,CLCD_E_PIN,output);

	_delay_ms(40);
	/* Function Set command */
	CLCD_VidSendCommand(0b00111111);

	/* Display ON/OFF command */
	CLCD_VidSendCommand(0b00001100);

	/* Display clear */
	CLCD_VidSendCommand(1);
}
void CLCD_VidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8address=0;
	if(Copy_u8XPos == 0) /* first line */
	{
		Local_u8address= Copy_u8YPos;
	}
	else if(Copy_u8XPos == 1) /* second line */
	{
		Local_u8address= 0x40 + Copy_u8YPos;
	}
	CLCD_VidSendCommand(Local_u8address + 128); /* 0b10000000 -->> 128 */
}

void CLCD_VidWriteSpecialCharacter( u8 * Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Address= 8 * Copy_u8PatternNumber;
	/* Writing in CGRAM */
	CLCD_VidSendCommand(64+Local_u8Address);
	/* Saving the rows bytes for writing the character  */
	for(u8 i=0; i<8; i++)
	{
		CLCD_VidSendData(Copy_pu8Pattern[i]);
	}
	/* Going to any position on the screen*/
	CLCD_VidGoToXY(Copy_u8XPos,Copy_u8YPos);
	/* Printing the character */
	CLCD_VidSendData(Copy_u8PatternNumber);
}

void CLCD_VidWriteString(u8 * Copy_pu8Array) /* function to send a string */
{
	u8 i=0;
		while(Copy_pu8Array[i] != '\0') /* the defined string will have 10 characters maximum */
		{
			CLCD_VidSendData(Copy_pu8Array[i]); /* send character by character */
			i++;
		}
}
