/*
 * UART_program.c
 *
 *  Created on: Aug 29, 2021
 *      Author: DELL
 */
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "UART_private.h"
#include "UART_interface.h"
#include "UART_config.h"


void UART_vid_Init()
{
	/* Receiver mode */
	UCSRB |= (Receiver<<UCSRB_RXEN_PIN);
	/* Transmitter mode */
	UCSRB |= (Transmitter<<UCSRB_TXEN_PIN);
	/* Receive Complete Interrupt*/
	UCSRB |= (RX_Complete_Interrupt<<UCSRB_RXCIE_PIN);
	/* Transmit Complete Interrupt */
	UCSRB |= (TX_Complete_Interrupt<<UCSRB_TXCIE_PIN);
	/* USART Data Register Empty Interrupt */
	UCSRB |= (USART_Data_Register_Empty_Interrupt<<UCSRB_UDRIE_PIN);
	/* If Character Size is chosen t be 9 bits  */
	if(Character_Size == size_9_bit)
	{
		SET_BIT(UCSRB,UCSRB_UCSZ2_PIN);
	}

	SET_BIT(UCSRC,UCSRC_URSEL);  /* Register Select. To access the UCSRC register and write on it*/
	/* USART Mode Select. Asynchronous or Synchronous mode of operation. */
	UCSRC |= (USART_Mode<<UCSRC_UMSEL);
	/* Parity Mode */
	UCSRC |= (Parity<<UCSRC_UPM0);
	/* Stop Bit Select */
	UCSRC |= (stop_bits<<UCSRC_USBS);
	/* Character Size Select */
	UCSRC |= (Character_Size<<UCSRC_UCSZ0);


	/* Baud Rate = 9600 */
	UBRRL =51;  /* For Oscillator Frequency = 8 MHz*/
	/* NOTE: REFER TO THE TABLES IN THE DATASHEET TO CHOOSE ANOTHER BAUD RATE THAT FITS YOUR FREQENCY */
}
void UART_vid_Send(u8 Copy_u8_data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE_PIN) == 0);  /* wait until the transmit complete flag is set */
	UDR= Copy_u8_data;
}
u8 UART_u8_Receive()
{
	while(GET_BIT(UCSRA,UCSRA_RXC_PIN) == 0);	/* wait until the receive complete flag is set */
	return UDR;

}

void UART_vid_Send_9_bits(u8 Copy_u16_data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE_PIN) == 0);  /* wait until the transmit complete flag is set */
	UCSRB |= (((Copy_u16_data>>8) & 0b00000001) << UCSRB_TXB8_PIN);
	UDR = (u8) Copy_u16_data;
}

u16 UART_u16_Receive_9_bits()
{
	u16 read=0;
	while(GET_BIT(UCSRA,UCSRA_RXC_PIN) == 0);	/* wait until the receive complete flag is set */
	read = (((UCSRB>> UCSRB_RXB8_PIN) & 0b00000001) <<8);
	read |= UDR;
	return read;
}
void Send_vid_String( u8  string_u8_array[] )
{
	/* if the string is received from the UART receiver it will end  with '\r'  ---->>>[ENTER] */
	/* if the string is defined inside the program code during the run time then it will end with '\0' */
	for(u8 i=0; (string_u8_array[i] != '\r') && (string_u8_array[i] != '\0') ; i++)
	UART_vid_Send(string_u8_array[i]);
}

void Recieve_u8_String( u8 * string_u8_array )
{
	for(u8 i=0; string_u8_array[i-1] != '\r'; i++) /* Keep receiving the string until [ENTER] is pressed */
	{
		string_u8_array[i] = UART_u8_Receive();  /* save the received string in the passed array that will be global */
	}
}

void UART_vid_Receive()
{
	while(GET_BIT(UCSRA,UCSRA_RXC_PIN) == 0);	/* wait until the receive complete flag is set */
}

/* Receive complete ISR */
void (* RX_INT_func) (void) = NULL;

void RX_INT_Call_Back(void (*func) (void))  /* In main: define a function for the task and call it back using this function  */
{
	RX_INT_func = func;
}

void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	if(RX_INT_func != NULL )
		RX_INT_func();
}
