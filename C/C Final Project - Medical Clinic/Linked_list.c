#include "Linked_list.h"
#define empty_slot 88
extern st_node * head;
u16 List_Length =0;
extern u8 * ptr_slots_arr[] ;
extern u8 flag_arr [5];

void Add_New_Patient(void)
{
		if(List_Length == 0 )
		{
			st_node * new = (st_node *)malloc(sizeof(st_node));
			head = new;
			
			printf("Enter Patient Name: ");
			scanf("%s",head->name);
			printf("Enter Patient Age: ");
			scanf("%d",&(head ->age));
			printf("Enter Patient Gender(m/f): ");
			scanf(" %c",&(head ->gender));
			printf("Enter Patient ID: ");
			scanf("%d",&(head ->ID));
			head -> next = NULL;
		}
		
		else 
		{
			st_node * last;  
			st_node * new  = (st_node *)malloc(sizeof(st_node));
			printf("Enter Patient Name: ");
			scanf("%s",new->name);
			printf("Enter Patient Age: ");
			scanf("%d",&(new ->age));
			printf("Enter Patient Gender(m/f): ");
			scanf(" %c",&(new ->gender));
			printf("Enter Patient ID: ");
			scanf("%d",&(new ->ID));
			new -> next = NULL;
			last = head ;
			while (last->next != NULL)
			{
				last = last->next;
			}
			last->next = new;
		}
		List_Length++;
		
}

