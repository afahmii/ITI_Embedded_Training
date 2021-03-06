#ifndef  _UART_INTERFACE_H_ 
#define  _UART_INTERFACE_H_ 


enum UART_INIT{
	UART_Async,
	USART_Sync,
	UART_ParityDisable =0 ,
	UART_PartiyEven = 2,
	UART_PartiyOdd,
	UART_OneStopBit = 0,
	UART_TwoStopBits,
	UART_Data_5Bit = 0,
	UART_Data_6Bit,
	UART_Data_7Bit,
	UART_Data_8Bit,
	UART_Data_9Bit = 7,
	UART_Sampling_RX_Falling =0,
	UART_Sampling_RX_Rising,
	UART_DoubleSpeedDisabled = 0,
	UART_DoubleSpeedEnabled,
	UART_MultiProcessingDisabled = 0,
	UART_MultiProcessingEnabled,
	/*INTERRUPTS*/
	UART_RX_Complete_INT_Disabled =0,
	UART_RX_Complete_INT_Enabled,
	UART_TX_Complete_INT_Disabled =0,
	UART_TX_Complete_INT_Enabled,
	UART_Data_Reg_Empty_INT_Disabled =0,
	UART_Data_Reg_Empty_INT_Enabled
}en_uart;

/*UART Initialization Structure*/
typedef struct ST_UART_INIT{
	u8 STM_UART_MODE;
	u8 STM_UART_Parity;
	u8 STM_UART_StopBit;
	u8 STM_UART_DataBits;
	u8 STM_UART_CLKPolarity;
	u8 STM_UART_DoubleSpeed;
	u8 STM_UART_MultiProcessing;
	u8 STM_UART_BAUDRAte;
}st_uart_init;

/*UART Interrupts Structure*/
typedef struct ST_UART_INT{
	u8 STM_RX_Status;
	u8 STM_TX_Status;
	u8 STM_UDR_Status;
}st_uart_int;

void UART_Vidinit(st_uart_init * );
void UART_VidInterruptInit(st_uart_int * );
void UART_VidReceiverEnable(void);
void UART_VidReceiverDisable(void);
void UART_VidTransmitterEnable(void);
void UART_VidTransmitterDisable(void);
void UART_VidTransmit(u8 Copy_u8Data);
u8 UART_u8Receive(void);
void UART_VidSendString(u8 * Copy_PStr);
void UART_VidRecString(u8 * Copy_PStr,u8);
void RXComplete_CallBack (void(*func)(void),u8 * );
void UART_DataRegEmpty_CallBack (void(*func)(void));
#endif	/* _UART_INTERFACE_H_*/
