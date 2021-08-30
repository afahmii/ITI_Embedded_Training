#include <stdio.h>


void main()
{
	//int sum = 0, avg;
	int x;
	int arr[10]; 
	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("please enter no of numbers to sort:");
	scanf("%d",&x);
	printf(" please enter %d numbers: \n",x);
	for(int k = 0; k <x ; k++)
	{
		printf("number %d is: ", arr1[k]);
		scanf("%d",&arr[k]);
	}
	for (int i = 0 ; i<x-1 ; i ++ )
	{
		for (int j = 0 ; j<x-1-i ; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j+1];
				arr[j+1]=arr[j];
				arr[j]= temp;
			}
		}
	}
	printf("sorted numbers are :\n ");
	for(int i = 0; i <x ; i++)
	{
		printf("number %d is: %d\n", arr1[i],arr[i]);
	}
}
	
	