/*
	abdelrahman ramzi fahmi 
	assignment 1
*/
#include <stdio.h>

/********** user defined array size*********/
#define size 10

/************functions prototype*********/
void get_values(int*ptr1); /*function to ask user for input values */
void bubble_sort(int []);  /*bubble sort function that takes an array as an argument*/
void print_array(int*ptr); /*function to print array to user*/

/****************main body***********/
void main(void)
{
	int arr1[size];
	get_values(arr1);
	bubble_sort(arr1);
	print_array(arr1);
	
}

/**************functions body*************/


void get_values(int*ptr1)
{
		for(int j = 0 ; j<size; j++)
		{
				printf("please enter value no. %d: ",j+1);
				scanf("%d",(ptr1+j));
		}
	
}
void bubble_sort(int arr[])
{

	for (int i = 0 ; i<size-1 ; i ++ )
	{
		for (int j = 0 ; j<size-1-i ; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j+1];
				arr[j+1]=arr[j];
				arr[j]= temp;
			}
		}
	}
}
void print_array(int*ptr)
{
	printf("\n sorted array is: ");
	for (int i=0; i<size; i++)
	{
		printf("%d ",*(ptr+i));
	}
}