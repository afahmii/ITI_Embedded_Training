/*
 * main.c
 *
 *  Created on: Sep 6, 2021
 *      Author: DELL
 */
#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER/Timer_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "HAL/CLCD/CLCD_INTERFACE.h"
#include "HAL/KPD/KPD_interface.h"
#include "HAL/KPD/KPD_config.h"
#include "HAL/ULTRA_SONIC/UltraSonic_interface.h"
#include "special_functions_interface.h"


/* Global variables */
/* string to indicate turning on the right lamps */
u8 right_u8String[]="-->>";
/* string to indicate turning on the left lamps */
u8 left_u8String[]="<<--";
/* string to save the key pressed */
u8 key_u8Value=0;

u8 Globla_u8SPIData =0;
u8 * Global_u8SPIPointerToData = 0;
u8 Global_u8SmallDistanceFlag=0;

/*****************************************************************************************/
void SPI_IntReceive(void)
{
	Globla_u8SPIData = *Global_u8SPIPointerToData;

	if (Globla_u8SPIData == 70 && Global_u8SmallDistanceFlag==1 )
		{
		/* if 70 is received, then velocity is high
		 * If the velocity is high and the distance is close: open the airbag
		 *  send 65 to let the master know it needs to open the air bag */
			SPI_u8_TransmitReceive(65);
		}
	else
	{
		SPI_u8_TransmitReceive(1);
	}
}
/* *******************************************************************************************/

void ExternalInterupt()
{
	switch (key_u8Value)
	{
		case '1':
		/* if key '1' is pressed : turn on the left lamps  */
			DIO_VidSetPinValue(Port_B,Pin_0,high);
			CLCD_VidGoToXY(1,10);
		/* print left direction symbol on the screen */
			CLCD_VidWriteString(left_u8String);
			break;
		case '2':
		/* if key '2' is pressed : turn on the right lamps  */
			DIO_VidSetPinValue(Port_B,Pin_1,high);
		/* print right direction symbol on the screen */
			CLCD_VidGoToXY(1,10);
			CLCD_VidWriteString(right_u8String);
			break;
		case '3':
		/* if key '3' is pressed : turn off the lamps  */
			DIO_VidSetPinValue(Port_B,Pin_0,low);
			DIO_VidSetPinValue(Port_B,Pin_1,low);
		/* Clear LCD screen */
			CLCD_VidSendCommand(1);
			break;
	}
}

int main()
{
	/* variable to control the sense control of the external interrupt 0 */
	u8 Sense_u8Control =0;
	/* local variable to save the distance value */
	u32 Local_u32Distance;

	/* warning string in case the car is close to hit */
	u8 warning_string[]="Too Close. Stop!";
	/* safety string in case the car is in an acceptable range before hitting */
	u8 Safe_u8String[]="still safe      ";
	/* string to print "cm" after the distance number */
	u8 Cm_u8String[]="cm";
	/* strings to clear the LCD without clearing the lamp symbol  */
	u8 Empty_u8String1[]="     ";
	u8 Empty_u8String2[]="               ";

	/* set the car lamps pins as outputs */
	DIO_VidSetPinDirection(Port_B,Pin_0,output);
	DIO_VidSetPinDirection(Port_B,Pin_1,output);
	/* initially turn off the lamps */
	DIO_VidSetPinValue(Port_B,Pin_0,low);
	DIO_VidSetPinValue(Port_B,Pin_1,low);

	/* set the external interrupt 0 pin as input */
	DIO_VidSetPinDirection(Port_D,Pin_2,input);
	/* set the pin 3 on port as output to use it to trigger the external interrupt */
	DIO_VidSetPinDirection(Port_B,Pin_3,output);

	/* set the directions of the keypad pins */
	DIO_VidSetPortDirection(KPD_u8PORT,0b00001111);
	/* Necessary action: activating internal pull up resistors for keypad pins by writing high on them */
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW0_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW1_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW2_PIN,high);
	DIO_VidSetPinValue(KPD_u8PORT,KPD_u8ROW3_PIN,high);


	/*set the task of external interrupt 0 ISR */
	EXTI_INT0_Call_Back(ExternalInterupt);

	/*set the task of SPI communication protocol ISR */
	SPI_INT_Call_Back(SPI_IntReceive,Global_u8SPIPointerToData);

	/* initialize LCD */
	CLCD_VidInit();

	/* initialize SPI communication protocol : slave mode */
	SPI_Void_Init_Slave();

	/* initialize ultra sonic sensor */

	UltraSonic_voidInit();
	/* enable external interrupt 0 to control the lightening system */
	EXTI0_Vid_Init();

	/* global enable for the interrupts */
	GIE_Vid_Enable();


	while(1)
	{
		/* get the distance in cm from ultra-sonic */
		Local_u32Distance= (u16)UltraSonic_f64Read();

		/* map the given value in a range of 0 to 100 cm */
		Local_u32Distance= Map_u16Function(Local_u32Distance,100,1120,0,100);

		/* convert the distance number to string to print on LCD */
		u8 Distance_u8String[6]={0};
		intTo_u16Str(Local_u32Distance,Distance_u8String,2);

		/* print the distance on the first line */
		if((Local_u32Distance < 35) && (Local_u32Distance >= 0))
		{
			/* the car is too close to collide */
			Global_u8SmallDistanceFlag =1;
			/* print warning string on the first line */
			CLCD_VidGoToXY(0,0);
			CLCD_VidWriteString(warning_string);
			/* print the distance on the second line */
			CLCD_VidGoToXY(1,0);
			CLCD_VidWriteString(Distance_u8String);
			/* print "cm" after the distance */
			CLCD_VidGoToXY(1,3);
			CLCD_VidWriteString(Cm_u8String);
		}
		else if(Local_u32Distance < 99)
		{
			Global_u8SmallDistanceFlag =0;
			/* print safety string on the first line */
			CLCD_VidGoToXY(0,0);
			CLCD_VidWriteString(Safe_u8String);
			/* print the distance on the second line */
			CLCD_VidGoToXY(1,0);
			CLCD_VidWriteString(Distance_u8String);
			/* print "cm" after the distance */
			CLCD_VidGoToXY(1,3);
			CLCD_VidWriteString(Cm_u8String);
		}
		else
		{
			/* print no strings or distance if you are away from the surroundings by 1 meter or more */
			CLCD_VidGoToXY(0,0);
			CLCD_VidWriteString(Empty_u8String2);
			CLCD_VidGoToXY(1,0);
			CLCD_VidWriteString(Empty_u8String1);
		}
		 	 /* check if a key is pressed on keypad */
		key_u8Value = KPD_u8GetPresssedKey();
		if(key_u8Value != NOT_PRESSED)
		{
			/* trigger the external interrupt by making a change in the pulse */
			Sense_u8Control = ! Sense_u8Control;
			DIO_VidSetPinValue(Port_B,Pin_3,Sense_u8Control);
		}

	}
	return 0;
}

