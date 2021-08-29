/**************************************************************************
NAME		: Karthikeyan.V
DATE		: 08.06.2021
DESCRIPTION	: To check a given number is even or odd and it’s sign using bitwise operators
OUTPUT		: ./a.out
		ENTER THE VALUE OF 'N': -25
		-25 is -ve odd number
		DO YOU WISH TO CONTINUE (Y/y):y
		ENTER THE VALUE OF 'N': 25
		25 is +ve odd number
		DO YOU WISH TO CONTINUE (Y/y):n


***************************************************************************/


#include<stdio.h>
int main()
{
	char choice;
	int input,first_bit,last_bit;
	do
	{
	printf("ENTER THE VALUE OF 'N': ");
	scanf("%d",&input);
	first_bit=(input>>31 & 01);		// to get the first bit of input
	last_bit= (input & 01);		//to get the last bit of input
	printf("%d is ",input);
	if(first_bit==1)			//first bit==1(-ve number) or first bit==0(+ve number)
	{
		if(last_bit==1)			//last bit==1 =>odd number
			printf("-ve odd number\n");	
		else if(last_bit==0)
			printf("-ve even number\n");	//last bit==1 =>even number
		
	}
	else
	{
		if(last_bit==1)
			printf("+ve odd number\n");
		else if(last_bit==0)
			printf("+ve even number\n");
	
		
	}
	printf("DO YOU WISH TO CONTINUE (Y/y):");
	scanf(" %c",&choice);
	}
	while(choice=='y' || choice=='Y');		//input from user to continue the loop
	return 0;
}
