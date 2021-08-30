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
	while(1)
	{
		PORTD = 0x00;
		for(u8 i = 0 ; i<8; i++)
			{
				//PORTD = 0x00;
				Set_Bit(PORTD,i);
				_delay_ms(100);
			}
		PORTD = 0x00;
		for(s8 i = 7 ; i>=0; i--)
				{

					Set_Bit(PORTD,i);
					_delay_ms(100);
				}

	}
}

