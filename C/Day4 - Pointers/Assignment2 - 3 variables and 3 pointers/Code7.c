/*
	abdelrahman ramzi fahmi 
	assignment 2 
*/

#include <stdio.h>

/************main body*********/
void main(void)
{
	int x=5,y=10,z=15;
	int* p = &x;
	int* q = &y;
	int* r = &z;
	int temp=0;
	printf("printing variables x= %d , y=%d , z=%d , p=%d , q=%d , r=%d , *p=%d , *q=%d , *r=%d \n",x,y,z,p,q,r,*p,*q,*r);
	printf("swapping pointers....\n");
	temp=r;
	r = p; p = q; q= temp;
	printf("printing variables x= %d , y=%d , z=%d , p=%d , q=%d , r=%d , *p=%d , *q=%d , *r=%d \n",x,y,z,p,q,r,*p,*q,*r);
}