/*
 * SPI_private.h
 *
 *  Created on: Aug 30, 2021
 *      Author: DELL
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include "../../lib/STD_TYPES.h"

#define SPDR		*((volatile u8 *) 0x2F)				/* SPI Data Register – SPDR */
#define SPSR		*((volatile u8 *) 0x2E)				/* SPI Status Register – SPSR */
#define SPCR		*((volatile u8 *) 0x2D)				/* SPI Control Register – SPCR */

/* SPI Status Register – SPSR PINS */
#define SPSR_SPIF_PIN				7
#define SPSR_WCOL_PIN				6
#define SPSR_SPI2X_PIN				0

/* SPI Control Register – SPCR PINS */
#define SPCR_SPIE_PIN				7
#define SPCR_SPE_PIN				6
#define SPCR_DORD_PIN				5
#define SPCR_MSTR_PIN				4
#define SPCR_CPOL_PIN				3
#define SPCR_CPHA_PIN				2
#define SPCR_SPR1_PIN				1
#define SPCR_SPR0_PIN				0


enum SPI_config{
disable_SPI_INT,
enable_SPI_INT,
MSB_first=0,
LSB_first,
Rising_leading_edge=0,
Falling_leading_edge,
Sample_on_leading_edge=0,
Setup_on_leading_edge,
divide_Focs_by_4=0,
divide_Focs_by_16,
divide_Focs_by_64,
divide_Focs_by_128,
divide_Focs_by_2,
divide_Focs_by_8,
divide_Focs_by_32

}SPI_configurations;



#endif /* SPI_PRIVATE_H_ */
