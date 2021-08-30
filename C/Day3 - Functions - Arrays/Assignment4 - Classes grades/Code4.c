/*
	Abdelrahman Ramzi 
	assignemt 4
*/
#include <stdio.h>

/******************* functions declerations *****************/

int std_pass_no (int arr[]);
int highest_grade (int arr[]);
int lowest_grade (int arr[]);
float avg_grade (int arr[]);


void main(void)
{
	int std1 [] = { 63,79 ,77 ,88 ,99 ,40 ,35 , 95, 91,55 ,42 };
	int std2 [] = { 64,80 ,78 ,89 ,100,41 ,36 , 96, 92,56 ,43 };
	int std3 [] = { 65,24 ,79 ,90 ,94 ,42 ,37 , 96, 93,57 ,44 };
	int pass,high, low ;
	float avg;
	/**************printing the no of passed and failed students***********/
	pass = std_pass_no(std1)+std_pass_no(std2)+std_pass_no(std3);
	printf(" no of passed students is: %d \n",pass);
	printf(" no of failed students is: %d \n",30-pass);
	/********************printing the highest grade *******************/
	high = highest_grade(std1);
	high< highest_grade(std2)? high=highest_grade(std2):
	high< highest_grade(std3)? high=highest_grade(std3):0;
	printf("highest grade is: %d \n",high);
	/********************printing the lowest grade *******************/
	low = lowest_grade(std1);
	low> lowest_grade(std2)? low=lowest_grade(std2):
	low> lowest_grade(std3)? low=lowest_grade(std3):0;
	printf(" lowest grade is: %d \n",low);
	/********************** printing avg grade ***********************/
	avg = (avg_grade(std1)+avg_grade(std2)+avg_grade(std3))/3;
	printf("avg is: %f",avg);
	
	
}
/************************ functions definitions ********************/

int std_pass_no (int arr[])
{
	int counter = 0; 
	for (int i = 0 ; i<10; i++)
	{
		if(arr[i]>=50)
		counter++;
	}
	return counter; 
}
//int std_failed_no (int arr[]);
int highest_grade (int arr[])
{
	int max=0 ; 
	for (int i = 0 ; i<10 ; i++)
	{
		if (arr[i]>max)
			max = arr[i];
		
	}
	return max; 
}

int lowest_grade (int arr[])
{
	int min = arr[0] ; 
	for (int i = 0 ; i<10 ; i++)
	{
		if (arr[i]<min)
			min = arr[i];
	}
	return min; 
}

float avg_grade (int arr[])
{
	float avg =0;
		for (int i = 0 ; i<10 ; i++)
	{
		avg+= arr[i];
	}
	return (avg/10);
}