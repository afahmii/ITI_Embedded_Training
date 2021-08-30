#include <stdio.h>

void main()
{
	/*
		abdelrahman ramzi mohamed 
		G1 
		User Registeration
	*/
	// ID data base 
	int id1 = 1234, id2 = 5678, id3 = 9870;
	// Corresponding passwords 
	int p1 = 7788,  p2 = 5566,  p3 = 1122;
	// user input 
	int id , p,indicator=0; 
	// asking user to enter his ID 
	printf("please enter your ID: ");
	scanf ("%d",&id);
	// check if ID is avaliable
	if (id == id1|| id==id2 || id == id3)
	{
		printf("ID is correct.\n");
		for(int i =0 ; i<3 ;i++)
		{
		printf("please enter your password: ");
		scanf ("%d",&p);
		if((p==p1 && id ==id1)||(p==p2&&id==id2)||(p==p3&&id==id3)) //check is passowrd is correct. 
		{
			printf("password is correct.\n");
			indicator = 0;
			break;
		} 
		indicator =1;
		}
		if(indicator)
		printf("wrong passowrd, no more tries.");
	}
	else 
		printf ("You are not signed, please try again.\n");
	
	
}