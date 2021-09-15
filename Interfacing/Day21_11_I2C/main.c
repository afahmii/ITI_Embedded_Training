/*
 * main.c
 *
 *  Created on: Aug 31, 2021
 *      Author: AbdElRahman
 */

#include "LIB/Datatypes.h"
#include "LIB/Bit_Operations.h"
#include <util/delay.h>

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/I2C/I2C_Interface.h"



void main (void){

	TWI_VidMasterInit(0x15);
	DIO_VidSetPinDirection(Port_A,Pin_2,output);
	u8 Local_u8MasterRead = 0x55;
	while(1){
		/*EEPROM Read*/
		//TWI_SendStartCondition();
		//TWI_MasterSendAddress(0x51,TWI_Write);
		//TWI_MasterSendData(0x01);
		//TWI_SendStartCondition();
		//TWI_MasterSendAddress(0x51,TWI_Read);
		//TWI_MasterReadData(&Local_u8MasterRead);
		//TWI_SendStopCondition();
		/*End of EEPROM READ*/

		/*EEPROM Write*/
		TWI_SendStartCondition();
		TWI_MasterSendAddress(0x51,TWI_Write); 	// EEPROM Address, Up to 8 EEPROMS
		TWI_MasterSendData(0x23);				// Page Address
		TWI_MasterSendData(Local_u8MasterRead);
		TWI_SendStopCondition();
		/*End of EEPROM Write*/

		_delay_ms(1000);
		//if(Local_u8MasterRead == 0x10)
			//DIO_VidSetPinValue(Port_A,Pin_2,high);

	}
}