void View_Patient_List(void)
{ 
	
	if(List_Length > 0 )
	{
		u8 i = 1;
		st_node * print;
		print = head;
		
		while (print != NULL)
		{
			printf("-----------------\n\n");
			printf("Patient name is: %s\n",print->name);
			printf("Patient age is: %d\n",print->age);
			printf("Patient gender is: %c\n",print->gender);
			printf("Patient ID is: %d\n",print->ID);
			print = print->next;
			printf("\n\n-----------------");
		}
	}
	else if(List_Length ==0)
	{
		printf("There Are Currently No Patients Registered. \n");
	}

}
void Edit_Patient_Record(u16 ID)
{
	st_node * patient_edit = head;
	
	/* Case 1: the data to edit is in the first node:*/
	if ( patient_edit->ID == ID)
		{			u8 Menu_Exit = 0 ; 
				u16 Patient_Data  =0; 
				printf("Patient name is %s\n",patient_edit->name);
				while(1){
					printf("Select Data to edit\n");
					printf("1.Name\n");
					printf("2.Age\n");
					printf("3.ID\n");
					printf("4.Back To Menu\n");

					scanf("%d",&Patient_Data);
				switch(Patient_Data){
					case 1:
						printf("Enter New Patient Name: ");	scanf("%s",patient_edit->name);	 break;
					case 2:
						printf("Enter New Patient Age: ");		scanf("%d",&(patient_edit ->age)); break;
					case 3:
						printf("Enter New Patient ID: "); 		scanf("%d",&(patient_edit ->ID)); 	 break;
					case 4:
					Menu_Exit =1; break;
				}
				if(Menu_Exit ==1 )
					break;
				}
		}
				
	while(patient_edit-> next != NULL){
		patient_edit = patient_edit->next;
		if ( patient_edit->ID == ID)
		{			u8 Menu_Exit = 0 ; 
				u16 Patient_Data  =0; 
				printf("Patient name is %s\n",patient_edit->name);
				while(1){
					printf("Select Data to edit\n");
					printf("1.Name\n");
					printf("2.Age\n");
					printf("3.ID\n");
					printf("4.Back To Menu\n");

					scanf("%d",&Patient_Data);
					switch(Patient_Data){
					case 1:
						printf("Enter New Patient Name: ");	scanf("%s",patient_edit->name);	 	break;
					case 2:
						printf("Enter New Patient Age: ");		scanf("%d",&(patient_edit ->age)); 	break;
					case 3:
						printf("Enter New Patient ID: "); 		scanf("%d",&(patient_edit ->ID)); 	break;
					case 4:
					Menu_Exit =1; break;
				}
				if(Menu_Exit ==1 )
					break;
				}
		}
		else{
			printf("ID not found");
		}
	}
}
void Slot_Reservation(void){
	
		st_node * new  = (st_node *)malloc(sizeof(st_node));
		new = head ; 
		static u8 slot_no = 9; /*arbitraty number*/ 
		u16 ID = 0; 
		
		/*at the start, all slots are available*/
			printf("\nAvailable Slots are:");
			for(u8 i = 0; i<5;i++){
				if(flag_arr[i]==empty_slot){
					printf("\nslot %d: %s",i+1,ptr_slots_arr[i]);
				}
			}
		printf("\nEnter patient ID:");
		scanf("%d",&ID);
		/*function to check the first patient*/
		if(new->ID == ID ){
			printf("Enter the number of the desired slot:");
			scanf("%d",&slot_no);
			new->res_time = ptr_slots_arr[slot_no-1];
			flag_arr[slot_no-1]=slot_no-1;
			printf("\nslot no %d has been reserved for %s\n\n",slot_no,new->name);
		}
		else if(new->next != NULL){
		while(new->next != NULL){
			new = new->next;
			if(new->ID== ID)
			{
				printf("Enter the number of the desired slot:");
				scanf("%d",&slot_no);
				flag_arr[slot_no-1]=slot_no-1;
				new->res_time = ptr_slots_arr[slot_no-1];
				printf("slot no %d has been reserved for %s\n",slot_no,new->name);
			}
			
			}
		}
		else 
			printf("\nInvalid ID:");
		
		
}
void Cancel_Reservation(void){
	st_node * new  = (st_node *)malloc(sizeof(st_node));
	new = head ; 
	u16 ID =0;
	u8 cancel_flag =1 ;
	printf("Enter patient ID: ");
		scanf("%d",&ID);
		/*function to check the first patient*/
		if(new->ID == ID ){
			for(u8 i = 0 ; i <5;i++){
				if(new->res_time == ptr_slots_arr[i]){
					printf("\n%s was schedualed for %s\n",new->name,new->res_time);
					printf("canceling.....\n");
					flag_arr[i]= empty_slot;
					new->res_time = NULL;
					printf("reservation canceled.\n");
				}
			}
			
		}
		else if(new->next != NULL){
			while(new->next != NULL){
				new = new->next;
				if(new->ID== ID)
				{
					for(u8 i = 0 ; i <5;i++){
						if(new->res_time == ptr_slots_arr[i]){
							printf("\n%s was schedualed for %s\n",new->name,new->res_time);
							printf("canceling.....\n");
							flag_arr[i]= empty_slot;
							new->res_time = NULL;
							printf("reservation canceled.\n");
						}
					}
				}
			
			}
		}
		else 
			printf("\nInvalid ID:");
}
void View_Patient_Record(void){
	static u16 ID= 0;
	st_node * new  = (st_node *)malloc(sizeof(st_node));
	new = head ; 
	printf("Enter patient ID: ");
	scanf("%d",&ID);
		/*function to check the first patient*/
		if(new->ID == ID ){
					printf("\nPatient name is %s\n",new->name);
					printf("Patient age is: %d\n",new->age);
					printf("Patient gender is: %c\n",new->gender);
					printf("Patient ID is: %d\n",new->ID);
		}
		else if(new->next != NULL){
			while(new->next != NULL){
				new = new->next;
				if(new->ID== ID)
				{
					printf("\nPatient name is %s\n",new->name);
					printf("Patient age is: %d\n",new->age);
					printf("Patient gender is: %c\n",new->gender);
					printf("Patient ID is: %d\n",new->ID);
				}
			
			}
		}
		else 
			printf("\nInvalid ID:");
}
void View_Reservations(void){
	
		st_node * new  = (st_node *)malloc(sizeof(st_node));
		new = head ; 
			if(new->res_time != '\0'){
					printf("\nname:%s\nID:%d\nis schedualed for: %s\n",new->name,new->ID,new->res_time);
			}
			while(new->next != '\0'){
			new = new->next;
				if(new->res_time !='\0'){
					printf("\nname:%s\nID:%d\nis schedualed for: %s\n",new->name,new->ID,new->res_time);
				}
			}
		
}
