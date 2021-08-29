/*************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:01.06.2021
DESCRIPTION	:TO PRINT A NUMBER IS ODD OR EVEN
OUTPUT		:./a.out
		ENTER THE NUM TO CHECK FOR ODD OR EVEN: -32212
		-32212 is a -ve even number
		DO YOU WISH TO CONTINUE(y/Y): y
		ENTER THE NUM TO CHECK FOR ODD OR EVEN: 0
		0 is neither odd nor even
		DO YOU WISH TO CONTINUE(y/Y): n

*************************************************************/

#include<stdio.h>
int main()
{
	int num, check=1;	
	char ch ='y';		//initialise ch as 'y'
	
	for(int i=1;i<=20;i++)
		check=check*2;
		
	while(ch == 'y' || ch == 'Y')		//check for execution condition
	{
	printf("ENTER THE NUM TO CHECK FOR ODD OR EVEN: ");
	scanf("%d", &num);
		if ( num >= -check && num <=check )	//limit -2^20 and 2^20
		{
			if ( num < 0 )
			{
				if (num%2 == 0 )
					printf("%d is a -ve even number\n", num);
				else
					printf("%d is a -ve odd number\n", num);
			}
			
			else if ( num > 0)
			{
				if (num%2 == 0 )
					printf("%d is a +ve even number\n", num);
				else
					printf("%d is a +ve odd number\n", num);
			}
			else
			{
				printf("%d is neither odd nor even\n", num);
			}
			
		}
		else
		{
			printf("Number out of range\n");
		}
	
	printf("DO YOU WISH TO CONTINUE(y/Y): ");				//input from user to continue
	scanf(" %c",&ch);				
	}
}
