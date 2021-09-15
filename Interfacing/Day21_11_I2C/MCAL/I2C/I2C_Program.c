#include "../../LIB/Datatypes.h"
#include "../../LIB/Bit_Operations.h"

#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "I2C_Config.h"


void TWI_VidMasterInit(u8 Copy_Address){
	/*Frequency = 400 Kbps*/
	TWBR = 2;
	CLR_Bit(TWSR,TWSR_TWPS0);
	CLR_Bit(TWSR,TWSR_TWPS1);
	/*Assign Address*/
	if(Copy_Address > 0){
	TWAR = (Copy_Address<<TWAR_TWA0);
	}

	/*Enable TWI*/
	TWCR |= (1<<TWCR_TWEN);

}

void TWI_VidSlaveInit(u8 Copy_Address){

	/*Assign Address*/
	if(Copy_Address > 0){ /*Avoid General Call*/
	TWAR = (Copy_Address<<TWAR_TWA0);
	}
	/*Enable TWI*/
	TWCR |= (1<<TWCR_TWEN);
}


void TWI_SendStartCondition(void){

	/*Send Start Condition*/
	Set_Bit(TWCR,TWCR_TWSTA);
	/*Start Function buy clearing the flag*/
	Set_Bit(TWCR,TWCR_TWINT);
	/*Wait till flag is set by hardware*/
	while (Get_Bit(TWCR,TWCR_TWINT)==0);

	/*Error Checking*/

}

void TWI_MasterSendAddress(u8 Copy_Address,u8 Copy_R_W){


	/*Set address to Communicate with*/
	TWDR = (Copy_Address<<1) | Copy_R_W ;
	/*Start Function buy clearing the flag*/
	Set_Bit(TWCR,TWCR_TWINT);
	/*Clear Start Bit - For no Valid Reason: The Timing only works here */
	CLR_Bit(TWCR,TWCR_TWSTA);
	/*Wait till flag is set by hardware*/
	while (Get_Bit(TWCR,TWCR_TWINT)==0);

	/*Check*/

}
void TWI_MasterSendData(u8 Copy_u8Data){
	/*Load Data into register*/
	TWDR = Copy_u8Data;
	/*Start Function buy clearing the flag*/
	Set_Bit(TWCR,TWCR_TWINT);
	/*Wait till flag is set by hardware*/
	while (Get_Bit(TWCR,TWCR_TWINT)==0);
	/*Check*/

}
void TWI_MasterReadData(u8* Copy_u8Data){
	/*Start Function buy clearing the flag*/
	Set_Bit(TWCR,TWCR_TWINT);
	/*Wait till flag is set by hardware*/
	while (Get_Bit(TWCR,TWCR_TWINT)==0);
	/*Read Data*/
	*Copy_u8Data = TWDR;
	/*Check*/
}
void TWI_SendStopCondition(void){
	/*Send Stop Condition*/
	Set_Bit(TWCR,TWCR_TWSTO);
	/*Start Function buy clearing the flag*/
	Set_Bit(TWCR,TWCR_TWINT);
	/*No waiting*/
}


