/*
 * UART_config.h
 *
 *  Created on: Aug 30, 2021
 *      Author: DELL
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/* choose between: 		enable			or 		disable       */
#define Receiver										enable
#define Transmitter										enable

/* choose between: 		Asynchronous			or 		Synchronous       */
#define USART_Mode 										Asynchronous

/* choose between: 		disable			or 		even_parity			or			odd_parity       */
#define	Parity 											disable

/* choose between: 		enable			or 		disable       */
#define RX_Complete_Interrupt							enable
#define TX_Complete_Interrupt							disable
#define USART_Data_Register_Empty_Interrupt				disable

/* choose between: 		size_5_bit		size_6_bit		size_7_bit		size_8_bit		size_9_bit	      */
#define Character_Size									size_8_bit

/* choose between:		one_stop_bit		or			two_stop_bits		*/
#define stop_bits										one_stop_bit


#endif /* UART_CONFIG_H_ */
