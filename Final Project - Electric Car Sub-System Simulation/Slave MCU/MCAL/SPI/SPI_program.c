/*
 * SPI_program.c
 *
 *  Created on: Aug 30, 2021
 *      Author: DELL
 */

#include "../../lib/BIT_MATH.h"
#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "../DIO/DIO_interface.h"
void SPI_Void_Init_Master()
{

	/* SPI Interrupt */
	SPCR |= SPI_Interrupt<< SPCR_SPIE_PIN;
	/* Data Order */
	SPCR |= Data_Order<<SPCR_DORD_PIN;
	/* Clock Polarity */
	SPCR |= Clock_Polarity<<SPCR_CPOL_PIN;
	/* Master select*/
	SET_BIT(SPCR,SPCR_MSTR_PIN);
	/* Clock Phase */
	SPCR |= Clock_Phase<<SPCR_CPHA_PIN;
	/* Clock Rate Select */
	SPCR |= (((SCK_Frequency<<6)>>6)<<SPCR_SPR0_PIN);
	SPSR |= (SCK_Frequency>>2)<<SPSR_SPI2X_PIN;
	/*  SPI Enable */
	SET_BIT(SPCR,SPCR_SPE_PIN);
}

void SPI_Void_Init_Slave()
{
	DIO_VidSetPinDirection(Port_B,Pin_4,input);  		/* Slave Select setup */
	DIO_VidSetPinDirection(Port_B,Pin_5,input);			/* MOSI */
	DIO_VidSetPinDirection(Port_B,Pin_6,output);		/* MISO */
	DIO_VidSetPinDirection(Port_B,Pin_7,input);			/* SCK */

	/* set the settings same as the master but don not set the relation between SCK and the Oscillator Frequency */
	/* SPI Interrupt */
	SPCR |= SPI_Interrupt<< SPCR_SPIE_PIN;
	/* Data Order */
	SPCR |= Data_Order<<SPCR_DORD_PIN;
	/* Clock Polarity */
	SPCR |= Clock_Polarity<<SPCR_CPOL_PIN;
	/* Slave select*/
	CLEAR_BIT(SPCR,SPCR_MSTR_PIN);
	/* Clock Phase */
	SPCR |= Clock_Phase<<SPCR_CPHA_PIN;
	/*  SPI Enable */
	SET_BIT(SPCR,SPCR_SPE_PIN);
}

u8 SPI_u8_TransmitReceive( u8 Copy_u8_Data )
{
	/* Send Data */
	SPDR = Copy_u8_Data;
	/* Wait until the process is complete */
	while(GET_BIT(SPSR,SPSR_SPIF_PIN) == 0 );
	/* Return Received Data */
	return SPDR;
}
void SPI_void_Transmit(u8 Copy_u8_Data)
{
	/* Send Data */
	SPDR = Copy_u8_Data;
}

/*****************************************************ISR*****************************************************/
void (* SPI_INT_func) (void) = NULL;
u8 * Global_Pu8_SPDR = NULL;

/* In main: define a function for the task and call it back using this function also define a global variable for the SPDR */
void SPI_INT_Call_Back(void (*func) (void), u8 * Copy_Pu8_SPDR)
{
	SPI_INT_func = func;
	*Global_Pu8_SPDR = *Copy_Pu8_SPDR;
}

void __vector_12 (void) __attribute__((signal));
void __vector_12 (void)
{
	*Global_Pu8_SPDR = SPDR;
	if(SPI_INT_func != NULL )
		SPI_INT_func();
}
