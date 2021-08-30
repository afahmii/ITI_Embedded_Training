#include <stdio.h> 

void main()
{
	int code; 
	printf("please enter your private code: ");
	scanf("%d",&code);
	switch(code)
	{
		case(1234):
		printf("ahmed");
		break;
		case(4321):
		printf("alaa");
		break;
		case(4567):
		printf("abdelrahman");
		break;
		default:
		printf("wrong number");
	}
	
	
}