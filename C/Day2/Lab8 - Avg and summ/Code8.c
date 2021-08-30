#include <stdio.h>

void main()
{	
	int x,sum;
	printf("please enter random 10 numbers: ");
	for(int i =0; i<10; i++)
	{
		scanf("%d",&x);
		sum = sum+x;
	}
	int avg =sum/10;
	printf("\n average is: %d",avg);
	printf("\n sum is: %d",sum);
}