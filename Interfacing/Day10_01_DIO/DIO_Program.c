#include "LIB/Datatypes.h"
#include "LIB/Bit_Operations.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"


/*-------------------------------------------------------------------------------------------------------------------------*/
								/**************************set pin*****************************/
/*-------------------------------------------------------------------------------------------------------------------------*/


void DIO_VidSetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8State ){

	/****************** set pin as input***********************/
	if(Copy_u8State == low){
		switch (Copy_u8Port) {
			case (Port_A) : CLR_Bit(PORTA,Copy_u8PinNumber);break;
			case (Port_B) : CLR_Bit(PORTB,Copy_u8PinNumber);break;
			case (Port_C) : CLR_Bit(PORTC,Copy_u8PinNumber);break;
			case (Port_D) : CLR_Bit(PORTD,Copy_u8PinNumber);break;
		}
	}
	/****************** set pin as output***********************/
	else if(Copy_u8State == high){
		switch (Copy_u8Port) {
			case (Port_A) : Set_Bit(PORTA,Copy_u8PinNumber);break;
			case (Port_B) : Set_Bit(PORTB,Copy_u8PinNumber);break;
			case (Port_C) : Set_Bit(PORTC,Copy_u8PinNumber);break;
			case (Port_D) : Set_Bit(PORTD,Copy_u8PinNumber);break;
		}
	}
}

void DIO_VidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8PinNumber,u8 Copy_u8PinDirection)
{
	/****************** set pin as input***********************/
	if(Copy_u8PinDirection == input){
		switch (Copy_u8Port) {
			case (Port_A) : CLR_Bit(DDRA,Copy_u8PinNumber);break;
			case (Port_B) : CLR_Bit(DDRB,Copy_u8PinNumber);break;
			case (Port_C) : CLR_Bit(DDRC,Copy_u8PinNumber);break;
			case (Port_D) : CLR_Bit(DDRD,Copy_u8PinNumber);break;
		}
	}
	/****************** set pin as output***********************/
	else if(Copy_u8PinDirection == output){
		switch (Copy_u8Port) {
			case (Port_A) : Set_Bit(DDRA,Copy_u8PinNumber);break;
			case (Port_B) : Set_Bit(DDRB,Copy_u8PinNumber);break;
			case (Port_C) : Set_Bit(DDRC,Copy_u8PinNumber);break;
			case (Port_D) : Set_Bit(DDRD,Copy_u8PinNumber);break;
		}
	}
}


void DIO_VidGetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8* Copy_Pu8PinValue)
{
	/****************** set pin as input***********************/
		switch (Copy_u8Port) {
			case (Port_A) : *Copy_Pu8PinValue = Get_Bit(PINA,Copy_u8PinNumber);break;
			case (Port_B) : *Copy_Pu8PinValue = Get_Bit(PINB,Copy_u8PinNumber);break;
			case (Port_C) : *Copy_Pu8PinValue = Get_Bit(PINC,Copy_u8PinNumber);break;
			case (Port_D) : *Copy_Pu8PinValue = Get_Bit(PIND,Copy_u8PinNumber);break;
		}
}


/*---------------------------------------------------------------------------------------------------------------------------------*/
									/************************set port************************/
/*---------------------------------------------------------------------------------------------------------------------------------*/


void DIO_VidSetPortVal(u8 Copy_u8Port, u8 Copy_u8State){

	/****************** set Port as High***********************/
	if(Copy_u8State == low){
		switch (Copy_u8Port) {
			case (Port_A) : PORTA = 0x00;break;
			case (Port_B) : PORTB = 0x00;break;
			case (Port_C) : PORTC = 0x00;break;
			case (Port_D) : PORTD = 0x00;break;
		}
	}

	/****************** set Port as Low***********************/
	else if(Copy_u8State == high){
		switch (Copy_u8Port) {
			case (Port_A) : PORTA = 0xff;break;
			case (Port_B) : PORTB = 0xff;break;
			case (Port_C) : PORTC = 0xff;break;
			case (Port_D) : PORTD = 0xff;break;
		}
	}
}

void DIO_VidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	/****************** set Port as input***********************/
	if(Copy_u8Direction == input){
		switch (Copy_u8Port) {
			case (Port_A) : DDRA = 0x00 ;break;
			case (Port_B) : DDRB = 0x00 ;break;
			case (Port_C) : DDRC = 0x00 ;break;
			case (Port_D) : DDRD = 0x00 ;break;
		}
	}

	/****************** set Port as output***********************/
	else if(Copy_u8Direction == output){
		switch (Copy_u8Port) {
			case (Port_A) : DDRA = 0xff ;break;
			case (Port_B) : DDRB = 0xff ;break;
			case (Port_C) : DDRC = 0xff ;break;
			case (Port_D) : DDRD = 0xff ;break;
		}
	}
}

void DIO_VidGetPortValue(u8 Copy_u8Port, u8* Copy_Pu8Value)
{
	switch (Copy_u8Port) {
		case (Port_A) : *Copy_Pu8Value = PINA; break;
		case (Port_B) : *Copy_Pu8Value = PINB; break;
		case (Port_C) : *Copy_Pu8Value = PINC; break;
		case (Port_D) : *Copy_Pu8Value = PIND; break;
	}
}
