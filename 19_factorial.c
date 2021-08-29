/*****************************************************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:24.06.2021
DESCRIPTION	:19. WAP to find factorial for given number using recursive method and without
		 using any other function than main function

OUTPUT		:./a.out

		ENTER THE NUMBER FOR FACTORIAL:5
		THE FACTORIAL IS: 120

		DO YOU WANT TO CONTINUE:y
		
		ENTER THE NUMBER FOR FACTORIAL: 0
		THE FACTORIAL IS: 1

		DO YOU WANT TO CONTINUE:y

		ENTER THE NUMBER FOR FACTORIAL:6
		THE FACTORIAL IS: 720

		DO YOU WANT TO CONTINUE:n
		
*****************************************************************************************************/

#include<stdio.h>
static int num = -1, fact;
int main()
{
	char choice;
	if(num >= 0)
	{
		if(num > 1)
		{
			fact = fact * num;
				main(--num);
		}
		else
		{
			printf("THE FACTORIAL IS: %d\n",fact);
			printf("\nDO YOU WANT TO CONTINUE:");
			scanf(" %c",&choice);
			if( choice == 'Y' || choice == 'y' )		//to execute as new num=-1
				main(num = -1);
			else
				return 1;					
		}
	}
	else if(num < 0)							//num is initialised to -1
	{
		printf("\nENTER THE NUMBER FOR FACTORIAL: ");		
		scanf("%d", &num);
		fact = 1;
		int limit = 1;
		for(int i = 0; i < 20; i++)
		{
			limit = limit * 2;
		}
		if(num < 0 || num > limit)
		{	
			printf("NUMBER IS INVALID\n");		//error msg on invalid input
			printf("\nDO YOU WANT TO CONTINUE:");
			scanf(" %c",&choice);
			if( choice == 'Y' || choice == 'y' )
				main(num = -1);			//to execute as new num=-1
			else
				return 1;					
		}
		else
			main(num);
	}
}
	

