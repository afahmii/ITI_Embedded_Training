/*
 * UART_interface.h
 *
 *  Created on: Aug 29, 2021
 *      Author: DELL
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_



void UART_vid_Init();		/* initialize UART as configured in UART_config.h file */
void UART_vid_Send(u8 Copy_u8_data);  /* send data */
u8 UART_u8_Receive();				/* receive data */
void UART_vid_Send_9_bits(u8 Copy_u16_data);  /* function to send data if 9 bits character size is selected */
u16 UART_u16_Receive_9_bits();				 /* function to receive data if 9 bits character size is selected */
void Send_vid_String( u8  string_u8_array[]);		/* send string, works in NON 9 bits mode  */
void Recieve_u8_String( u8 * string_u8_array );		/* receive string, works in NON 9 bits mode  */
void RX_INT_Call_Back(void (*func) (void));
void UART_vid_Receive(); /* function that waits until data is received and gives no return: USED WITH RECEIVE COMPLETE INTERRUPT */

#endif /* UART_INTERFACE_H_ */
