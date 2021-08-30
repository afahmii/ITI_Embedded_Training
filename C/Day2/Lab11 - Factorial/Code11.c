#include <stdio.h>

void main()
{
	int x,fac=1; 
	printf("enter the number to calc factorial: ");
	scanf("%d",&x);
	
	
		if(x==1 || x ==0)
		{
			fac=1;
		}
		else
		{
			for(;x>0;x--)
			{
				fac = fac*x;
			}
		}
	printf("\nfactorial is: %d",fac);
	
}