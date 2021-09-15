/*
 * main.c
 *
 *  Created on: Sep 2, 2021
 *      Author: AbdElRahman
 */
#include "LIB/Datatypes.h"
#include "LIB/Bit_Operations.h"
#include "util/delay.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/I2C/I2C_Interface.h"

#include "HAL/ExternalEEPROM/EEPROM_Interface.h"


void main(void){
static u8 Local_u8DataArr[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
	TWI_VidMasterInit(0);
	//u8 Local_u8Counter = 1;
	while(1){
		EEPROM_VidSelect(EN_EPPROM1,EN_EEPROM_Write);
		EEPROM_VidPageWrite(0x00,Local_u8DataArr);
		_delay_ms(1000);
	}
}
