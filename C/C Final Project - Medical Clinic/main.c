/*
	Name: Abdelrahman Ramzi Mohamed
	G1
	Code Description: Medical Clinic system for elrolling and viewing patient appoinements 
*/


/* Including standard Libraries*/
#include <stdio.h>
/*Including Global Libraries*/
#include "Datatypes.h"
/*Including Linked List Library*/
#include "Linked_list.h"
/*Macros for Configurability*/
#define true 1
#define false 0
#define empty_slot 88

/*															Globla Variables																*/
st_node * head;
/* Initializing the time slots a patient can schedule*/
u8 slots_arr1[5] = "2:30";
u8 slots_arr2[5] = "3:00";
u8 slots_arr3[5] = "3:30";
u8 slots_arr4[5] = "4:00";
u8 slots_arr5[5] = "4:30";
/*Array of Pointers, to access the slots easliy*/
u8 * ptr_slots_arr[] = {slots_arr1,slots_arr2,slots_arr3,slots_arr4,slots_arr5};
/*Flag array to indicatie the reserved slots*/
u8 flag_arr [5]={empty_slot,empty_slot,empty_slot,empty_slot,empty_slot};


/*==========================================================*/
/*												Main Program, Entry Pointers														*/
/*==========================================================*/

void main (void){
	u8 Mode_Select = 1 ; /*default for Admin mode*/
	static u16 Default_Password = 1234; 
	u16 Admin_Password =0;
	u8 Admin_Flag = false; 
	u8 Program_Exit_Flag = 0 ;
/* 	strcpy(slot1[0].slot_time , "2:30");
	strcpy(slot1[1].slot_time , "3:00");
	strcpy(slot1[2].slot_time , "3:30");
	strcpy(slot1[3].slot_time , "4:00");
	strcpy(slot1[4].slot_time , "4:30"); */
while(1){
	
	/*UI*/
	printf("Select Operation Mode:\n");
	printf("1.Admin Mode:\n");
	printf("2.User Mode:\n");
	printf("3.Exit Program:\n");
	/*Mode Select Input*/
	scanf("%d",&Mode_Select);
/*========================Admin Mode==========================*/
	if(Mode_Select == 1){
		printf("Admin Mode Activated.");
		for (u8 i = 0 ; i<3; i++){
				printf("\nEnter your Password: ");
				scanf("%d",&Admin_Password);
				if(Admin_Password == Default_Password){
					printf("Correcet Password↑↑↑.\n");
					Admin_Flag = true ;
					break ; 
				}
				else if(Admin_Password != Default_Password){
					printf("Worng Password.\nYou Have %d More Tries",2-i);
					if((2-i)==false)
						Program_Exit_Flag==1;
				}	
		}
		if(Program_Exit_Flag ==1 )
			break;
		while(1){
			u8 User_Exit_Flag = false ; 
			if(Admin_Flag == true )
			{
				u8 Admin_Mode_Select = 0 ; 
				u16 ID =0;
				printf("\nChoose Function:");
				printf("\n1.Add A New Patient Record");
				printf("\n2.View An Existing Patient Record");
				printf("\n3.Edit A Patient Record");
				printf("\n4.Schedule A Meeting With The Doctor");
				printf("\n5.Cancel Reservation");
				printf("\n6.Back To Mode Select\n");
				scanf("%d",&Admin_Mode_Select);
				switch(Admin_Mode_Select){
					case 1:
						Add_New_Patient();break;
					case 2:
						View_Patient_List();break;
					case 3:
						printf("Enter patient ID: ");scanf("%d",&ID);
						Edit_Patient_Record(ID);break;
					case 4:
						 Slot_Reservation();break;
					case 5:
						Cancel_Reservation();break;
					case 6:
						User_Exit_Flag =true;break;
				}
			}
			if(User_Exit_Flag == true){
				break;}
		}/*end of while loop*/
	}/*End of Admin Mode*/	
/*========================User Mode==========================*/
	else if(Mode_Select == 2){ 
		printf("\nUser Mode Activated\n");
		u8 User_Mode_Select = 0; 
		u8 User_Exit_Flag =0 ;
		while(1){
			printf("\nChoose A Function:");
			printf("\n1.View Patient Information");
			printf("\n2.View Today's Patients Schedules");
			printf("\n3.Back To Operation Mode Menu\n");
			scanf("%d",&User_Mode_Select);
			switch(User_Mode_Select){
				case 1:
					View_Patient_Record();break;
				case 2:
					View_Reservations();break;
				case 3:
					User_Exit_Flag =1 ; break;
			}/*End of Switch*/
			if(User_Exit_Flag==1)
				break;
		}
	}
	else break; /*Exits Whole Program*/
}/*end of superloop*/
}/*end of main*/