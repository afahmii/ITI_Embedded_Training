#include <stdio.h>

void main()
{
	/*
		abdelrahman ramzi mohamed 
		G1 
		search for value position between 10 numbers 
	*/
	// defining variables to input the numbers 
	int n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,sr;
	// asking the user for numbers to input
	printf("please enter 10 random numbers: \n");
	printf("number 1:");
	scanf("%d",&n1);
	printf("number 2:");
	scanf("%d",&n2);
	printf("number 3:");
	scanf("%d",&n3);
	printf("number 4:");
	scanf("%d",&n4);
	printf("number 5:");
	scanf("%d",&n5);
	printf("number 6:");
	scanf("%d",&n6);
	printf("number 7:");
	scanf("%d",&n7);
	printf("number 8:");
	scanf("%d",&n8);
	printf("number 9:");
	scanf("%d",&n9);
	printf("number 10:");
	scanf("%d",&n10);
	printf("please enter a number to search for: ");
	scanf("%d",&sr);
	// comparing the values with the value the user wished to search for and printing out the result
	if(n1 == sr)
		printf("the value exist at element no. 1");
	else if(n2 == sr)
		printf("the value exist at element no. 2");
	else if(n3 == sr)
		printf("the value exist at element no. 3");
	else if(n4 == sr)
		printf("the value exist at element no. 4");
	else if(n5 == sr)
		printf("the value exist at element no. 5");
	else if(n6 == sr)
		printf("the value exist at element no. 6");
	else if(n7 == sr)
		printf("the value exist at element no. 7");
	else if(n8 == sr)
		printf("the value exist at element no. 8");
	else if(n9 == sr)
		printf("the value exist at element no. 9");
	else if(n10 == sr)
		printf("the value exist at element no. 10");
	else 
		printf("value does not exist");
}