/***************************************************************************************
NAME		: Karthikeyan.V
DATE		: 09.06.2021
DESCRIPTION	: Given a number n, WAP to print all primes smaller than or equal to n. Use Sieve of Eratosthenes method
OUTPUT		:./a.out
		ENTER THE LIMIT FOR FINDING PRIME NUMBERS :29
		THE PRIME NUMBER WITHIN THE LIMIT 29 ARE
		2,3,5,7,11,13,17,19,23,29,
		DO YOU WISH TO CONTINUE(y/Y):y
		ENTER THE LIMIT FOR FINDING PRIME NUMBERS :5
		THE PRIME NUMBER WITHIN THE LIMIT 5 ARE
		2,3,5,
		DO YOU WISH TO CONTINUE(y/Y):n

***************************************************************************************/


#include<stdio.h>
int main()
{
	char choice;
	int num,limit=1;
	for(int i=0;i<20;i++)
	{
		limit=limit*2;
	}
	do
	{
		printf("ENTER THE LIMIT FOR FINDING PRIME NUMBERS :");
		scanf("%d",&num);
		if(num<limit)				//limit check(2^20)
		{
			if(num>0)			//valid number check
			{
				int array[num],index=0;
				for(int i=2;i<=num;i++,index++)		//to get an array from 2 to 'num'
				{
					array[index]=i;
				}
				
				for(int x=0;x<index;x++)
				{
				for(int y=x+1;y<index;y++)
				{	
					if(array[x]!=0 && array[y]!=0 && array[y]%array[x]==0)		//make the numbers divisible from former number 0
						array[y]=0;
				}
				}
				printf("THE PRIME NUMBER WITHIN THE LIMIT %d ARE\n", num);
				for(int i=0;i<index;i++)
				{	if(array[i]!=0)			//to print the array except 0 value elements
						printf("%d,",array[i]);
				}
				printf("\n");
			}
			else				//error msg for negative input
			{
			printf("INVALID INPUT, ENTER ONLY POSITIVE VALUES\n");
			}
		}			
		else					//error msg for limit exceed
		{
			printf("INPUT NUMBER OUT OF RANGE\n");
		}
		
		printf("DO YOU WISH TO CONTINUE(y/Y):");
		scanf(" %c",&choice);				
	}
	while(choice=='y' || choice=='Y');			//ask the user for loop continuation
	return 0;
}	
