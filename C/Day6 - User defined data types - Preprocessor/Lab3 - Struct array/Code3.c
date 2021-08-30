/*
	abdelrahman ramzi mohamed 
	lab 3 
*/

#include <stdio.h>
#include "..\Datatypes.h"

/******definig how many students can the used enter*****/
#define nostd 3  

/********** defining a new data type "structure" ************/
typedef struct {
	s32 ID;
	s32 math;
	s32 chemistry;
	s32 physics;
	s32 english;
}st_student;

/* - initialization of a new object/variable of type st_student.
	- the variable "students" is of global charactaristics. */
st_student students[nostd]; 

/************* functions prototypes ***************/
void pass_data(void);
void show_data(s32 );

/********** main program - entry point***********/
void main (void)
{
	s32 id=0;
	pass_data();
	printf("please enter student ID:");
	scanf("%d",&id);
	show_data(id);
}

/************** functions body **************/

/*********** function for UI with the user *****/
void pass_data(void)
{
	for(u8 i =0; i<nostd;i++)
	{
	printf("please enter std no.%d ID: ",i+1);
	scanf("%d",&students[i].ID);
	printf("please enter std no.%d math grade: ",i+1);
	scanf("%d",&students[i].math);
	printf("please enter std no.%d chemistry grade: ",i+1);
	scanf("%d",&students[i].chemistry);
	printf("please enter std no.%d english grade: ",i+1);
	scanf("%d",&students[i].english);
	}
}

/************ function to fetch students data based on their ids*********/
void show_data(s32 id)
{
	u8 temp =0;
	for(u8 i= 0;i<nostd;i++)
	{
		
		if(id ==students[i].ID)
			{
				printf("access granted\n");
				printf("student no.%d math grade is:%d\n",i+1,students[i].math);
				printf("student no.%d chemistry grade is:%d\n",i+1,students[i].chemistry);
				printf("student no.%d english grade is:%d\n",i+1,students[i].english);
				temp =0;
				
			}
		else  temp =1;
	}
	if(temp == 1 )
		printf("wrong ID");
}