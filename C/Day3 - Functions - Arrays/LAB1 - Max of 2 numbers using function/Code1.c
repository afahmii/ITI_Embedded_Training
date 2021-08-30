#include <stdio.h>
int Max (int x1, int x2);
void main()
{
	int num1 , num2;
	printf("please enter the first number: ");
	scanf("%d",&num1);
	printf("please enter the second number: ");
	scanf("%d",&num2);
	printf("\n max is: %d",Max(num1,num2));
}
int Max (int x1, int x2){
	int max;
	if  (x1 > x2)
	{
		max = x1; 
	}
	else 
		max = x2;
	
return max;
}