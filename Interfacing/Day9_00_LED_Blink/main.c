/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *  Author: AbdElRahman
 */
#include <avr/io.h>
#define F_CPU 8000000
#include <util\delay.h>


void main (void)
{
	DDRA = 0b00000001;
	PORTA = 0b00000001;
	while(1)
	{
		PORTA = 0b00000000;
		_delay_ms(1000);
		PORTA = 0b00000001;
		_delay_ms(1000);
	}
}

