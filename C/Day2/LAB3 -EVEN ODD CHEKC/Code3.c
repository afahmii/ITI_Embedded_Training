#include <stdio.h>

void main()
{
	int x;
	printf("plese enter a number:");
	scanf("%d",&x);
	if (x%2==0)
		printf("number is even");
	else
		printf("number is odd");
}