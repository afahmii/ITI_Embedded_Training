#include "Linked_list.h"

st_node * head;
u16 List_Length =0;

void add_node(u16 val)
{
		if(List_Length == 0 )
		{
			st_node * new = (st_node *)malloc(sizeof(st_node));
			head = new;
			head -> data = val;
			head -> next = NULL;
		}
		else 
		{
			st_node * last;  
			st_node * new  = (st_node *)malloc(sizeof(st_node));
			new -> data = val;
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

void print_list(void)
{ 
	
	if(List_Length > 0 )
	{
		u8 i = 1;
		st_node * print;
		print = head;
		
		while (print != NULL)
		{
			printf("Node number%d value is:%d\n",i++,(print->data));
			print = print->next;
		}
	}
	else if(List_Length ==0)
	{
		printf("there are currently no nodes in the list. \n");
	}

}

void delete_node(u16 n)
{
	st_node * prev = head;
	st_node * next1 = prev->next ;
	
	/* Case 1: the data to delete is in the first node:*/
	if ( head->data ==n)
	{
		st_node * temp = head->next; 
		free(head);
		head = temp;
		List_Length --;
	}
	/*Case 2: the data is at any node but the fist and last nodes:*/
	while(next1->next != NULL)
	{
		if(next1->data == n)
		{
			//printf("prev is: %d \nprev.next is: %d\n next is: %d\n next.next is: %d\n",prev,prev->next,next1,next1->next);
			prev->next = next1->next; /* making the pointer "prev->next" pointing (hold) to the first address of the 3rd node */
			//printf("prev is: %d \nprev.next is: %d\n next is: %d\n next.next is: %d\n",prev,prev->next,next1,next1->next);
			free(next1);                       /* freeing the memory that the second address "next1" points to.  */
			next1= prev->next;            /* reassigning the "next1" pointer to the first address of the 3d node which is "prev->next". 
														note: next1 was a wild pointer after freeing and before assigning*/
			//printf("prev is: %d \nprev.next is: %d\n next is: %d\n next.next is: %d\n",prev,prev->next,next1,next1->next);
			List_Length --;
		}
		else 
		{
			prev = prev->next;
			next1 = prev-> next;
		}
	}
	/* Case 3: the  data is at the last node */
	if(next1->next == NULL )
	{
		free(next1);
		prev->next = NULL;
		List_Length--;
	}
	/*Case 4: there are no nodes*/
	else 
		printf("there are no nodes to be deleted.\n"); 
}

void insert_node (u8 pos, u16 val)
{
	st_node * before; 
	st_node * next_one = head;
	if (pos == 1 )
	{
		st_node * new = (st_node*)malloc (sizeof(st_node));
		new->data = val;
		new->next = head; 
		head = new; 
		List_Length ++;
	}
	else if(pos <= List_Length)
	{
		for (u8 i= 1; i<pos;i++)
		{
			before = next_one;
			next_one = next_one->next;
		}
		st_node * new = (st_node *)malloc (sizeof(st_node));
		new -> data = val;
		new -> next = next_one ;
		before->next = new ;
		List_Length++;
	}
	else 
		printf("invalid position\n");
}


