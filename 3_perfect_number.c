/****************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:01.06.2021
DESCRIPTION	:3.TO PRINT THE INPUT NUMBER IS PERFECT OR NOT
OUTPUT		:./a.out
		ENTER THE NUMBER FOR PERFECT NUMBER CHECKING: 28
		Yes, entered number 28 is perfect number
		DO YOU WISH TO CONTINUE(y/Y): y
		
		ENTER THE NUMBER FOR PERFECT NUMBER CHECKING: -2
		Invalid input, please enter only positive number
		DO YOU WISH TO CONTINUE(y/Y): n

*****************************************************************/

#include<stdio.h>
int main()
{	
	int num, check=1;
	char choice='y';		//initialise choice as 'y'
	for(int i=1;i<=20;i++)		//to set the limits 
		check=check*2;
		
	while (choice=='y' || choice=='Y')		//while the user gives y continue to execute
	{
	printf("ENTER THE NUMBER FOR PERFECT NUMBER CHECKING: ");
	scanf("%d",&num);
		
		if(num<check)		//if the num is within limits execute
		{	
			int sum=0;	//set sum to zero
			if(num>0)
			{
				for(int i=1;i<=(num/2);i++)	//execute until the num/2	
				{
				if(num%i==0)			//it only allows the divisors of the num
				{
					sum=sum+i;
					}	
				}
				if(sum==num)			//if the sum of divisors equal to input num
				{
					printf("Yes, entered number %d is perfect number\n",num);
				}
				else
				{
					printf("No, entered number %d is not a perfect number\n",num);
				}
			}
			else
			{
			printf("Invalid input, please enter only positive number\n");
			} 
		}
		else					//error statement for input out of range
		{
		printf("NUMBER OUT OF RANGE, PLEASE ENTER THE VALUE -2^20<'N'<2^20\n");
		}
	printf("DO YOU WISH TO CONTINUE(y/Y): ");	//asks input from user to continue
	scanf(" %c",&choice);				//scan the input choice
	printf("\n");
	}
	
}
