/*
 * main.c

 *
 *  Created on: Aug 29, 2021
 *      Author: AbdElRahman
 */
/*Global Libraries*/
#include "LIB/Datatypes.h"
#include "LIB/Bit_Operations.h"
#include <util/delay.h>
#include <stdio.h>

/*MCAL*/
#include "MCAL/UART/UART_Interface.h"
#include "MCAL/UART/UART_Private.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"

#define Code_Select 4

#if Code_Select == 1
/*						Send And Receive String						*/

#define ArrLen 20 /*Select Array Length*/
extern st_uart_init UART_INIT;
extern st_uart_int UART_INT;
void main (void){
	/*Send myname as a string*/
	u8 arr[] = {'A','B','D','E','L','R','A','H','M','A','N',NULL};
	u8 arr1[ArrLen]= {0};				/*Array to store Received String*/
	UART_VidTransmitterEnable();		/*Enable TX*/
	UART_VidReceiverEnable();			/*Enable RX*/
	UART_Vidinit(&UART_INIT);			/*UART INIT*/
//UART_VidTransmit(UART_u8Receive());	/*Send the Received Char*/
	UART_VidRecString(arr1,ArrLen);		/*Receive String in arr1*/
	UART_VidSendString(arr1);			/*Display arr1*/
	while(1){}
}


#elif Code_Select == 2
/*						LED ANIMATION						*/
s8 right =4 ,left =3;
s8 first =0 ,last =7;
s8 snake_c ;
static u8 x = 255 ;
extern st_uart_init UART_INIT;
extern st_uart_int UART_INT;
void main ()
{

	/* Set Port_A as output */
	DIO_VidSetPortDirection(Port_A,output);
	UART_VidTransmitterEnable();		/*Enable TX*/
	UART_VidReceiverEnable();			/*Enable RX*/
	UART_Vidinit(&UART_INIT);			/*UART INIT*/

	while(1){
		switch (UART_u8Receive()){
			case 'a' :
				x = ~x;
				DIO_VidSetPortVal(Port_A,x);
				_delay_ms(300);
				break;
			case  'b':
				for(u8 i = 0 ; i < 8 ; i++){
					DIO_VidSetPortVal(Port_A, 0x00);
					DIO_VidSetPinValue(Port_A,i,high);
					_delay_ms(300);
				}
				break;
			case 'c' :
				for(s8 i = 7 ; i >= 0 ; i--){
					DIO_VidSetPortVal(Port_A,0);
					DIO_VidSetPinValue(Port_A,i,high);
					_delay_ms(250);
				}
				break;
			case 'd'  :
				DIO_VidSetPortVal(Port_A,0);
				_delay_ms(300);
				for(u8 i = 0 ; i < 4 ; i++){
					DIO_VidSetPinValue(Port_A,first,high);
					DIO_VidSetPinValue(Port_A,last,high);
					last --;
					first++;
					_delay_ms(300);
				}
				first = 0 ;
				last = 7 ;
				break;
			case 'e'   :
				DIO_VidSetPortVal(Port_A,0);
				_delay_ms(300);
				for(u8 i = 0 ; i < 4 ; i++){
					DIO_VidSetPinValue(Port_A,right,high);
					DIO_VidSetPinValue(Port_A,left,high);
					left --;
					right++;
					_delay_ms(300);
				}
				right = 4 ;
				left = 3 ;
				break;
			case 'f'   :
				for(u8 i = 0 ; i < 8 ; i++){
					DIO_VidSetPortVal(Port_A,0);
					DIO_VidSetPinValue(Port_A,i,high);
					_delay_ms(250);
				}
				for(s8 i = 7 ; i >= 0 ; i--){
					DIO_VidSetPortVal(Port_A,0);
					DIO_VidSetPinValue(Port_A,i,high);
					_delay_ms(250);
				}
				break;
			case 'g'       :
				DIO_VidSetPortVal(Port_A,0);
				for(u8 i = 0 ; i < 8 ; i++){
					DIO_VidSetPinValue(Port_A,i,high);
					_delay_ms(300);
				}
				break;
			case 'h'    :
				for(u8 i = 0 ; i < 4 ; i++)	{
					DIO_VidSetPortVal(Port_A,0);
					DIO_VidSetPinValue(Port_A,first,high);
					DIO_VidSetPinValue(Port_A,last,high);
					last --;
					first++;
					_delay_ms(300);
				}
				for(u8 i = 0 ; i < 4 ; i++){
					DIO_VidSetPortVal(Port_A,0);
					DIO_VidSetPinValue(Port_A,right,high);
					DIO_VidSetPinValue(Port_A,left,high);
					left --;
					right++;
					_delay_ms(300);
				}
				right = 4 ;
				left = 3 ;
				first = 0 ;
				last = 7 ;
				break;
		}
	}
}



#elif Code_Select == 3
/*								ADC READ						*/
extern st_uart_init UART_INIT;
extern st_uart_int UART_INT;
void main(void){
	u8 Local_u8CharArr[10]={0};

	DIO_VidSetPinDirection(Port_A,Pin_0,input); /*ADC0 pin*/
	UART_VidTransmitterEnable();		/*Enable TX*/
	UART_VidReceiverEnable();			/*Enable RX*/
	UART_Vidinit(&UART_INIT);			/*UART INIT*/
	ADC_VidInit();
	while(1){
	u8 Local_ADCTemp = ADC_u8ReadChannel(ADC_0);
	u16 mv_read = ADC_f32LCDVoltConv(Local_ADCTemp);
	snprintf(Local_u8CharArr,7,"%d",mv_read);
	UART_VidSendString(Local_u8CharArr);
	UART_VidTransmit('\r');
	_delay_ms(1000);
	}
}



#elif Code_Select == 4
/*						ADC INT	Receive					*/
extern st_uart_init UART_INIT;
extern st_uart_int UART_INT;
void UART_INTRead_TASK(void){
	if(UDR == 'a'){
		DIO_VidSetPinValue(Port_A,Pin_2,high);
	}
}
void main(void){
	DIO_VidSetPinDirection(Port_A,Pin_2,output);
	RXComplete_CallBack(UART_INTRead_TASK);
	UART_VidTransmitterEnable();		/*Enable TX*/
	UART_VidReceiverEnable();			/*Enable RX*/
	UART_Vidinit(&UART_INIT);			/*UART INIT*/
	GIE_VidEnable();
	UART_INT.STM_RX_Status = UART_RX_Complete_INT_Enabled;
	UART_VidInterruptInit(&UART_INT);

	while(1){
	}
}



#endif
