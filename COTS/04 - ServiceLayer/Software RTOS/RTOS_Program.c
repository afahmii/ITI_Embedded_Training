#include "../LIB/Datatypes.h"
#include "../LIB/Bit_Operations.h"

#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/Timer/Timer_Interface.h"
#include "../MCAL/Timer/Timer_Config.h"
#include "../MCAL/DIO/DIO_Interface.h"

#include "RTOS_Config.h"
#include "RTOS_Interface.h"
#include "RTOS_Private.h"


extern st_TIMER0 timer_0;
st_TaskControlBlock TaskBlockArr[RTOS_TASK_NO] = {{NULL}}; /*Equivalent to {{0},{0},{0}} for every array*/

void RTOS_VidStart(void){

	/*Init Timer - OCR0 = 125, Prescaler = 64*/
	TIMER0_VidInit(&timer_0);
	/*Set Call Back of Algorithm*/
	TIMER0_SetCallBack(RTOS_VidAlgorithm);
	/*Enable Global Int*/
	GIE_VidEnable();
}
u8 RTOS_u8CreateTask(u8 Cpy_u8Priority, u16 Cpy_u16Periodicity, void (*func)(void)){

	u8 Local_err = No_Error;
	if((Cpy_u8Priority < RTOS_TASK_NO) && (func != NULL)){
	TaskBlockArr[Cpy_u8Priority].peridoicity = Cpy_u16Periodicity;
	TaskBlockArr[Cpy_u8Priority].TaskFunc = func;
	TaskBlockArr[Cpy_u8Priority].RunMe = 0;
	TaskBlockArr[Cpy_u8Priority].TaskCounter = 0;
	}
	else {
		Local_err = Error;
	}
	return Local_err;
}
static void RTOS_VidAlgorithm(void){
	/*Check on All The Tasks Using For Loop*/

	for(u8 Local_u8Counter = 0; Local_u8Counter<RTOS_TASK_NO ; Local_u8Counter ++){
		/*Check if Task Exists*/
		if(	TaskBlockArr[Local_u8Counter].TaskFunc != NULL){
			/*Check on Counter if counter ==0*/
			if(TaskBlockArr[Local_u8Counter].TaskCounter ==0){

				/*Set Flag*/
				TaskBlockArr[Local_u8Counter].RunMe =1;
				/*Update Counter = Periodicity*/
				TaskBlockArr[Local_u8Counter].TaskCounter =TaskBlockArr[Local_u8Counter].peridoicity;
			}
			else {
				/*Decrement the Counter*/
				TaskBlockArr[Local_u8Counter].TaskCounter--;
			}
		}
	}
	//DIO_VidSetPinValue(Port_A,Pin_7,low);
}

void RTOS_VidDispatcher(void){
	for(u8 Local_u8Counter = 0; Local_u8Counter<RTOS_TASK_NO ; Local_u8Counter ++){
		if(	TaskBlockArr[Local_u8Counter].TaskFunc != NULL){
			if(TaskBlockArr[Local_u8Counter].RunMe == 1){
				TaskBlockArr[Local_u8Counter].RunMe = 0; /*Reset flag*/
				TaskBlockArr[Local_u8Counter].TaskFunc();
			}
		}
	}
}

static void RTOS_Sleep(void){

}
