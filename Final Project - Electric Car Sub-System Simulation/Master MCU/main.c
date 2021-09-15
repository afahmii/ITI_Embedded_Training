/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: AbdElRahman
 */
/*Global Libraries*/
#include "LIB/Datatypes.h"
#include "LIB/Bit_Operations.h"
#include "util/delay.h"
#include <stdio.h>
#include <stdlib.h>
/*MCAL*/
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/Timer/Timer_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
/*HAL*/
#include "HAL/MotorDriver/MotorDriver_Interface.h"
#include "HAL/LCD/CLCD_Interface.h"
#include "HAL/Servo/Servo_Interface.h"

/*Macros*/
/*Code Switching Macros*/
#define Wipers 		1
#define Motors 		0
#define distance 	2
#define AIRBAG 		3
#define CarStop		4
#define Wiper_unactive 	1
#define Wiper_Active	0
#define airbag_active 65
#define airbag_unactive 0
#define carspeed_high 70

/*Global Variables Initialization*/
u8 Global_u8PWM;								/*Store PWM*/
u8 Global_u8RPM;								/*Store Km/h*/
u8 Local_u8StatusCombined = Stop;				/*Combined Status of All switches*/
u8 Global_u8TotalDistance = 0;					/*Total Distance*/
u8 Codestate = Motors;							/*Start the Code Initially by running the motors code segment*/
u8 Wiper_flag1 = Wiper_unactive ;				/*Initial status of the Wiper is Inactive*/
u8 Global_u8RPMArr[20]= {0};					/*Store Km/h as a String in this array*/
u8 Global_u8DistanceArr[20] = {0};				/*Array to Store Distance*/
u8 Global_u8AirBagStatue = airbag_unactive;		/*Initial status of air bag is inactive*/
extern st_TIMER2 timer_2;						/*Timer 2 st_TIMER2 type variable*/
extern st_spi_init SPI_INIT;					/*SPI st_spi_init type Variable*/

/*ISR functions Prototypes*/
void Servo_vidSwipeOnce(void);
void Timer2Counter_flags(void);

