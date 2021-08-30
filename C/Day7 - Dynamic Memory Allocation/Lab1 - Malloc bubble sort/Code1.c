/*
	- implementing bubble_sort function, 
	- passing an address that defines a pointer inside the function"ptr1" 
	  which is equivalnt to the pointer defined in main function "ptr".
	- because we're using malloc function, the address we get from "ptr" 
	  is the address of the first elemnt of the memory size reserved.
	  so we passed its address to "ptr1", which basically means we have
	  2 pointers pointing to the same address(first element in the memory size). 
	  - this is a different case from using double pointer.
*/

#include <stdio.h>
#include <stdlib.h>
#include "..\Datatypes.h"
void bubble_sort(u16 * , u8 );
void main(void)
{
	u16 x; 
	printf("please enter the number of elemnets to be sorted: ");
	scanf("%d",&x);
	u16 * ptr = (u16 *) malloc(x*sizeof(u16));
	for(u8 i =0; i<x;i++)
	{
	printf("please enter value of element no.%d ",i+1);
	scanf("%d",(ptr+i));
	}
	/********bubble sort*********/
/* 	for (u8 i = 0 ; i<x-1 ; i ++ 

	{
		for (u8 j = 0 ; j<x-1-i ; j++)
		{
			if(ptr[j]>ptr[j+1])
			{
				u16 temp = ptr[j+1];
				ptr[j+1]=ptr[j];
				ptr[j]= temp;
			}
		}
	} */
	
	bubble_sort(ptr,x);
	/*********printing*********/
	for(u8 i= 0 ; i<x;i++)
	{
		printf("%d ",ptr[i]);
	}
}

void bubble_sort(u16 * ptr1 , u8 x)
{
			for (u8 i = 0 ; i<x-1 ; i ++ )
	{
		for (u8 j = 0 ; j<x-1-i ; j++)
		{
			if(ptr1[j]>ptr1[j+1])
			{
				u16 temp = ptr1[j+1];
				ptr1[j+1]=ptr1[j];
				ptr1[j]= temp;
			}
		}
	}
}