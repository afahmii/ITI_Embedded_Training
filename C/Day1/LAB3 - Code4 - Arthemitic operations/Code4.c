#include <stdio.h>

void main()
{   int a,b;
	//ask user for inputs
	printf("enter first number: ");
	scanf("%d",&a);
	printf("\n");
	printf("enter second number: ");
	scanf("%d",&b);
	printf("\n");
	//summsion of inputs
	int y= a+b; 
	printf("sum of 2 numbers is:%d ",y);
	printf("\n");
	// diff between inputs
	y= a-b;
	printf("diff between 2 numbers is: %d",y);
	printf("\n");
	// multi of inputs
	y=a*b;
	printf(" X of 2 numbers is: %d",y);
	printf("\n");
	//div of inputs
	y = a/b;
	printf(" div of 2 numbers is: %d",y);
	printf("\n");
	//reminder of inputs
	float	z = b%a;
	printf(" reminder of 2 numbers is: %f",z);
	printf("\n");
	//post and pre fixes of variables 
	printf("\"a++\" is %d",a++);
	printf("\n");
	a=10;
	printf("\"++a\" is %d",++a);
	printf("\n");
	printf("\"b--\" is %d",b--);
	printf("\n");
	b=20;
	printf("\"--b\" is %d",--b);
	
}