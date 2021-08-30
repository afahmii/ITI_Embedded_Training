#include <stdio.h>

void main()
{
	int x = 7;
	int y = 4;
	printf("*x&y*: %d \n",x&y);
	printf("*x|y*: %d\n",x|y);
	printf("*x^y*: %d\n",x^y);
	printf("*x<<2*: %d\n",x<<2);
	printf("*x>>1*: %d",x>>1);
}