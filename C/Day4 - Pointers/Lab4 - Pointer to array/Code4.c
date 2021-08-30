/*
	abdelrahman ramzi fahmi 
	lab 4 
*/
#include <stdio.h>


/************user can define the size of this array*************/
#define size 5
 
/************** declaration of the sum function *************/
int sum(int *); /* this function takes a pointer to an array as an argument, returns the summation of this array*/

/**********************main body***********************/
void main(void)
{
	int arr[size];
	for(int i=0; i<size;i++)
	{
	printf("please enter element no %d:\n",i);
	scanf("%d",&arr[i]);
	}
	printf("summation of arry is:%d",sum(arr));
	
}
/*******************function definition*****************/
int sum(int *ptr)
{	int sum = 0; 
	for(int i=0; i<size; i++)
	{
		sum += *(ptr+i);
	}
	return sum;
}

