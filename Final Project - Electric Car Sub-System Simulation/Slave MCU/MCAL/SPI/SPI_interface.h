/*
 * SPI_interface.h
 *
 *  Created on: Aug 30, 2021
 *      Author: DELL
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_



void SPI_Void_Init_Master();  	/* initialize master */
void SPI_Void_Init_Slave();		/* initialize slave */
u8 SPI_u8_TransmitReceive( u8 Copy_u8_Data );		/* send and receive data and save it */
void SPI_INT_Call_Back(void (*func) (void), u8 * Copy_Pu8_SPDR); /* Call back function for the SPI Transmit Complete interrupt*/
void SPI_void_Transmit(u8 Copy_u8_Data); /* send data only : used with the SPI INTERRUPT */

#endif /* SPI_INTERFACE_H_ */
