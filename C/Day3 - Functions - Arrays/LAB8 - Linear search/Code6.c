#include <stdio.h>


void main()
{
	//int sum = 0, avg;
	int x, counter = 0 ;
	int arr[10]; 
	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
/* 	printf("please enter no of numbers to sort:");
	scanf("%d",&x); */
	printf(" please enter 10 numbers: \n");
	for(int k = 0; k <10 ; k++)
	{
		printf("number %d is: ", arr1[k]);
		scanf("%d",&arr[k]);
	}
	printf("please enter the number to search for: ");
	scanf("%d",&x);
	for(int i = 0; i<10 ; i++)
	{
		if(arr[i]==x)
		{
			counter++;
		}
	}
	if(counter > 0)
		printf("number exists %d times",counter);
	else
		printf("number does not exis");
}
	