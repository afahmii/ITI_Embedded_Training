/*
	Abdelrahman Ramzi 
	assignemt 1 
*/
#include <stdio.h>
/**************** functions declerations *************/
void get_values(int arr[]); 
int get_max(int arr[]);
int get_min(int arr[]);

void main(void)
{
	int arr[4],max;            /* defining an array of 4 elements for the user to store values*/
//	int arr1[]={ 9,18 ,2 ,20};  
	get_values(arr);   /* asking user to enter 4 values */
	printf("max value is: %d",get_max(arr)); /*printing the maximum value using get_max function */
	printf("\n");
	printf("min value is: %d",get_min(arr));  /*printing the minimum value using get_min function */
/*     printf("\n %d",&arr[0]);
	printf("\n"); */
/* 	printf("%d",arr[0]);
	printf("\n");
	printf("%d",arr[1]);
	printf("\n");
	printf("%d",arr[2]);
	printf("\n");
	printf("%d",arr[3]);
	printf("\n");
 */
}

/************** finctions definitions ****************/
void get_values(int arr[])
{
	for(int i = 0; i<4;i++)
	{
	printf("please enter the value no. %d: ",i+1);
	scanf("%d",&arr[i]);
	}
}
int get_max(int arr[])
{
	int max =0 ;
	for(int i = 0; i<4;i++)
	{

		if(arr[i] >max)
		{
			max = arr[i];

		}
	}

	return max;
}
int get_min(int arr[])
{
	int min =arr[0];
	for(int i = 0; i<4;i++)
	{

		if(arr[i] < min)
		{
			min = arr[i]; 
		}
	}
	return min;
}

