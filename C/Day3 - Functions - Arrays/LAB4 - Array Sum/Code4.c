#include <stdio.h>

void main()
{
	int sum = 0, avg;
	int arr[10]; 
	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
	printf(" please enter 10 numbers: \n");
	for(int i = 0; i <10 ; i++)
	{
		printf("number %d is: ", arr1[i]);
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i <10 ; i++)
	{
		sum += arr[i];
	}
	avg = sum/10; 
	printf("sum = %d and avg = %d",sum , avg);
}