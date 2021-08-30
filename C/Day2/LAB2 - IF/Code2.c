#include <stdio.h>

void main()
{	
	int x,sal;
	printf("please enter your working hours");
	scanf("%d",&x);
	if (x>40)
		sal = x*50;
	if(x<=40)
		sal = 0.9*50*x;
	printf("\n your salary is: ");
	printf("%d",sal);
}