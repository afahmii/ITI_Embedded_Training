/*
- each node in the linked list data structure holds 2 pointers.
- one pointing at the value of the node and the other pointing at the address of the next node

*/
#ifndef  __Linked_list__
#define __Linked_list__

#include <stdio.h> 
#include <stdlib.h>
#include "..\Datatypes.h"

/* Creating a new struct of type st_node
	with a pointer that points to the first address of its type "st_node" ..(self referencial structs)*/

typedef struct node{
	u16 data;
	struct node * next;
}st_node;



void add_node(u16);
void print_list(void);
void delete_node(u16);
void insert_node (u8 n, u16 val);



#endif /*__Linked_list__*/