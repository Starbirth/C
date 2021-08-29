/*************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:01.06.2021
DESCRIPTION	:2.TO PRINT THE FIBONOCCI SERIRES UPTO INPUT 'N'
OUTPUT		:./a.out
		ENTER THE RANGE FOR FIBONACCI SERIES: -13
		0, -1, 1, -2, 3, -5, 8, -13, 
		DO YOU WISH TO CONTINUE(y/Y): y
		ENTER THE RANGE FOR FIBONACCI SERIES: -21
		0, -1, 1, -2, 3, -5, 8, -13, 21, 
		DO YOU WISH TO CONTINUE(y/Y): n

*************************************************************/

#include<stdio.h>
int main()
{	
	int num, term_1 ,term_2 ,temp, check=1;
	char choice='y';		//initialise choice as 'y'
	for(int i=1;i<=20;i++)		//to set the limits 
		check=check*2;
		
	while (choice=='y' || choice=='Y')		//while the user gives y continue to execute
	{
	printf("ENTER THE RANGE FOR FIBONACCI SERIES: ");
	scanf("%d",&num);
		
		if(num>-check && num<check)		//if the num is within limits execute
		{
			term_1=0;			//first term is 0
			if(num<0)			//for negative series
			{
				term_2=-1;		//second as -1 for negative series
				while(term_1>=num && -term_1>=num)		//if both the term_1 and -term_1 are greater than given -ve num
				{
					printf("%d, ",term_1);
					temp=term_1;
					term_1=term_2;
					term_2=temp-term_1;
				}
				printf("\n");
			}
			
			else if(num>=0)
			{
				term_2=1;		//second term as 1 for positive series
				while(term_1<=num)	//when the term_1 is less than or equal to input
				{	
					printf("%d, ",term_1);
					temp=term_1;
					term_1=term_2;
					term_2=temp+term_1;
				}
				printf("\n");
			}
		}
		else					//error statement for input out of range
		{
		printf("NUMBER OUT OF RANGE, PLEASE ENTER THE VALUE -2^20<'N'<2^20\n");
		}
	printf("DO YOU WISH TO CONTINUE(y/Y): ");	//asks input from user to continue
	scanf(" %c",&choice);				//scan the input choice
	}
	
}
