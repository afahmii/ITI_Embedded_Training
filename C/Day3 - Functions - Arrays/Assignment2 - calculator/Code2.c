/*
	Abdelrahman Ramzi 
	assignemt 2
*/
#include <stdio.h>
/**************** functions declerations *************/
int add(int,int);
int not(int);
int xor(int,int);
int reminder(int,int);
int inc(int);

void main (void)
{
	int x , res;
	/****************** user interface ******************/
	printf("enter the wanted operand: \n");
	printf("1. add \n");
	printf("2. not \n");
	printf("3. xor \n");
	printf("4. reminder \n");
	printf("5. inc \n");
	scanf("%d",&x);
	/**************** swtiching between operations *****************/
	switch(x)
	{
		int x,y;
		/*
		in this example you can: 
		
		1. scan operands 1 time only before the switch function
		2. print the result 1 time only after the switch function
		*/
		case(1):
		printf("please enter numbers to be added: ");
		scanf("%d %d",&x,&y);
		res = add(x,y);
		printf("sum:%d",res);
		break;
		case(2):
		printf("please enter number to be reversed: ");
		scanf("%d",&x);
		res = not(x);
		printf("%d reversed is :%d",x,res);
		break;
		case(3):
		printf("please enter numbers to perform XOR operation: ");
		scanf("%d %d",&x,&y);
		res = xor(x,y);
		printf("Xor:%d",res);
		break;
		case(4):
		printf("please enter numbers to calculate reminder: ");
		scanf("%d %d",&x,&y);
		res = reminder(x,y);
		printf("reminder:%d",res);
		break;
		case(5):
		printf("please enter a number to increment: ");
		scanf("%d",&x);
		res = inc(x);
		printf("inc:%d",res);
		break;
		default:
		printf("operand does not exist. ");
	}
}
/*************** functions definitions ****************/ 
int add(int x,int y)
{
	int res = x+y;
	return res;
}
int not(int x)
{
	return ~x;
}
int xor(int x,int y)
{
	int res = x^y;
	return res;
}
int reminder(int x,int y)
{
	int reminder = x%y;
	return reminder; 
}
int inc(int x)
{
	++x;
	return x;
}
