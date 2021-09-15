/*Global Libraries*/
#include "../../LIB/Datatypes.h"
#include "../../LIB/Bit_Operations.h"

/*MCAL*/
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer/Timer_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"

/*HAL*/
#include "MotorDriver_Interface.h"
#include "MotorDriver_Private.h"
#include "MotorDriver_Config.h"

extern st_TIMER0 timer_0;
void MotorDriver_VidPortInit(void){
	/*Set Switches as input*/
	DIO_VidSetPinDirection(Switch_Port,Switch1_Pin,input);
	DIO_VidSetPinDirection(Switch_Port,Switch2_Pin,input);
	DIO_VidSetPinDirection(Switch_Port,Switch3_Pin,input);
	/*Pull-up Resistor Activated*/
	DIO_VidSetPinValue(Switch_Port,Switch1_Pin,high);
	DIO_VidSetPinValue(Switch_Port,Switch2_Pin,high);
	DIO_VidSetPinValue(Switch_Port,Switch3_Pin,high);
	/*Set Motors Direction Pins as output*/
	DIO_VidSetPinDirection(Motor_Port,Motor1A,output);
	DIO_VidSetPinDirection(Motor_Port,Motor1B,output);
	DIO_VidSetPinDirection(Motor_Port,Motor2A,output);
	DIO_VidSetPinDirection(Motor_Port,Motor2B,output);
}

void MotorDriver_VidGetSwitchesStatus(u8* Copy_pS1,u8* Copy_pS2,u8* Copy_pS3){
	/*Get Switches Values, 1 for not pressed, 0 for pressed*/
	DIO_VidGetPinValue(Switch_Port,Switch1_Pin,Copy_pS1);
	DIO_VidGetPinValue(Switch_Port,Switch2_Pin,Copy_pS2);
	DIO_VidGetPinValue(Switch_Port,Switch3_Pin,Copy_pS3);
}
void MotorDriver_VidForward(void){
	/*Motor 1 CW*/
	DIO_VidSetPinValue(Motor_Port,Motor1A,high);
	DIO_VidSetPinValue(Motor_Port,Motor1B,low);
	/*Motor 2 CW*/
	DIO_VidSetPinValue(Motor_Port,Motor2A,high);
	DIO_VidSetPinValue(Motor_Port,Motor2B,low);

}
void MotorDriver_VidBackward(void){
	/*Motor 1 CCW*/
	DIO_VidSetPinValue(Motor_Port,Motor1A,low);
	DIO_VidSetPinValue(Motor_Port,Motor1B,high);
	/*Motor 2 CCW*/
	DIO_VidSetPinValue(Motor_Port,Motor2A,low);
	DIO_VidSetPinValue(Motor_Port,Motor2B,high);

}
void MotorDriver_VidRight(void){
	/*Motor 1 CW*/
	DIO_VidSetPinValue(Motor_Port,Motor1A,high);
	DIO_VidSetPinValue(Motor_Port,Motor1B,low);
	/*Motor 2 CCW*/
	DIO_VidSetPinValue(Motor_Port,Motor2A,low);
	DIO_VidSetPinValue(Motor_Port,Motor2B,high);

}
void MotorDriver_VidLeft(void){
	/*Motor 1 CCW*/
	DIO_VidSetPinValue(Motor_Port,Motor1A,low);
	DIO_VidSetPinValue(Motor_Port,Motor1B,high);
	/*Motor 2 CW*/
	DIO_VidSetPinValue(Motor_Port,Motor2A,high);
	DIO_VidSetPinValue(Motor_Port,Motor2B,low);
}
void MotorDriver_VidStop(void){
	/*Motor 1 Stop*/
	DIO_VidSetPinValue(Motor_Port,Motor1A,low);
	DIO_VidSetPinValue(Motor_Port,Motor1B,low);
	/*Motor 2 STOP*/
	DIO_VidSetPinValue(Motor_Port,Motor2A,low);
	DIO_VidSetPinValue(Motor_Port,Motor2B,low);
}

void MotorDriver_VidMotorsINIT(void){
	TIMER0_VidInit(&timer_0); 	/*DutyCycle = 0*/
	MotorDriver_VidStop();		/*Initial Condition: Car Stopped*/
}
u8 MotorDriver_VidChangeSpeed(void){
	u8 local_u8Speed = 0;
	local_u8Speed = ADC_u8ReadChannel(ADC_3);
	TIMER0_VidDutyCycleSelector_Normal(local_u8Speed);
	return local_u8Speed;
}

