#include <stdio.h>

void main()
{
	/*
		abdelrahman ramzi mohamed 
		G1 
		sum of 2 numbers
	*/
	int x1, x2,sum=0; //variables to store the user input numbers and calc sum.
	while(1)
	{
		sum = 0 ; 
		// asking user to enter 2 numbers 
		printf("enter the first number: ");
		scanf("%d",&x1);
		printf("enter the second number: ");
		scanf("%d",&x2);
		sum = x1 +x2;  // function to calc sum.
		printf("sum is: %d \n", sum); // printing sum 
	}
}