/*Entry Point*/
void main(void){

	/*Local Variables Initialization*/
	u8 Local_Stoparr[] 		= 	{"Stopped "};
	u8 Local_Forwardarr[] 	= 	{"Forward "};
	u8 Local_Reversearr[] 	= 	{"Reverse "};
	u8 Local_Rightarr[] 	= 	{"Right   "};
	u8 Local_Leftarr[] 		= 	{"Left    "};
	u8 Local_Speedarr[] 	= 	{"s:"};
	u8 Local_Blankarr[] 	= 	{"         "};
	u8 Local_Unitarr[] 		= 	{"km/h"};
	u8 Local_UnitKMarr[] 	= 	{"km"};
	u8 Local_u8S1 = 2;								/*S1 Status*/
	u8 Local_u8S2 = 2;								/*S2 Status*/
	u8 Local_u8S3 = 2;								/*S3 Status*/

	/*Functions Calling*/
	DIO_VidSetPinDirection(Port_B,Pin_4,output);	/*SS*/
	DIO_VidSetPinValue(Port_B,Pin_4,low);			/*SS Pulled low*/
	DIO_VidSetPinDirection(Port_B,Pin_5,output);	/*MOSI*/
	DIO_VidSetPinDirection(Port_B,Pin_6,input);		/*MISO*/
	DIO_VidSetPinDirection(Port_B,Pin_7,output);	/*CLK*/
	EXTI0_CallBack(Servo_vidSwipeOnce);				/*Linking Function to ISR	-	Wiping Function*/
	TIMER2_SetCallBack(Timer2Counter_flags);		/*Linking Function to ISR	-	Timer2 Scheduler*/
	DIO_VidSetPinDirection(Port_D,Pin_2,input);		/*External Interrupt Pin as input - For Servo Switch*/
	DIO_VidSetPinValue(Port_D,Pin_2,high);			/*Pull-up Resistor	- 	For Servo Switch*/
	DIO_VidSetPinDirection(Port_B,Pin_3,output);	/*Timer0 PWM Pin OC0	-	For Motors*/
	DIO_VidSetPinDirection(Port_D,Pin_5,output);	/*Timer1 PWM UnitA Pin OC1A - For Servo PWM*/
	DIO_VidSetPinDirection(Port_D,Pin_7,output);	/*Timer2 PWM - OC2*/
	DIO_VidSetPinDirection(Port_D,Pin_3,output);	/*AIRBag - SPI		*/
	DIO_VidSetPinDirection(Port_D,Pin_4,output);	/*Buzzer - Speed Limit*/
	CLCD_VidPortINIT();								/*Initializes LCD Ports*/
	CLCD_VidInit();									/*Initializes LCD*/
	MotorDriver_VidPortInit();						/*Initialized Switches and Motors Pins*/
	MotorDriver_VidMotorsINIT();  					/*Initializes Timer0_PWM W/ DutyCycle =0*/
	Servo_vidInit();								/*Initializes Timer1 for servo control*/
	TIMER2_VidInit(&timer_2);						/*Initializes Timer2 - PWM*/
	ADC_VidInit();									/*Initializes ADC*/
	EXTI0_VidIntInit();								/*Initializes External Interrupt 0	-	Falling Edge Sense Control*/
	SPI_VidInit(&SPI_INIT);							/*Initializes SPI - Interrupt is on*/
	GIE_VidEnable();								/*Enable Global Interrupt*/

	/*Super loop*/
	while(1){
		/*Get ADC Value, Convert it to PWM*/
		Global_u8PWM = MotorDriver_VidChangeSpeed();
		/*Map PWM into km/h*/
		Global_u8RPM = ADC_VidMapping(Global_u8PWM,0,255,0,180);
		/*Get Switches Status*/
		MotorDriver_VidGetSwitchesStatus(&Local_u8S1,&Local_u8S2,&Local_u8S3);
		/*Combine Switches Status and turn them into predefined conditions 0~7 (Forward,Left,Right,Reverse,Stop,...Stop)*/
		Local_u8StatusCombined = (Local_u8S3<<2)|(Local_u8S2<<1)|(Local_u8S1);

		/*Code Status*/
		/*--------------------------------------------------*/
		/*						AIRBag						*/
		if(Codestate == AIRBAG){
			if(Global_u8AirBagStatue == airbag_active){
				DIO_VidSetPinValue(Port_D,Pin_3,high);
				Codestate = CarStop;
			}
		}
		/*--------------------------------------------------*/
		/*						Wipers						*/
		if(Codestate == Wipers){
			if(Wiper_flag1 == Wiper_Active){
				Servo_vidSwipe();
				Codestate = Motors;
			}
		}
		/*--------------------------------------------------*/
		/*					Distance Calculator				*/
		else if(Codestate == distance){
			CLCD_VidGotoXY(1,10);
			intToStr(Global_u8TotalDistance,&Global_u8DistanceArr[0],4);
			CLCD_VidSendString(Global_u8DistanceArr);
			CLCD_VidSendString(Local_UnitKMarr);
			Codestate = Motors;
		}
		/*--------------------------------------------------*/
		/*						Motors						*/
		else if(Codestate == Motors){
			/*if PWM equals zero, Stop the motors*/
			if(Global_u8PWM == 0){
				Local_u8StatusCombined = Stop;
			}
			if(Global_u8RPM >= 120 ){
				DIO_VidSetPinValue(Port_D,Pin_4,high);
			}
			else if(Global_u8RPM < 120){
				DIO_VidSetPinValue(Port_D,Pin_4,low);
			}
			switch(Local_u8StatusCombined){
				case Stop:
					MotorDriver_VidStop();
					CLCD_VidGotoXY(0,0);
					CLCD_VidSendString(Local_Stoparr);
					CLCD_VidGotoXY(1,0);
					CLCD_VidSendString(Local_Blankarr);
					break;
				case Right:
					MotorDriver_VidRight();
					CLCD_VidGotoXY(0,0);
					CLCD_VidSendString(Local_Rightarr);
					intToStr(Global_u8RPM,Global_u8RPMArr,3);
					CLCD_VidGotoXY(1,0);
					CLCD_VidSendString(Local_Speedarr);
					CLCD_VidSendString(Global_u8RPMArr);
					CLCD_VidSendString(Local_Unitarr);
					break;
				case Left:
					MotorDriver_VidLeft();
					CLCD_VidGotoXY(0,0);
					CLCD_VidSendString(Local_Leftarr);
					intToStr(Global_u8RPM,Global_u8RPMArr,3);
					CLCD_VidGotoXY(1,0);
					CLCD_VidSendString(Local_Speedarr);
					CLCD_VidSendString(Global_u8RPMArr);
					CLCD_VidSendString(Local_Unitarr);
					break;
				case Forwrd:
					MotorDriver_VidForward();
					CLCD_VidGotoXY(0,0);
					CLCD_VidSendString(Local_Forwardarr);
					intToStr(Global_u8RPM,Global_u8RPMArr,3);
					CLCD_VidGotoXY(1,0);
					CLCD_VidSendString(Local_Speedarr);
					CLCD_VidSendString(Global_u8RPMArr);
					CLCD_VidSendString(Local_Unitarr);
					break;
				case Backward:
					MotorDriver_VidBackward();
					CLCD_VidGotoXY(0,0);
					CLCD_VidSendString(Local_Reversearr);
					intToStr(Global_u8RPM,Global_u8RPMArr,3);
					CLCD_VidGotoXY(1,0);
					CLCD_VidSendString(Local_Speedarr);
					CLCD_VidSendString(Global_u8RPMArr);
					CLCD_VidSendString(Local_Unitarr);
					break;
				default:
					MotorDriver_VidStop();
					CLCD_VidGotoXY(0,0);
					CLCD_VidSendString(Local_Stoparr);
					CLCD_VidGotoXY(1,0);
					CLCD_VidSendString(Local_Blankarr);
					break;
			}/*End of Switch Function*/
		}
		else if(Codestate == CarStop){
			MotorDriver_VidStop();
			CLCD_VidGotoXY(0,0);
			CLCD_VidSendString(Local_Stoparr);
			CLCD_VidGotoXY(1,0);
			CLCD_VidSendString(Local_Blankarr);
			while(1);
		}/*End of Code Segments */
	}/*End of Super Loop*/
}/*End of main*/

