#include <stdio.h>

int sum(int*,int* );
void main(void)
{
	int x,y;//sum1;
	printf("enter 2 values: ");
	scanf("%d %d", &x,&y);
	//sum1 = sum(&x,&y);
	printf("sum is %d",sum(&x,&y));
}


int sum(int*ptr1,int*ptr2 )
{
	return *ptr1 + *ptr2 ;
}