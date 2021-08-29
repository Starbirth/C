/***************************************************************************************
NAME		: Karthikeyan.V
DATE		: 17.06.2021
DESCRIPTION	: Implement your own c-type library (any four).
OUTPUT		:./a.out
		ENTER THE CHARACTER: A
		SELECT AN OPTION:
		1.isalpha
		2.isalnum
		3.isascii
		4.islower
		ENTER YOUR CHOICE: 1
		THE CHARACTER 'A' is an alpha character
		DO YOU WANT TO CONTINUE(y/Y):n


***************************************************************************************/
#include<stdio.h>
int alpha(char ch);
int alnum(char ch);
int ascii(char ch);
int lower(char ch);
int main()
{
	char ch, choice;
	int operation;
	do
	{
	printf("ENTER THE CHARACTER: " );
	scanf(" %c",&ch);
	printf("SELECT AN OPTION:\n1.isalpha\n2.isalnum\n3.isascii\n4.islower\nENTER YOUR CHOICE: ");
	scanf("%d",&operation);
	printf("THE CHARACTER '%c' is ",ch);
	switch(operation)
	{
		case 1:
			alpha(ch)?printf("an alpha character"):printf("not an alpha character");
			break;
		case 2:
			alnum(ch)?printf("an alnum character"):printf("not an alnum character");
			break;
		case 3:
			ascii(ch)?printf("an ascii character"):printf("not an ascii character");
			break;
		case 4:
			lower(ch)?printf("a lower character"):printf("not a lower character");
			break;
		default:
			printf("INVALID CHOICE OF OPERATION");
	}
	printf("\nDO YOU WANT TO CONTINUE(y/Y):");
	scanf(" %c",&choice);
	}while(choice=='y' || choice=='Y');
		
}
int alpha(char ch)		
{
	return ( ch >= 65 && ch<=90 || ch >= 97 && ch <= 122 );		
}
int alnum(char ch)
{
	return ( alpha(ch) || (ch>=48 && ch<=57) );
}
int ascii(char ch)
{
	return ( ch>=0 && ch<=127 );
}
int lower(char ch)
{
	return ( ch >= 65 && ch<=90 );
}
