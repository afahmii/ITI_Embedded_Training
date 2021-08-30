#include <stdio.h>

void main()
{
	/*
		abdelrahman ramzi mohamed 
		G1 
		Max of 3 numbers
	*/
	  float m,n,p; //variables to store numbers
	printf("please enter 3 numbers: ");
    scanf("%f%f%f", &m,&n,&p); //
    if(m >= n && m >= p){
        printf("Max number is %f",m);
    } else if(n >= p && n >= m) {
        printf("Max number is %f",n);
    } else{    
        printf("Max number is %f",p);
    }
}