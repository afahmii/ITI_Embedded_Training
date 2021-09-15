#include "../../LIB/Datatypes.h"
#include "../../LIB/Bit_Operations.h"

#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"





st_spi_init SPI_INIT = {SPI_MODE,
						SPI_Status,
						SPI_INT_Status,
						SPI_Data_Order,
						SPI_CLK_Polarity,
						SPI_Clock_Phase,
						SPI_Frequency_Select};

void SPI_VidInit(st_spi_init * SPI_INIT){
	/*Mode Select*/
	SPCR &= ~(1<<SPCR_MSTR);
	SPCR |=  (SPI_INIT->STM_SPI_MODE<<SPCR_MSTR);
	/*Interrupt Status*/
	SPCR &= ~(1<<SPCR_SPIE);
	SPCR |= (SPI_INIT->STM_SPI_INT_Status<<SPCR_SPIE);
	/*Shift Register Data Order*/
	SPCR &= ~(1<<SPCR_DORD);
	SPCR |= (SPI_INIT->STM_SPI_Data_Order<<SPCR_DORD);
	/*Clock Polarity*/
	SPCR &= ~(1<<SPCR_CPOL);
	SPCR |= (SPI_INIT->STM_SPI_CLK_Polarity<<SPCR_CPOL);
	/*Clock Phase*/
	SPCR &= ~(1<<SPCR_CPHA);
	SPCR |= (SPI_INIT->STM_SPI_Clock_Phase<<SPCR_CPHA);
	/*Frequency*/
	if(SPI_INIT->STM_SPI_MODE == EN_SPI_Master_Mode){
	SPCR &= (0b11111100); /*Clear the first two bits*/
	SPCR |= (SPI_INIT->STM_SPI_Frequency_Select&0b00000011); /*Mask the last 6 bits then assign to the register*/
	SPSR &= (0b11111110); /*Clear the first bit*/
	SPSR |= (SPI_INIT->STM_SPI_Frequency_Select>>2); /*Shift the bits right by 2, then assign to the register*/
	}
	/*SPI Enable*/
	SPCR &= ~(1<<SPCR_SPE);
	SPCR |= (SPI_INIT->STM_SPI_Status<<SPCR_SPE);
}

u8 SPI_Transceive(u8 Copy_u8Data){

	SPDR = Copy_u8Data;
	while(!Get_Bit(SPSR,SPSR_SPIF));
	return SPDR;

}
void SPI_VidIntEnable(void){
	Set_Bit(SPCR,SPCR_SPIE);
}
void SPI_VidIntDisable(void){
	CLR_Bit(SPCR,SPCR_SPIE);
}
