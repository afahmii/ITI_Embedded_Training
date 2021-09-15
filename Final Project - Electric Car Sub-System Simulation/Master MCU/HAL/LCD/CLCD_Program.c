/*include std and global libiraries*/

#include "../../LIB/Bit_Operations.h"
#include "../../LIB/Datatypes.h"
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

/*MCAL Layer*/
#include "../../MCAL/DIO/DIO_Interface.h"/*Linking HAL TO MCAL*/

/*OWN Program Libirary*/
#include "CLCD_Interface.h"
#include "CLCD_Config.h"



void CLCD_VidPortINIT(void){
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_EN_PIN,output);
	DIO_VidSetPortDirection(CLCD_DATA_PORT, output);
}


void CLCD_VidSendCommand(u8 Copy_u8Command){

	/*set RS pin as low*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN,low );
	/*set RW pin low to write*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN,low );
	/*send commands to data pins */
	DIO_VidSetPortVal(CLCD_DATA_PORT, Copy_u8Command);
	/*send enable pulse*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_EN_PIN,high);
	/*delay*/
	_delay_ms(3);
	/*Clear enable pin (Pulse Complete)*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_EN_PIN,low);
}

void ClCD_VidSendData(u8 Copy_u8Data ){

	/*set RS pin as high*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN,high );
	/*set RW pin low to write*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN,low );
	/*send commands to data pins */
	DIO_VidSetPortVal(CLCD_DATA_PORT, Copy_u8Data);
	/*send enable pulse*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_EN_PIN,high);
	/*delay*/
	_delay_ms(3);
	/*Clear enable pin (Pulse Complete)*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT,CLCD_EN_PIN,low);
}
void CLCD_VidInit(void){
	_delay_ms(40);
	/*Function Set Command*/
	CLCD_VidSendCommand(0b00111111);
	/*Display on/off control command*/
	CLCD_VidSendCommand(0b00001111);
	/*Display Clear command*/
	CLCD_VidSendCommand(1);
}
void CLCD_VidGotoXY (u8 Copy_u8XPos,u8 Copy_u8YPos){ /*x from 0 to 1 -------- y from 0 to 16*/
	u8 Local_u8Address = 0 ;
	if(Copy_u8XPos ==0){
		Local_u8Address = Copy_u8YPos;
	}
	else if(Copy_u8XPos==1 ){
		Local_u8Address = 0x40 + Copy_u8YPos;
	}
	/*0b1000000 ----> 128 */
	CLCD_VidSendCommand(128+Local_u8Address);

}
void CLCD_VidWriteSpecialChar(u8 * Copy_Pu8Pattern, u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos ){

	u8 Local_u8Address = 0;

	Local_u8Address = 8* Copy_u8PatternNumber; /*Generate the wanted location*/

	CLCD_VidSendCommand(64+Local_u8Address); /*Access the wanted location*/

	for (u8 i = 0 ; i<8;i++){
		ClCD_VidSendData(Copy_Pu8Pattern[i]);  /*store data in the location*/
	}
	CLCD_VidGotoXY(Copy_u8XPos,Copy_u8YPos);  /*GO TO RAM*/
	ClCD_VidSendData(Copy_u8PatternNumber); /*Go to first address in CGRAM, Display output sequentially*/
}

void CLCD_VidSendString(u8 * Copy_Pu8Str){
	u8 i = 0;
	while(Copy_Pu8Str[i] != '\0'){

		ClCD_VidSendData(Copy_Pu8Str[i]);
		i++;
	}
}
void CLCD_VidLcdClear(void){
	CLCD_VidSendCommand(1);
}
void CLCD_VidSendNumber(u16 CLCD_u16Number,u8 * CLCD_u8PCharArr){

	sprintf(CLCD_u8PCharArr,CLCD_u16Number);
	CLCD_VidSendString(CLCD_u8PCharArr);

}
void CLCD_VidSendFloatNumber(f64 CLCD_u16Number,u8 * CLCD_u8PCharArr){

	snprintf(CLCD_u8PCharArr,6,"%f",CLCD_u16Number);
	CLCD_VidSendString(CLCD_u8PCharArr);

}
/* function that reverse elements of string */
void reverse(u8* Copy_StringArray, u16 Copy_StringLength)
{
	u8 i = 0, j = (Copy_StringLength - 1) , temp;
	while (i < j) {
		temp = Copy_StringArray[i];
		Copy_StringArray[i] = Copy_StringArray[j];
		Copy_StringArray[j] = temp;
		i++;
		j--;
	}
}
/* function that converts an integer number to string */
u16 intToStr(u16 Copy_u16_IntegerNumber, u8 Copy_StringArray[], u16 Copy_NumberOfDigits)
{
	u16 i = 0;
	while (Copy_u16_IntegerNumber) {
		Copy_StringArray[i++] = (Copy_u16_IntegerNumber % 10) + '0';
		Copy_u16_IntegerNumber = Copy_u16_IntegerNumber / 10;
	}

	/* If number of digits required is more, then
	 add 0s at the beginning */
	while (i < Copy_NumberOfDigits)
		Copy_StringArray[i++] = '0';

	reverse(Copy_StringArray, i);
	Copy_StringArray[i] = '\0';
	return i;
}

