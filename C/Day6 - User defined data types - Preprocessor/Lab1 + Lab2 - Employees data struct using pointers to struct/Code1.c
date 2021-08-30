/*
	abdelrahman 
	Lab 1 and Lab2 Combined 
*/
#include <stdio.h>
#include "..\Datatypes.h"

/******** definig a new struct of type emp ****/
typedef struct employees {
	s32 salary; 
	s32 bonus; 
	s32 deduction;
}emp;
/*********initialization of multi struct objects/variables **********/

emp emp1,emp2, emp3;

/***************** functions prototype*************/

void get_data(emp *, u8  );    /* my defined struct obj is global, i can do operations on the struct obj without passing the struct obj
											the problem is that I have to pass the struct obj, because i'm working on multiple struct objects
											- an alternative would be using struct array i can loop on*/
void print_data (emp *, u8  );

s16 calc_total( emp*  );

/**************main program - entry point ************/
void main(void)
{

	s16 total= 0;
	for (u8 j =1; j<4; j++)
	{
		if(j==1)
			get_data(&emp1,j);
		if (j==2)
			get_data(&emp2,j);
		if ( j==3) 
			get_data(&emp3,j);
	}	
	
	for (u8 i=1; i<4;i++)
	{	
		if(i== 1)
			print_data(&emp1,i);
		if(i== 2)
			print_data(&emp2,i);
		if (i==3)
			print_data(&emp3,i);
	}
	total = calc_total(&emp1)+ calc_total(&emp2)+ calc_total(&emp3);
	printf("total value needed is: %d",total);
}

/*********** functions body*************/

void get_data(emp* x, u8 j)
{	

	printf("enter employee %d salary: ",j);
	scanf("%d",&x->salary);
	printf("enter employee %d bonus: ",j);
	scanf("%d",&x->bonus);
	printf("enter employee %d deduction: ",j);
	scanf("%d",&x->deduction);
}

void print_data (emp* x, u8 i)
{
	printf("employee %d salary is: %d\n",i,x->salary);
	printf("employee %d bonus is: %d\n",i,x->bonus);
	printf("employee %d deduction is: %d\n",i,x->deduction);
}

s16 calc_total( emp* x )
{
	s16 total = x->bonus + x->salary +x->deduction;
}