#include <stdio.h>

void main(void)
{
	int x=10; 
	int *ptr = &x;
	printf("X value is: %d\n",x);
	*ptr +=10;
	printf("X+10 is %d",x);
}