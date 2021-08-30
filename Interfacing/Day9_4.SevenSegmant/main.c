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
		for(u8 i=0;i<10;i++)
			{
				/* no 0 */
				PORTD = 0b0111111;
				_delay_ms(1000);
				/* no 1 */
				PORTD = 0b0000110;
				_delay_ms(1000);
				/* no 2 */
				PORTD = 0b1011011;
				_delay_ms(1000);
				/* no 3 */
				PORTD = 0b1001111;
				_delay_ms(1000);
				/* no 4 */
				PORTD = 0b1100110;
				_delay_ms(1000);
				/* no 5 */
				PORTD = 0b1101101;
				_delay_ms(1000);
				/* no 6 */
				PORTD = 0b1111101;
				_delay_ms(1000);
				/* no 7 */
				PORTD = 0b0000111;
				_delay_ms(1000);
				/* no 8 */
				PORTD = 0b1111111;
				_delay_ms(1000);
				/* no 9 */
				PORTD = 0b1101111;
				_delay_ms(1000);
			}
	}
}

