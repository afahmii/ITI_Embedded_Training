#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_



typedef enum EN_SPI_INIT{
	/*Mode Select*/
	EN_SPI_Slave_Mode,
	EN_SPI_Master_Mode,
	/*Enable/Disable SPI*/
	EN_SPI_Disable = 0,
	EN_SPI_Enable,
	/*SPI Interrupt*/
	EN_SPI_INT_Disable = 0,
	EN_SPI_INT_Enable,
	/*Shift Register Data Order*/
	EN_SPI_DATA_MSB = 0,
	EN_SPI_DATA_LSB,
	/*Clock Polarity*/
	EN_SPI_CPOL_Leading_Rising = 0,
	EN_SPI_CPOL_Leading_Falling,
	/*Clock Phase*/
	EN_SPI_CPHA_Leading_Sample = 0,
	EN_SPI_CPHA_Leading_Setup,
	/*Frequency Selector*/
	EN_SPI_CLK_4 = 0,
	EN_SPI_CLK_16,
	EN_SPI_CLK_64,
	EN_SPI_CLK_128,
	EN_SPI_CLK_2,   /*Enable Double Speed Bit only*/
	EN_SPI_CLK_8,
	EN_SPI_CLK_32,
}en_spi_init;

typedef struct ST_SPI_INIT{
	u8 STM_SPI_MODE;
	u8 STM_SPI_Status;
	u8 STM_SPI_INT_Status;
	u8 STM_SPI_Data_Order;
	u8 STM_SPI_CLK_Polarity;
	u8 STM_SPI_Clock_Phase;
	u8 STM_SPI_Frequency_Select;
}st_spi_init;

void SPI_VidInit(st_spi_init *);
u8 SPI_Transceive(u8 Copy_u8Data);
void SPI_VidIntEnable(void);
void SPI_VidIntDisable(void);




#endif /*_SPI_INTERFACE_H_*/
