#include <stdio.h>

void main()
{
	int x; 
	float y; 
	char z; 
	printf("please enter an Integer: ");
	scanf("%d",&x);
	//fflush(stdin);
	printf("please enter a float number: ");
	scanf("%f",&y);
	//fflush(stdin);
	printf("please enter a character: ");
	scanf(" %c",&z);
	printf("your intger is %d \n your float is %f \n your character is %c \n",x,y,z);
}