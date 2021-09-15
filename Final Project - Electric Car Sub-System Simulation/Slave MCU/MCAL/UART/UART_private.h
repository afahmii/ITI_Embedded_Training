/*
 * UART_private.h
 *
 *  Created on: Aug 29, 2021
 *      Author: DELL
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UDR       *((volatile u8 *) 0x2C)          /* USART INPUT OUTPUT DATA REGISTER */
#define UCSRA     *((volatile u8 *) 0x2B)		   /* CONTROL AND STATUS REGISTER A */
#define UCSRB     *((volatile u8 *) 0x2A)          /* CONTROL AND STATUS REGISTER B */
#define UBRRL     *((volatile u8 *) 0x29)
#define UBRRH     *((volatile u8 *) 0x40)
#define UCSRC     *((volatile u8 *) 0x40)          /* CONTROL AND STATUS REGISTER C */

/* UCSRA: CONTROL AND STATUS REGISTER A */
#define UCSRA_RXC_PIN 		7					 /* USART Receive Complete flag*/
#define UCSRA_TXC_PIN 		6                    /* USART Transmit Complete flag */
#define UCSRA_UDRE_PIN 		5                    /* USART Data Register Empty flag  */
#define UCSRA_FE_PIN 		4                    /* Frame Error flag */
#define UCSRA_DOR_PIN 		3                    /* Data OverRun flag */
#define UCSRA_PE_PIN 		2                    /* Parity Error flag */
#define UCSRA_U2X_PIN 		1                    /* Double the USART Transmission Speed */
#define UCSRA_MPCM_PIN 		0                    /* Multi-processor Communication Mode */

/* UCSRB: CONTROL AND STATUS REGISTER B */
#define UCSRB_RXCIE_PIN      7                     /* RX Complete Interrupt Enable */
#define UCSRB_TXCIE_PIN      6                     /* TX Complete Interrupt Enable */
#define UCSRB_UDRIE_PIN      5                     /* USART Data Register Empty Interrupt Enable */
#define UCSRB_RXEN_PIN       4                     /* Receiver Enable: The MC is now a receiver */
#define UCSRB_TXEN_PIN       3                     /* Transmitter Enable: The MC is now a Transmitter*/
#define UCSRB_UCSZ2_PIN      2                     /* Character Size select bit along with  the UCSZ1:0 bit in UCSRC */
#define UCSRB_RXB8_PIN       1                     /* Receive Data Bit 8 when operating with serial frames with nine
													data bits. Must be read before reading the low bits from UDR*/
#define UCSRB_TXB8_PIN       0                    /* Transmit Data Bit 8 when operating with serial frames
												    with nine data bits. Must be written before writing the low bits to UDR.*/

/* UCSRC: CONTROL AND STATUS REGISTER C */
#define UCSRC_URSEL			 7					 /* Register Select. This bit selects between accessing the UCSRC or the UBRRH Register. It is read as one when
													reading UCSRC. The URSEL must be one when writing the UCSRC. */
#define UCSRC_UMSEL			 6					 /* USART Mode Select. This bit selects between Asynchronous and Synchronous mode of operation. 0 Asynchronous Operation. 1 Synchronous Operation*/
#define UCSRC_UPM1			 5					 /* Parity Mode */
#define UCSRC_UPM0			 4					 /* Parity Mode */
#define UCSRC_USBS			 3					 /* Stop Bit Select */
#define UCSRC_UCSZ1			 2					 /* Character Size select */
#define UCSRC_UCSZ0			 1					 /* Character Size select */
#define UCSRC_UCPOL			 0					 /*  Clock Polarity */


enum UART{
	disable,
	enable,
	Asynchronous=0,
	Synchronous,
	size_5_bit=0,
	size_6_bit,
	size_7_bit,
	size_8_bit,
	size_9_bit=3,
	even_parity=2,
	odd_parity,
	one_stop_bit = 0,
	two_stop_bits
};

#endif /* UART_PRIVATE_H_ */
