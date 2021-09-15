/*
 * special_functions_interface.h
 *
 *  Created on: Sep 9, 2021
 *      Author: DELL
 */

#ifndef SPECIAL_FUNCTIONS_INTERFACE_H_
#define SPECIAL_FUNCTIONS_INTERFACE_H_

u32 Map_u16Function(u32 Copy_u32GivenValue, u32 Copy_u32FromMin, u32 Copy_u32FromMax, u32 Copy_u32NewMin, u32 Copy_u32NewMax);
void Reverse_voidString(u8* Copy_u8StringArray, u16 Copy_u16StringLength);
u16 intTo_u16Str(u16 Copy_u16IntegerNumber, u8 Copy_u8StringArray[], u16 Copy_u16NumberOfDigits);

#endif /* SPECIAL_FUNCTIONS_INTERFACE_H_ */
