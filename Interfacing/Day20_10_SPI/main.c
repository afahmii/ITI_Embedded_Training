/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: AbdElRahman
 */

#include "LIB/Datatypes.h"
#include "LIB/Bit_Operations.h"
#include <util/delay.h>

#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"

#define Code_Select 1

#if Code_Select == 0
extern st_spi_init SPI_INIT;

void main (void){
	DIO_VidSetPinDirection(Port_B,Pin_0,output);
	DIO_VidSetPinDirection(Port_B,Pin_1,output);
	DIO_VidSetPinDirection(Port_B,Pin_5,output);
	DIO_VidSetPinDirection(Port_B,Pin_7,output);
	DIO_VidSetPinDirection(Port_B,Pin_6,input);



	SPI_VidInit(&SPI_INIT);


	while(1){
		DIO_VidSetPinValue(Port_B,Pin_0,low);
		DIO_VidSetPinValue(Port_B,Pin_1,high);
		SPI_Transceive(0x55);
		_delay_ms(1500);
		DIO_VidSetPinValue(Port_B,Pin_0,high);
		DIO_VidSetPinValue(Port_B,Pin_1,low);
		SPI_Transceive(0x66);
		_delay_ms(1500);
	}
}

#elif Code_Select == 1
/*			MASTER MCU				*/
extern st_spi_init SPI_INIT;

void main(void){
	DIO_VidSetPinDirection(Port_B,Pin_4,output);	/*SS*/
	DIO_VidSetPinValue(Port_B,Pin_4,low);			/*SS Pulled low*/
	DIO_VidSetPinDirection(Port_B,Pin_5,output);	/*MOSI*/
	DIO_VidSetPinDirection(Port_B,Pin_6,input);		/*MISO*/
	DIO_VidSetPinDirection(Port_B,Pin_7,output);	/*CLK*/

	SPI_VidInit(&SPI_INIT);

	while(1){
		SPI_Transceive(0x30);
		_delay_ms(1000);
		SPI_Transceive(0x31);
		_delay_ms(1000);
	}
}
#elif Code_Select == 2
/*			Slave MCU				*/
extern st_spi_init SPI_INIT;

void main(void){
	DIO_VidSetPinDirection(Port_B,Pin_4,input);		/*SS*/
	DIO_VidSetPinDirection(Port_B,Pin_5,input);		/*MOSI*/
	DIO_VidSetPinDirection(Port_B,Pin_6,output);	/*MISO*/
	DIO_VidSetPinDirection(Port_B,Pin_7,input);		/*CLK*/
	DIO_VidSetPinDirection(Port_B,Pin_1,output);
	SPI_INIT.STM_SPI_MODE = EN_SPI_Slave_Mode;
	SPI_VidInit(&SPI_INIT);
	static u8 read = 10;
	while(1){
		read = SPI_Transceive(0xff);
		if(read == '1'){
			DIO_VidSetPinValue(Port_B,Pin_1,high);
		}
		else if(read == '0'){
			DIO_VidSetPinValue(Port_B,Pin_1,low);
		}
	}
}


#endif
