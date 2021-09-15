
#include "../../LIB/Datatypes.h"
#include "../../LIB/Bit_Operations.h"
#include "util/delay.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer/Timer_Interface.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"

#include "Servo_Interface.h"

extern st_TIMER1_INIT timer1_init;
extern st_TIMER1_CompareMatch timer1_comparematch;
extern st_TIMER1_CompareValue timer1_compareval;


void Servo_vidInit(void){
	DIO_VidSetPinDirection(Port_D,Pin_5,output); 				/*Timer1 OC1A output pin*/
	TIMER1_VidInit(&timer1_init);
	TIMER1_VidSetCompareMatchOutputMode(&timer1_comparematch);
	TIMER1_VidSetTopOVF(20000);									/*Set ICR1 TOP Value "OVERFLOW Value"*/
}

void Servo_vidSwipe(void){
	/*Initially Servo is at -90 Position*/
	timer1_compareval.CompareMatchValue = 2000;	/*90 degrees*/
	TIMER1_VidSetCompareVal(&timer1_compareval);
	_delay_ms(1000);
	timer1_compareval.CompareMatchValue = 1000;	/*-90 degrees*/
	TIMER1_VidSetCompareVal(&timer1_compareval);
}