void Servo_vidSwipeOnce(void){
	Codestate = Wipers;
}
void Timer2Counter_flags(void){
	/*
	 * Timer2 ISR every 1ms,
	 * If Counter = 1000, then 1s passes
	 * */
	static u16 Local_u16MainCounter = 0;
	static u8  Local_u8SPICounter	= 5;		/*offset 5ms SPI tranceive */
	static u16 Local_u16DistanceCounter = 10;	/*offset 10ms from main counter*/
	static u32 Local_u32TotalDistance = 0;
	static u16 Global_u16SpeedSnap1 = 0;
	static u16 Global_u16AVGSpeed = 0;
	static u16 Global_u16AVGDistance =0;
	u8 Local_DistanceTemp = 0;
	Local_u16MainCounter ++;
	Local_u16DistanceCounter++;
	Local_u8SPICounter++;
	/*----------------Wipe-------------------*/
	/*Every 50 ms, check if "Codestate" changed (External Interrupt fired), Set Wiper_flag1 to active*/
	if(Local_u16MainCounter == 50){
		if(Codestate == Wipers){
			Wiper_flag1 = Wiper_Active;
		}
		Local_u16MainCounter = 0;
	}
	/*----------------Distance-------------------*/
	if(Local_u16DistanceCounter == 60){
		/*get the first snap*/
		Global_u16SpeedSnap1 = Global_u8RPM;
	}
	else if(Local_u16DistanceCounter == 1060){
		/*Get AVG every 1s*/
		/*if the car is not stopped, Calculate Average*/
		if(Local_u8StatusCombined != (Stop||CarStop)){
			Global_u16AVGSpeed = (Global_u16SpeedSnap1 + Global_u8RPM)/2;	/*Get Speed AVG every 1s*/
			Global_u16AVGDistance = (Global_u16AVGSpeed * 18)/(5);			/*Get Distance AVG every 1s*/
			Local_u32TotalDistance += Global_u16AVGDistance;				/*Calculate Total Distance in m/s*/
			Local_DistanceTemp = Local_u32TotalDistance /1000;				/*Total Distance in Km*/
			Global_u8TotalDistance = Local_DistanceTemp;					/*Return Total Distance*/
			Codestate = distance; 											/*Switch Code state to distance*/
		}
		Local_u16DistanceCounter =0;
	}
	/*----------------SPI-------------------*/
	if (Local_u8SPICounter == 105){
		if(Global_u8RPM>50){
		Global_u8AirBagStatue = SPI_Transceive(carspeed_high);
		Codestate = AIRBAG;
		}
		Local_u8SPICounter = 0;
	}
}

