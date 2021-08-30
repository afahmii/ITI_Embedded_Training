/*include std and global libiraries*/

#include "../Bit_Operations.h"
#include "../Datatypes.h"
#include <util/delay.h>

/*MCAL Layer*/
#include "../MCAL/DIO_Interface.h"/*Linking HAL TO MCAL*/

/*OWN Program Libirary*/
#include "CLCD_Interface.h"
#include "CLCD_Config.h"






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


void CLCD_VidInit(void){


	_delay_ms(40);
	/*Function Set Command*/
	CLCD_VidSendCommand(0b00111111);
	/*Display on/off control command*/
	CLCD_VidSendCommand(0b00001110);
	/*Display Clear command*/
	CLCD_VidSendCommand(1);
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
