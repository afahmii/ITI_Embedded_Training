/*
	Abdelrahman Ramzi 
	assignemt 3
*/
#include <stdio.h>
/**************** functions declerations *************/
void get_values(int arr[]); 
int get_max(int arr[]);
int get_min(int arr[]);
/***************** main program ******************/
void main(void)
{
	int arr[10];           			  /* defining an array of 4 elements for the user to store values*/
	get_values(arr); 				  /* asking user to enter 4 values */
	printf("max value is: %d",get_max(arr)); /*printing the maximum value using get_max function */
	printf("\n");
	printf("min value is: %d",get_min(arr));  /*printing the minimum value using get_min function */
	
	
}

/**************** functions definitions ****************/
/* function to ask user for 10 numbers */
void get_values(int arr[])
{
	for(int i = 0; i<10;i++)
	{
	printf("please enter the value no. %d: ",i+1);
	scanf("%d",&arr[i]);
	}
}
/* function to return the maximum number of 10 numbers */
int get_max(int arr[])
{
	int max =0 ;
	for(int i = 0; i<10;i++)
	{

		if(arr[i] >max)
		{
			max = arr[i];

		}
	}

	return max;
}
/* function to return the minimum number of 10 numbers */
int get_min(int arr[])
{
	int min =arr[0];
	for(int i = 0; i<10;i++)
	{

		if(arr[i] < min)
		{
			min = arr[i]; 
		}
	}
	return min;
}