/*
 * Main.c

 *
 *  Created on: Aug 16, 2021
 *      Author: AbdElRahman
 */
#include "Datatypes.h"
#include "Bit_Operations.h"
#include <avr/io.h>
#define F_CPU 8000000
#include <util\delay.h>



void main(void)
{
	DDRD = 0xff;
	CLR_Bit(DDRC,0);
	while(1)
	{
		PORTD = 0x00;
		if(Get_Bit(PINC,0)==1)
		{
			PORTD = 0xff;
			_delay_ms(1000);
		}
		else
			PORTD = 0x00;
	}
}

