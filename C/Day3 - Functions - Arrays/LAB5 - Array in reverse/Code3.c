#include <stdio.h>

void main()
{
	int arr[10]; 
	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
	printf(" please enter 10 numbers: \n");
	for(int i = 0; i <10 ; i++)
	{
		printf("number %d is: ", arr1[i]);
		scanf("%d",&arr[i]);
	}
	printf("\nnumbers in reverse: \n");
	for(int i = 9; i >=0 ; i--)
	{
		printf("number %d is: %d\n", arr1[i],arr[i]);
		
	}
	
}