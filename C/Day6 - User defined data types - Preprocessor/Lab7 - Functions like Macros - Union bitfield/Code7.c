/*
	abdelrahman ramzi mohamed 
	lab 7
*/
#include <stdio.h>
#include "Bit_Operations.h"
#include "..\Datatypes.h"


void main(void)
{
	typedef union
	{
		struct{
			u8 bit0 : 1 ;
			u8 bit1 : 1 ;
			u8 bit2 : 1 ;
			u8 bit3 : 1 ;
			u8 bit4 : 1 ;
			u8 bit5 : 1 ;
			u8 bit6 : 1 ;
			u8 bit7 : 1 ;
		}s1;
		u8 byte ; 
	}unt_u1;	
	
	unt_u1 u1; 

	Set_Bit(u1.s1.bit0,0);
	printf("bit value is: %d\n",u1.s1.bit0);
	CLR_Bit(u1.s1.bit0,0);
	printf("bit value is: %d\n",u1.s1.bit0);
}