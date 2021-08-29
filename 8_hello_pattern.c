/*************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:02.06.2021
DESCRIPTION	:8.TO PRINT THE 'X' SHAPE OF HELLO

OUTPUT		:./a.out
ENTER THE PATTERN LINES OF HELLO: 9
Hello        Hello 
 Hello      Hello  
  Hello    Hello   
   Hello  Hello    
    HelloHello    
   Hello  Hello    
  Hello    Hello   
 Hello      Hello  
Hello        Hello 
DO YOU WISH TO CONTINUE(y/Y): n

*************************************************************/
#include<stdio.h>
int main()
{
	int num, check=1;
	char choice='y';		//initialise choice as 'y'
	for(int i=1;i<=5;i++)		//to set the limits 
		check=check*2;
		
	while (choice=='y' || choice=='Y')		//while the user gives y continue to execute
	{
	printf("ENTER THE PATTERN LINES OF HELLO: ");
	scanf("%d",&num);
	if(num<check)
	{
		if(num>0)
		{
			int i,j;			
			for(i=1;i<=num;i++)
			{
			for(j=1;j<=num;j++)
			{
				if(i==j && i+j==num+1)			//to print first hello in the centre line
						printf("Hello");
				else if(i==j || i+j==num+1)		
				{	
					if(num%2!=0)
						printf("Hello ");	//if num is odd print hello with space, else with no space
					else
						printf("Hello");				
				}
				else
				printf(" ");
				if(i==j && i+j==num+1)			//to print second hello in the centre line
						printf("Hello");
					
			}
			printf("\n");
			}
		}
		else
		{
		printf("Please enter only positive numbers\n");
		}
	}
	else
		printf("NUMBER OUT OF RANGE, PLEASE ENTER THE VALUE -2^20<'N'<2^20\n");
	
	
	printf("DO YOU WISH TO CONTINUE(y/Y): ");	//asks input from user to continue
	scanf(" %c",&choice);				//scan the input choice
	}
}
