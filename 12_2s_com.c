/**************************************************************************
NAME		: Karthikeyan.V
DATE		: 08.06.2021
DESCRIPTION	: To print bits of signed and unsigned types for given number and check for 2’s complement
OUTPUT		: ./a.out
		ENTER THE NUMBER: 56
		+56 => 00000000000000000000000000111000
		-56 => 11111111111111111111111111001000
		DO YOU WISH TO CONTINUE(y/Y):y
		ENTER THE NUMBER: -8 
		-8 => 11111111111111111111111111111000
		+8 => 00000000000000000000000000001000
		DO YOU WISH TO CONTINUE(y/Y):n

***************************************************************************/
#include <stdio.h>
int main()
{
	int num,complement;					//to be printed as num and complement
	char choice;
	do					
	{
		printf("ENTER THE NUMBER: ");
		scanf("%d",&num);
		complement=(~num)+1;				//2's complement of given number
		if(num>0)
		
			printf("+%d => ",num);			//if num is positive then print "+" before printing the num
		else
			printf("%d => ",num);
		for(int i=31; i>=0 ;i--)			//to print the binary value of num bit by bit
		{
			printf("%d",((num>>i)&01));		
		}
			printf("\n");
		if(complement>0)
			printf("+%d => ",complement);		//if num is positive then print "+" before printing the num
		else
			printf("%d => ",complement);
		for(int i=31; i>=0 ;i--)			//to print the binary value of 2's complement bit by bit
		{
			printf("%d",((complement>>i)&01));
		}
			printf("\n");
		
	printf("DO YOU WISH TO CONTINUE(y/Y):");
	scanf(" %c",&choice);
	}
	while(choice=='y' || choice=='Y');			//to continue the while loop
	return 0;
}

