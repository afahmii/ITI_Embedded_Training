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

u8 Arr_DecToSeg[10] = {0b00111111,   /* 0 */
                       0b00000110,   /* 1 */
                       0b01011011,   /* 2 */
                       0b01001111,   /* 3 */
                       0b01100110,   /* 4 */
                       0b01101101,   /* 5 */
                       0b01111101,   /* 6 */
                       0b00000111,   /* 7 */
                       0b01111111,   /* 8 */
                       0b01101111    /* 9 */
					  };
u8 ones, tens;
u8 timer=11;


void main(void)
{
	DDRD = 0xff; /*for the first 7 segmant*/
	DDRC = 0xff; /*for the second 7 segmant*/
	DDRA = 0xff; /* for the LEDS*/
	u8 color = 0; /*0 for green,
					1 for yellow,
					2 for red	*/

	Set_Bit(PORTA,0); /* Initial Condition: Green Light is On*/
	while(1)
	{
		switch(color)
		{
		case 0:
			timer--;
			if(timer == 0 ) /*When Timer Reaches 0, Do: */
			{
				CLR_Bit(PORTA,0); /*Green Off*/
				Set_Bit(PORTA,1); /*Yellow On*/
				color = 1; /*Switching to the Yellow Case*/
				timer = 3; /*Yellow will be on for 3 seconds*/
			}
			break;
		case 1:
			timer--;
			if(timer == 0 ) /*When Timer Reaches 0, Do: */
			{
				CLR_Bit(PORTA,1); /*Yellow Off*/
				Set_Bit(PORTA,2); /*RED On*/
				color = 2; /*Switching to the Red Case*/
				timer = 10; /*Red will be on for 10 seconds*/
			}
			break;
		case 2:
			timer--; /*Decrement this variable each 1 second*/
			if(timer == 0 ) /*When Timer Reaches 0, Do: */
			{
				CLR_Bit(PORTA,2); /*Red Off*/
				Set_Bit(PORTA,0); /*Green On*/
				color = 0; /*Switching to the Green Case*/
				timer = 10; /*Green will be on for 10 seconds*/
			}
			break;
		}

		/*7Segmant Display*/
		tens = timer / 10 ;
		ones = timer % 10 ;
		PORTC = Arr_DecToSeg[tens] ;
		PORTD = Arr_DecToSeg[ones] ;

		/*Code 1s Delay*/
		_delay_ms(1000);
	}
}
