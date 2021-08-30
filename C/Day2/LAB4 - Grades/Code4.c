#include <stdio.h>

void main()
{
	int x; 
	printf("please enter your grade: ");
	scanf("%d",&x);
	if (x<=50 )
		printf("\n failed");
	else if (x>50 && x<=60)
		printf("\n good");
	else if (x>60 && x<=80)
		printf("\n v.good");
	else if (x>80)
		printf("\n excellent");
}