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
#define count1 9
#define count2 3
void S7_Display(u8* port, u8 count);


void main(void)
{
	DDRD = 0xff;
	DDRC = 0xff;
	DDRA = 0xff;
	while(1)
	{
		S7_Display(&PORTD,count1);
	}
}
void S7_Display(u8* port, u8 count)
{
			switch(count)
			{
					case 0:
						/* no 0 */
						*port = 0b0111111;
						//_delay_ms(1000);
						break;
					case 1:
						/* no 1 */
						*port = 0b0000110;
						//_delay_ms(1000);
						break;
					case 2:
						/* no 2 */
						*port = 0b1011011;
						//_delay_ms(1000);
						break;
					case 3:
						/* no 3 */
						*port = 0b1001111;
				    	//_delay_ms(1000);
						break;
					case 4:
						/* no 4 */
						*port = 0b1100110;
						//_delay_ms(1000);
						break;
					case 5:
						/* no 5 */
						*port = 0b1101101;
						//_delay_ms(1000);
						break;
					case 6:
						/* no 6 */
						*port = 0b1111101;
						//_delay_ms(1000);
						break;
					case 7:
						/* no 7 */
						*port = 0b0000111;
						//_delay_ms(1000);
						break;
					case 8:
						/* no 8 */
						*port = 0b1111111;
						//_delay_ms(1000);
						break;
					case 9:
						/* no 9 */
						*port = 0b1101111;
						//_delay_ms(1000);
						break;
			}
}

