/*
 * main.c
 *
 *  Created on: Aug 19, 2021
 *      Author: AbdElRahman
 */
#include "LIB/Datatypes.h"
#include "LIB/Bit_Operations.h"
#include <util/delay.h>

#include "MCAL/DIO_Interface.h"

#include "HAL/LCD/CLCD_Interface.h"
#include "HAL/LCD/CLCD_Config.h"

#define Code_Select 2


#if Code_Select == 1
/*						one motor two direction								*/
void main (void){

	/*one motor two direction DIO*/
	DIO_VidSetPinDirection(Port_D,Pin_0,input);
	DIO_VidSetPinDirection(Port_D,Pin_1,output);



	while(1){
		/*one motor two directions DIO*/
		u8 pinval = 0;
		DIO_VidGetPinValue(Port_D,Pin_0,&pinval);
		if(pinval == 0){
			DIO_VidSetPinValue(Port_D,Pin_1,high);
		}
		else
			DIO_VidSetPinValue(Port_D,Pin_1,low);

	}


}
#elif Code_Select == 2
void main (void){

	/*H Bridge DIO Init */
	DIO_VidSetPinDirection(Port_A,Pin_0,output); /*PortA,Pin0 As OutPut*/
	DIO_VidSetPinDirection(Port_A,Pin_1,output); /*PortA,Pin1 As OutPut*/
	DIO_VidSetPinDirection(Port_A,Pin_5,input);  /*PortA,Pin5 As Input*/
	DIO_VidSetPinDirection(Port_A,Pin_6,input);  /*PortA,Pin6 As Input*/
	DIO_VidSetPinValue(Port_A,Pin_5,high);		 /*Internal Pull-up Activation*/
	DIO_VidSetPinValue(Port_A,Pin_6,high);		 /*Internal Pull-up Activation*/

	/*LCD Init*/
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,output);
	DIO_VidSetPinDirection(CLCD_CTRL_PORT,CLCD_EN_PIN,output);
	DIO_VidSetPortDirection(CLCD_DATA_PORT, output);
	CLCD_VidInit(); /*Initializes the LCD*/


	while(1){
		/*H Bridge DIO*/
		u8 DC_u8getval1 = 1 ;
		u8 DC_u8getval2 = 1 ;
		DIO_VidGetPinValue(Port_A,Pin_5,&DC_u8getval1);
		DIO_VidGetPinValue(Port_A,Pin_6,&DC_u8getval2);
		if(DC_u8getval1==1 && DC_u8getval2==0){
			DIO_VidSetPinValue(Port_A,Pin_0,high);
			DIO_VidSetPinValue(Port_A,Pin_1,low);
			/*Turn Left*/
			CLCD_VidLcdClear();
			CLCD_VidSendString("Turn_Left");
			/*stay here and check for a change in value*/
			while(DC_u8getval1==1 && DC_u8getval2==0){
				DIO_VidGetPinValue(Port_A,Pin_5,&DC_u8getval1);
				DIO_VidGetPinValue(Port_A,Pin_6,&DC_u8getval2);
			}
		}
		else if(DC_u8getval1==0 && DC_u8getval2==1){
			DIO_VidSetPinValue(Port_A,Pin_0,low);
			DIO_VidSetPinValue(Port_A,Pin_1,high);
			/*Turn Right*/
			CLCD_VidLcdClear();
			CLCD_VidSendString("Turn_Right");
			/*stay here and check for a change in value*/
			while(DC_u8getval1==0 && DC_u8getval2==1){
				DIO_VidGetPinValue(Port_A,Pin_5,&DC_u8getval1);
				DIO_VidGetPinValue(Port_A,Pin_6,&DC_u8getval2);
			}

		}
		else if(DC_u8getval1 ==0 && DC_u8getval2 ==0){
			DIO_VidSetPinValue(Port_A,Pin_0,low);
			DIO_VidSetPinValue(Port_A,Pin_1,low);
			/*Stop, Error*/
			CLCD_VidLcdClear();
			CLCD_VidSendString("Error");
			/*stay here and check for a change in value*/
			while(DC_u8getval1==0 && DC_u8getval2==0){
				DIO_VidGetPinValue(Port_A,Pin_5,&DC_u8getval1);
				DIO_VidGetPinValue(Port_A,Pin_6,&DC_u8getval2);
			}
		}
/*		else{
			DIO_VidSetPinValue(Port_A,Pin_0,low);
			DIO_VidSetPinValue(Port_A,Pin_1,low);
			Stop
			CLCD_VidSendString("Breaks");
		}*/
	}/*End of Super Loop*/


}

#endif
