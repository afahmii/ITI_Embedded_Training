/*
	abdelrahman ramzi fahmi 
	lab 5 
*/
#include <stdio.h>
/**********defines the size of the arrays to multiply***********/
#define size 3

/************declaration of functions**************/
void get_values(int*, int*);
void scalar_multiplication(int *,int*,int*);
void print_array(int*);


/***************main program**************/
void main(void)
{
	int arr1[size];
	int arr2[size];
	int arr3[size]; /*array to save the multiplication results*/
	get_values(arr1,arr2);
	scalar_multiplication(arr1,arr2,arr3);
	print_array(arr3);
	
}

/************* definition of functions************/

/*****************function to store values in array**************/
void get_values(int*ptr1, int*ptr2)
{
		for (int i= 0; i<2; i++)
	{
		printf("please enter the values in the %d array: \n",1+i);
		for(int j = 0 ; j<size; j++)
		{
			if(i==0)
			{
				printf("please enter value no. %d: ",j+1);
				scanf("%d",(ptr1+j));
			}
			if(i==1)
			{
				printf("please enter value no. %d: ",j+1);
				scanf("%d",(ptr2+j));
			}
		}
	}
	
}

/********************function to multiply arrays****************/
void scalar_multiplication(int *ptr1,int*ptr2,int*ptr3)
{
	for(int j =0; j<size;j++)
	{
		*(ptr3+j)=(*(ptr2+j))*(*(ptr1+j));
		//ptr3[j]= (ptr2[j])*(ptr1[j]);
	}
}
/********************* function to print array to screen**********/
void print_array(int*ptr)
{
	printf("\n multiplied array is: ");
	for (int i=0; i<size; i++)
	{
		printf("%d ",*(ptr+i));
	}
}