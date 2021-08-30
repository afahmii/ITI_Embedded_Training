#include "Linked_list.h"



void main(void)
{
	u8 num,val,temp =0;
	u16 node_val ; 
	while(1)
	{
		printf("please choose a mode: \n1. for adding a new node.\n2. for printing the linked list.\n3. to exis\n4. to delete a node\n5. to insert a node.\n");
		scanf("%d",&num);
		switch(num)
		{
			case 1: 
				printf("enter the value you want to add:");
				scanf("%d",&val);
				printf("\n");
				add_node(val);
				printf("node added.\n----------\n");
				break;
			case 2:
				printf("-------------------\n\n");
				print_list();
				printf("\n-------------------\n\n");
				break;
			case 3:
				temp = 1; 
				break;
			case 4:
				printf("please the value to delete:");
				scanf("%d",&node_val);
				printf("-------------------\n\n");
				delete_node(node_val);
				printf("node deleted\n");
				printf("\n-------------------\n\n");
				break;
			case 5:
			printf("please the value to insert:");
			scanf("%d",&node_val);
			printf("please the position:");
			scanf("%d",&num);
			printf("-------------------\n\n");
			insert_node(num,node_val);
			printf("node inserted\n");
			printf("\n-------------------\n\n");
			break;
			default:
			printf("invalid choice.");
		}
		if(temp==1)
			break;
	}
}