#include <stdio.h>

void main()
{
	char x=0; 
	printf("please enter the result of 3*4\n");
	while(x!=12)
	{
		scanf("%d",&x);
		if(x!=12)
			printf("\ntry again.\n");
	}
	printf("\nyour answer is correct.");
}