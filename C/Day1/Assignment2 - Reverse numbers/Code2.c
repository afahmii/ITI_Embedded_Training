#include <stdio.h>

void main()
{
	/*
	abdelrahman ramzi mohamed fahmi 
	G1 
	input numbers and show the output in a reverse order
	*/
	//asking user for numbers to input 
	int x,y,z,temp; 
	printf("input 3 different numbers.\n");
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);
	printf("original order %d %d %d\n", x,y,z);
	temp = z ; 
	z=x;
	x = temp;
	printf("new order is: %d %d %d",x,y,z);
	
}