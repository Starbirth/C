/*****************************************************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:25.06.2021
DESCRIPTION	: 30. WAF read_int to read an integer

OUTPUT		:./a.out
		ENTER THE NUMBER :-212
		num=-212
		DO YOU WANT TO CONTINUE(y/Y) : y
		ENTER THE NUMBER :+212
		num=212
		DO YOU WANT TO CONTINUE(y/Y) : y
		ENTER THE NUMBER :545fds
		num=545
		DO YOU WANT TO CONTINUE(y/Y) : n

*****************************************************************************************************/
#include<stdio.h>
#include<stdio_ext.h>
int read_int(void);
int is_digit(char num);
int main()
{
	char choice;
	int num;
	do{
		__fpurge(stdin);			//for clearing the input buffer
		printf("ENTER THE NUMBER :");
		num=read_int();			//function call
		printf("num=%d\n",num);
		__fpurge(stdin);
		printf("DO YOU WANT TO CONTINUE(y/Y) : ");
		scanf(" %c",&choice);
	}while( choice=='y' || choice=='Y');
	return 0;
}			

int read_int(void)
{
	
	int num=0,i=0,flag=0;
	char digit;
	while((digit=getchar())!='\n')		//gets input until user enter '\n'
	{
		if(digit=='+' || digit=='-')		//it h	as to get symbols as a first character, othercases , exit
		{	
			if(i==0 && digit=='-')
				flag=1;
			if(i>0)
				break;				
		}
		else if(is_digit(digit))		//own function for isdigit check
			num=(num*10)+(digit-'0');	//converting from char to num		
		else
			break;
		
		i=1;
	}
	if(flag==1)
		return num*-1;
	return num;
}
int is_digit(char num)
{
	if(num>=48 && num<=57)			//if char is from 0-9
		return 1;
	else 
		return 0;
}
