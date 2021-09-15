#ifndef _TWI_INTERFACE_
#define _TWI_INTERFACE_

#define TWI_Write 0
#define TWI_Read 1


void TWI_VidMasterInit(u8 Copy_Address);

void TWI_VidSlaveInit(u8 Copy_Address);

void TWI_SendStartCondition(void);

void TWI_MasterSendAddress(u8 Copy_Address,u8 Copy_R_W);

void TWI_MasterSendData(u8 Copy_u8Data);

void TWI_MasterReadData(u8* Copy_u8Data);

void TWI_SendStopCondition(void);


#endif	/*_TWI_INTERFACE_*/
