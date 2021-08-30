#include <stdio.h>

void sum_sub(int,int ,int*,int*);
void main(void)
{
	int x,y,sum1,sub;//sum1;
	printf("enter 2 values: ");
	scanf("%d %d", &x,&y);
	sum_sub(x,y,&sum1,&sub);
	printf("sum is %d\n",sum1);
	printf("sub is %d",sub);
}


void sum_sub(int x,int y,int *ptr3,int *ptr4 )
{
	 *ptr3 =  x + y ;
	 *ptr4 = x - y;
}