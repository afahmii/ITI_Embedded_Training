#ifndef  _UART_CONFIG_H_
#define  _UART_CONFIG_H_ 

/*UART Initialization Configuration*/
/*Configure this file using "UART_INIT" in UART_Interface header file*/
#define UART_MODE 				UART_Async
#define UART_Parity				UART_ParityDisable
#define UART_StopBit	     	UART_OneStopBit
#define UART_DataBits     		UART_Data_8Bit
#define UART_CLKPolarity    	UART_Sampling_RX_Falling
#define UART_DoubleSpeed    	UART_DoubleSpeedDisabled
#define UART_MultiProcessing	UART_MultiProcessingDisabled
#define UART_BAUDRate			51


/*UART Interrupts Configuration*/
/*Configure this file using "UART_INT" in UART_Interface header file*/
#define RX_Status  	UART_RX_Complete_INT_Disabled
#define TX_Status	UART_TX_Complete_INT_Disabled
#define UDR_Status 	UART_Data_Reg_Empty_INT_Disabled

#endif	/* _UART_CONFIG_H_*/
