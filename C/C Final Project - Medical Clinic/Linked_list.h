/*
- each node in the linked list data structure holds 2 pointers.
- one pointing at the value of the node and the other pointing at the address of the next node

*/
#ifndef  __Linked_list__
#define __Linked_list__

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "Datatypes.h"

/* Creating a new struct of type st_node
	with a pointer that points to the first address of its type "st_node" ..(self referencial structs)*/

typedef struct node{
	u8 name[15];
	u8 age;
	u8 gender;
	u16 ID;
	u8 * res_time;
	struct node * next;
}st_node;


/* typedef struct slot{
	u8 slot_time[5];
}st_slot;
 */

/* 
slot2.slot_time = "3:00";
slot3.slot_time = "3:30";
slot4.slot_time = "4:00";
slot5.slot_time = "4:30"; */

void Add_New_Patient(void);
void View_Patient_List(void);
void Edit_Patient_Record(u16 n);
void Slot_Reservation(void);
void Cancel_Reservation(void);
void View_Patient_Record(void);
void View_Reservations(void);




#endif /*__Linked_list__*/