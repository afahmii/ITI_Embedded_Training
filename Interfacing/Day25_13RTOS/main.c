/*
 * main.c
 *
 *  Created on: Sep 6, 2021
 *      Author: AbdElRahman
 */

#include "LIB/Datatypes.h"
#include "LIB/Bit_Operations.h"
#include "ServiceLayer/RTOS_Interface.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/Timer/Timer_Interface.h"
void Task0(void);
void Task1(void);
void Task2(void);
void Task3(void);
void Task4(void);

void main(void){

	DIO_VidSetPinDirection(Port_A,Pin_0,output);
	DIO_VidSetPinDirection(Port_A,Pin_1,output);
	DIO_VidSetPinDirection(Port_A,Pin_2,output);
	DIO_VidSetPinDirection(Port_A,Pin_3,output);
	DIO_VidSetPinDirection(Port_A,Pin_4,output);

	RTOS_u8CreateTask(0,400,Task0);
	RTOS_u8CreateTask(1,800,Task1);
	RTOS_u8CreateTask(2,1200,Task2);
	RTOS_u8CreateTask(3,1600,Task3);
	RTOS_u8CreateTask(4,2000,Task4);

	RTOS_VidStart();
	while(1){

		RTOS_VidDispatcher();
	}

}
void Task0(void){
	static u8 state =1;
	state =! state;
	DIO_VidSetPinValue(Port_A,Pin_0,state);
}
void Task1(void){
	static u8 state =1;
	state =! state;
	DIO_VidSetPinValue(Port_A,Pin_1,state);
}
void Task2(void){
	static u8 state =1;
	state =! state;
	DIO_VidSetPinValue(Port_A,Pin_2,state);
}
void Task3(void){
	static u8 state =1;
	state =! state;
	DIO_VidSetPinValue(Port_A,Pin_3,state);
}
void Task4(void){
	static u8 state =1;
	state =! state;
	DIO_VidSetPinValue(Port_A,Pin_4,state);
}



