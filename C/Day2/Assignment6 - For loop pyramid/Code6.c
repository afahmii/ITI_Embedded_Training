#include <stdio.h>

void main() 
{
   /*
		abdelrahman ramzi mohamed 
		G1 
		Pyramid of '*'
   */
   int r, space, rows=0;
   int t=0;
   printf("Enter number of rows to print the pyramid: ");
   scanf("%d", &rows);
   printf("\n");
   printf("The Pyramid Pattern for the number of rows are:");
   printf("\n\n");
   for(r=1;r<=rows;++r,t=0)   //responsible for rows of the pyramids 
	{
      for(space=1; space<=rows-r; ++space) //responsible for columns of the pyramids 
	  {
         printf("  ");  //print double space according to the relation space<=rows-r
      }
      while (t!=2*r-1)  // star '*'  numbers in a single row relation is 2('*')-1 
	  {
         printf("* ");
         ++t;
      }
      printf("\n"); //new line 
   }
}