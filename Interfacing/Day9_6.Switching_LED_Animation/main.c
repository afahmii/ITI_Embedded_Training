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



void main (void)
{
	DDRD = 0xff;
	DDRA = 0x00;
	u8 state = Get_Bit(PINA,0)|(Get_Bit(PINA,1)<<1)|(Get_Bit(PINA,2)<<2);
	while(1)
	{
		switch (state)
		{
		case 0:
			PORTA = 0xff;
		}
	}
}
