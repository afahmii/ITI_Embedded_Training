

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum {
	input,
	output,
	Port_A,
	Port_B,
	Port_C,
	Port_D,
	low = 0,
	high,
	Pin_0 =0,
	Pin_1,
	Pin_2,
	Pin_3,
	Pin_4,
	Pin_5,
	Pin_6,
	Pin_7

}enut_DIO;

					/********************set pin**********************/
void DIO_VidSetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8State );

void DIO_VidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8PinNumber,u8 Copy_u8PinDirection);

void DIO_VidGetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8* Copy_Pu8PinValue);

					/********************set port**********************/

void DIO_VidSetPortVal(u8 Copy_u8Port, u8 Copy_u8Val);

void DIO_VidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

void DIO_VidGetPortValue(u8 Copy_u8Port, u8* Copy_Pu8Value);



#endif /*DIO_INTERFACE_H_*/
