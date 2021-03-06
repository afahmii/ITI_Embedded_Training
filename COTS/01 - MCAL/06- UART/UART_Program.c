#include "../../LIB/Datatypes.h"
#include "../../LIB/Bit_Operations.h"

#include "UART_Config.h"
#include "UART_Private.h"
#include "UART_Interface.h"

st_uart_init UART_INIT = {UART_MODE,
		UART_Parity,
		UART_StopBit,
		UART_DataBits,
		UART_CLKPolarity,
		UART_DoubleSpeed,
		UART_MultiProcessing,
		UART_BAUDRate};

st_uart_int UART_INT = {RX_Status,
						TX_Status,
						UDR_Status};

void UART_Vidinit(st_uart_init * PtrUART){

	u8 Local_u8temp;

	/*	Select Mode of Operation - UCSRC*/
	/*==================================*/
	if(PtrUART->STM_UART_MODE == UART_Async){
		CLR_Bit(Local_u8temp,UCSRC_UMSEL); /*Clear Bit*/
	}
	else if(PtrUART->STM_UART_MODE == USART_Sync){
		Set_Bit(Local_u8temp,UCSRC_UMSEL); /*Set Bit*/
	}
	/*		Set Parity - UCSRC			*/
	/*==================================*/
	if(PtrUART->STM_UART_Parity == UART_ParityDisable){
		CLR_Bit(Local_u8temp,UCSRC_UPM0);
		CLR_Bit(Local_u8temp,UCSRC_UPM1);	/*Clear Bits*/
	}
	else if(PtrUART->STM_UART_Parity == UART_PartiyEven){
		CLR_Bit(Local_u8temp,UCSRC_UPM0);
		Set_Bit(Local_u8temp,UCSRC_UPM1);
	}
	else if(PtrUART->STM_UART_Parity == UART_PartiyOdd){
		Set_Bit(Local_u8temp,UCSRC_UPM0);
		Set_Bit(Local_u8temp,UCSRC_UPM1);
	}
	/*	Set No of Stop Bits - UCSRC		*/
	/*==================================*/
	if(PtrUART->STM_UART_StopBit == UART_OneStopBit){
		CLR_Bit(Local_u8temp,UCSRC_USBS);
	}
	else if(PtrUART->STM_UART_StopBit == UART_TwoStopBits){
		Set_Bit(Local_u8temp,UCSRC_USBS);
	}
	/*Character Size (5~9) - UCSRC/UCSRB*/
	/*==================================*/
	if(PtrUART->STM_UART_DataBits == UART_Data_5Bit){
		CLR_Bit(Local_u8temp,UCSRC_UCSZ0);
		CLR_Bit(Local_u8temp,UCSRC_UCSZ1);
		CLR_Bit(UCSRB,UCSRB_UCSZ2);
	}
	else if(PtrUART->STM_UART_DataBits == UART_Data_6Bit){
		Set_Bit(Local_u8temp,UCSRC_UCSZ0);
		CLR_Bit(Local_u8temp,UCSRC_UCSZ1);
		CLR_Bit(UCSRB,UCSRB_UCSZ2);
	}
	else if(PtrUART->STM_UART_DataBits == UART_Data_7Bit){
		CLR_Bit(Local_u8temp,UCSRC_UCSZ0);
		Set_Bit(Local_u8temp,UCSRC_UCSZ1);
		CLR_Bit(UCSRB,UCSRB_UCSZ2);
	}
	else if(PtrUART->STM_UART_DataBits == UART_Data_8Bit){
		Set_Bit(Local_u8temp,UCSRC_UCSZ0);
		Set_Bit(Local_u8temp,UCSRC_UCSZ1);
		CLR_Bit(UCSRB,UCSRB_UCSZ2);
	}
	else if(PtrUART->STM_UART_DataBits == UART_Data_9Bit){
		Set_Bit(Local_u8temp,UCSRC_UCSZ0);
		Set_Bit(Local_u8temp,UCSRC_UCSZ1);
		Set_Bit(UCSRB,UCSRB_UCSZ2);
	}

	/*		Clock Polarity- UCSRC		*/
	/*==================================*/
	if(PtrUART->STM_UART_CLKPolarity == UART_Sampling_RX_Falling){
		CLR_Bit(Local_u8temp,UCSRC_UCPOL);
	}
	else if(PtrUART->STM_UART_CLKPolarity == UART_Sampling_RX_Rising){
		Set_Bit(Local_u8temp,UCSRC_UCPOL);
	}
	/*		Access UCSRC Register		*/
	/*==================================*/
	Set_Bit(Local_u8temp,UCSRC_URSEL); 	/*Set URSEL Bit to 1 in Local_u8temp*/
	UCSRC = Local_u8temp ;				/*Store all Local_u8temp Bits values into UCSRC*/

	/*Enable/Disable Double Transmission Speed*/
	/*==================================*/
	if(PtrUART->STM_UART_DoubleSpeed == UART_DoubleSpeedDisabled){
		CLR_Bit(UCSRA,UCSRA_U2X);
	}
	else if(PtrUART->STM_UART_DoubleSpeed == UART_DoubleSpeedEnabled){
		Set_Bit(UCSRA,UCSRA_U2X);
	}

	/*Enable/Disable Double Processing Mode*/
	/*==================================*/
	if(PtrUART->STM_UART_MultiProcessing == UART_MultiProcessingDisabled){
		CLR_Bit(UCSRA,UCSRA_MPCM);
	}
	else if(PtrUART->STM_UART_MultiProcessing == UART_MultiProcessingEnabled){
		Set_Bit(UCSRA,UCSRA_MPCM);
	}
	/*			Set BAUD Rate			*/
	/*==================================*/
	UBRRL = PtrUART->STM_UART_BAUDRAte; /*9600*/

}/*End of UART_INIT Function*/



