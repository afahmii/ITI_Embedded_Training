/*
 * special_functions.c
 *
 *  Created on: Sep 9, 2021
 *      Author: DELL
 */

#include "lib/STD_TYPES.h"
#include "lib/BIT_MATH.h"

/* mapping function that gives the corresponding value of a number in different domain */
u32 Map_u16Function(u32 Copy_u32GivenValue, u32 Copy_u32FromMin, u32 Copy_u32FromMax, u32 Copy_u32NewMin, u32 Copy_u32NewMax)
{
	Copy_u32GivenValue = (100UL*(Copy_u32GivenValue-Copy_u32FromMin));
	Copy_u32GivenValue /= (Copy_u32FromMax-Copy_u32FromMin);
	Copy_u32GivenValue =  ((Copy_u32GivenValue)*(Copy_u32NewMax - Copy_u32NewMin));
	Copy_u32GivenValue /=	100UL;
	Copy_u32GivenValue += Copy_u32NewMin;
	return Copy_u32GivenValue;
}

/* function that reverse elements of string */
void Reverse_voidString(u8* Copy_u8StringArray, u16 Copy_u16StringLength)
{
	u8 i = 0, j = (Copy_u16StringLength - 1) , temp;
	while (i < j) {
		temp = Copy_u8StringArray[i];
		Copy_u8StringArray[i] = Copy_u8StringArray[j];
		Copy_u8StringArray[j] = temp;
		i++;
		j--;
	}
}

/* function that converts an integer number to string */
u16 intTo_u16Str(u16 Copy_u16IntegerNumber, u8 Copy_u8StringArray[], u16 Copy_u16NumberOfDigits)
{
	u16 i = 0;
	while (Copy_u16IntegerNumber)
	{
		Copy_u8StringArray[i++] = (Copy_u16IntegerNumber % 10) + '0';
		Copy_u16IntegerNumber = Copy_u16IntegerNumber / 10;
	}

	/* If number of digits required is more, then
	 add 0s at the beginning */
	while (i < Copy_u16NumberOfDigits)
		{Copy_u8StringArray[i++] = '0';}

	Reverse_voidString(Copy_u8StringArray, i);
	Copy_u8StringArray[i] = '\0';
	return i;
}
