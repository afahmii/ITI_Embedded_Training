#include <stdio.h>
int x = 100, y = 600;
void swap (void);
void main()
{
	printf("number 1 : %d and number 2: %d ", x ,y);
	//printf ("swapped: %d and %d ",x,y );
		swap();
		printf(" Swapped number 1 : %d and number 2: %d ", x ,y);
}
void swap (void)
{
	int temp = x; 
	x = y; 
	y = temp ;
}