#include <stdio.h>

void main()
{
	/*
		abdelrahman ramzi mohamed 
		G1 
		search for value position between 10 numbers 
	*/
	// ID data base 
	int id1 = 800125084, id2 = 800128595, id3 = 800125086;
	// Corresponding passwords 
	int p1 = 0000,			p2 = 0001, 			p3 = 0002;
	// user input 
	int id , p; 
	// asking user to enter his ID 
	printf("please enter your ID: ");
	scanf ("%d",&id);
	// check if ID is avaliable
	if (id == id1|| id==id2 || id == id3)
	{
		printf("ID is correct.\n");
		printf("please enter your password: ");
		scanf ("%d",&p);
		if((p==p1 && id ==id1)||(p==p2&&id==id2)||(p==p3&&id==id3)) //check is passowrd is correct. 
		{
			printf("password is correct.\n");
		}
		else 
			printf("wrong passowrd, pleaes try again.");
	}
	else 
		printf ("ID is invalid, please try again.\n");
	
	
}