void UART_VidReceiverEnable(void){
	UCSRB |= (1<<UCSRB_RXEN);
}
void UART_VidReceiverDisable(void){
	UCSRB &= ~(1<<UCSRB_RXEN);
}
void UART_VidTransmitterEnable(void){
	UCSRB |= (1<<UCSRB_TXEN);
}
void UART_VidTransmitterDisable(void){
	UCSRB &= ~(1<<UCSRB_TXEN);
}
void UART_VidInterruptInit(st_uart_int * PtrUART){

	/*Enable/Disable RX Complete interrupt*/
	if(PtrUART->STM_RX_Status == UART_RX_Complete_INT_Disabled){
		CLR_Bit(UCSRB,UCSRB_RXCIE);
	}
	else if(PtrUART->STM_RX_Status == UART_RX_Complete_INT_Enabled){
		Set_Bit(UCSRB,UCSRB_RXCIE);
	}
	/*Enable/Disable TX Complete Interrupt*/
	if(PtrUART->STM_TX_Status == UART_TX_Complete_INT_Disabled){
		CLR_Bit(UCSRB,UCSRB_TXCIE);
	}
	else if(PtrUART->STM_TX_Status == UART_TX_Complete_INT_Enabled){
		Set_Bit(UCSRB,UCSRB_TXCIE);
	}
	/*Enable/Disable Data Register Empty Interrupt*/
	if(PtrUART->STM_UDR_Status == UART_Data_Reg_Empty_INT_Disabled){
		CLR_Bit(UCSRB,UCSRB_UDRIE);
	}
	else if(PtrUART->STM_UDR_Status == UART_Data_Reg_Empty_INT_Disabled){
		Set_Bit(UCSRB,UCSRB_UDRIE);
	}
}

void UART_VidTransmit(u8 Copy_u8Data){
	while(Get_Bit(UCSRA,UCSRA_UDRE) == 0);	/*Wait till register is empty*/
	UDR = Copy_u8Data;						/*Send Data*/
}

u8 UART_u8Receive(void){
	while(!Get_Bit(UCSRA,UCSRA_RXC)); 	/*Wait till data is Received*/
	return UDR;							/*Read Data*/
}
void UART_VidSendString(u8 * Copy_PStr){
	u8 Local_counter = 0;
	while(Copy_PStr[Local_counter] != NULL){
		UART_VidTransmit(Copy_PStr[Local_counter]);
		Local_counter++;
	}
}
void UART_VidRecString(u8 * Copy_PStr, u8 Copy_u8ArrLength){
	u8 Local_counter = 0;
	for(Local_counter = 0 ; Local_counter<=Copy_u8ArrLength ; Local_counter++){
		Copy_PStr[Local_counter] = UART_u8Receive();
		if(Copy_PStr[Local_counter] == '\r')
			break;
	}
	Copy_PStr[Local_counter] = NULL;
}



void (* UART_DataRegEmpty_Func)(void) = NULL;

void UART_DataRegEmpty_CallBack (void(*func)(void)){
	UART_DataRegEmpty_Func = func ;
}

void __vector_14 (void) __attribute__((signal)) ;
void __vector_14 (void){
	if(UART_DataRegEmpty_Func != NULL)
		UART_DataRegEmpty_Func();
}

u8* PointerToReg ;
void (* RXComplete_Func)(void) = NULL; /*ptr*/

void RXComplete_CallBack (void(*func)(void), u8 * Local_PtoReg){ /*fun agr is PtrToFunc, Pointer*/

	RXComplete_Func = func ;
	PointerToReg = Local_PtoReg;
}

void __vector_13 (void) __attribute__((signal)) ;
void __vector_13 (void){
	*PointerToReg = UDR;
	if(RXComplete_Func != NULL)
		RXComplete_Func();
}

