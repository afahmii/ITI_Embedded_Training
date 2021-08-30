#include <stdio.h>

void main()
{
	int x; 
	printf("please enter your desired number:");
	scanf("%d",&x);
	for(int i =0; i<=10;i++)
	{
		printf(" %d*%d = %d \n",x,i,x*i);
	}
}