/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: AbdElRahman
 */

#include "LIB/Datatypes.h"
#include "LIB/Bit_Operations.h"
#include "util/delay.h"

#include "MCAL/DIO/DIO_Interface.h"

#include "RTOS/FreeRTOS.h"
#include "RTOS/task.h"
#include "RTOS/semphr.h"

void Task1 (void *p);
void Task2 (void *p);
void Task3 (void *p);
void Task4 (void *p);

//SemaphoreHandle_t obj1 ;
void main(void){
	DIO_VidSetPortDirection(Port_D,output);
	xTaskCreate(Task1,		/*Function Address*/
				NULL,		/*Function Name*/
				100,		/*Stack Depth*/
				NULL,		/*Pointer to Void,Will be Passed to the task*/
				1,			/*Priority*/
				NULL);		/*Handle to Control the task, Like delete function*/

	xTaskCreate(Task2,		/*Function Address*/
				NULL,		/*Function Name*/
				100,		/*Stack Depth*/
				NULL,		/*Pointer to Void,Will be Passed to the task*/
				1,			/*Priority*/
				NULL);		/*Handle to Control the task, Like delete function*/

	xTaskCreate(Task3,		/*Function Address*/
				NULL,		/*Function Name*/
				100,		/*Stack Depth*/
				NULL,		/*Pointer to Void,Will be Passed to the task*/
				1,			/*Priority*/
				NULL);		/*Handle to Control the task, Like delete function*/

	xTaskCreate(Task4,		/*Function Address*/
				NULL,		/*Function Name*/
				100,		/*Stack Depth*/
				NULL,		/*Pointer to Void,Will be Passed to the task*/
				1,			/*Priority*/
				NULL);		/*Handle to Control the task, Like delete function*/

	vTaskStartScheduler();  /*Start of RTOS*/

	/**No actions will be taken here**/
	while(1){

	}

}

void Task1 (void *p){

	u8 state = 1 ;
	while(1){
		DIO_VidSetPinValue(Port_D,Pin_0,state);
		vTaskDelay(200); 	/*RTOS will execute other functions in this 1 second delay*/
		//_delay_ms(1000); 	/*Processor is stuck here doing null statements for 1 second*/
		state = !state;
	}
}
void Task2 (void *p){

	u8 state = 1 ;
	while(1){
		DIO_VidSetPinValue(Port_D,Pin_1,state);
		vTaskDelay(400); 	/*RTOS will execute other functions in this 1 second delay*/
		//_delay_ms(1000); 	/*Processor is stuck here doing null statements for 1 second*/
		state = !state;
	}
}
void Task3 (void *p){

	u8 state = 1 ;
	while(1){
		DIO_VidSetPinValue(Port_D,Pin_2,state);
		vTaskDelay(800); 	/*RTOS will execute other functions in this 1 second delay*/
		//_delay_ms(1000); 	/*Processor is stuck here doing null statements for 1 second*/
		state = !state;
	}
}
void Task4 (void *p){

	u8 state = 1 ;
	while(1){
		DIO_VidSetPinValue(Port_D,Pin_3,state);
		vTaskDelay(1000); 	/*RTOS will execute other functions in this 1 second delay*/
		//_delay_ms(1000); 	/*Processor is stuck here doing null statements for 1 second*/
		state = !state;
	}
}
