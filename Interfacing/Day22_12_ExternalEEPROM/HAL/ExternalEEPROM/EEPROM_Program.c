/*General Libraries*/
#include "../../LIB/Datatypes.h"
#include "../../LIB/Bit_Operations.h"
/*MCAL Abstraction Layer*/
#include "../../MCAL/I2C/I2C_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
/*Own Driver Libraries*/
#include "EEPROM_Config.h"
#include "EEPROM_Interface.h"


void EEPROM_VidSelect(u8 Copy_u8E2PAddress, u8 Copy_u8Operation){
	/*Initializing Each of the (A0,A1,A2) Pins corresponding to the EEPROM ADDRESS*/
	u8 Local_u8Bit0 = (Copy_u8E2PAddress & 1);
	u8 Local_u8Bit1 = ((Copy_u8E2PAddress>>1) & 1);
	u8 Local_u8Bit2 = ((Copy_u8E2PAddress>>2) & 1);
	DIO_VidSetPinDirection(EEPROM_PORT,EEPROM_A0_Pin,output);
	DIO_VidSetPinValue(EEPROM_PORT,EEPROM_A0_Pin,Local_u8Bit0);
	DIO_VidSetPinDirection(EEPROM_PORT,EEPROM_A1_Pin,output);
	DIO_VidSetPinValue(EEPROM_PORT,EEPROM_A1_Pin,Local_u8Bit1);
	DIO_VidSetPinDirection(EEPROM_PORT,EEPROM_A2_Pin,output);
	DIO_VidSetPinValue(EEPROM_PORT,EEPROM_A2_Pin,Local_u8Bit2);
	/*Sending Start Condition*/
	TWI_SendStartCondition();
	/*Sending the ADDRESS W/ Read or Write Operation*/
	TWI_MasterSendAddress(Copy_u8E2PAddress,Copy_u8Operation);
}

void EEPROM_VidByteWrite(u8 Copy_u8ByteAddress, u8 Copy_u8ByteData){
	TWI_MasterSendData(Copy_u8ByteAddress);
	TWI_MasterSendData(Copy_u8ByteData);
	TWI_SendStopCondition();
}
void EEPROM_VidPageWrite(u8 Copy_u8FirstByteAddress, u8 * Copy_u8pFirstByteData){

	TWI_MasterSendData(Copy_u8FirstByteAddress);
	for (u8 i = 0 ; i<8; i++){
	TWI_MasterSendData(Copy_u8pFirstByteData[i]);
	}
	TWI_SendStopCondition();
}



