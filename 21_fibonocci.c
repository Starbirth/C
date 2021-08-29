/*****************************************************************************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:24.06.2021
DESCRIPTION	:WAP to generate fibbonacci numbers <= 'n' using recursions without using static keyword and global variables.

OUTPUT		:./a.out
		ENTER THE LIMIT FOR FIBONOCCI SERIES :8
		THE FIBONOCCI SERIES IS: 0,1,1,2,3,5,8,
		DO YOU WANT TO CONTINUE:y
		ENTER THE LIMIT FOR FIBONOCCI SERIES :-13
		THE FIBONOCCI SERIES IS: 0,-1,1,-2,3,-5,8,-13,
		DO YOU WANT TO CONTINUE:y
		ENTER THE LIMIT FOR FIBONOCCI SERIES :5
		THE FIBONOCCI SERIES IS: 0,1,1,2,3,5,
		DO YOU WANT TO CONTINUE:n


******************************************************************************************************************************/

#include<stdio.h>
void pos_fibonocci(int num,int first, int second);
void neg_fibonocci(int num,int first, int second);
int main()
{
	int num;
	char choice;
	printf("ENTER THE LIMIT FOR FIBONOCCI SERIES 	:");
	scanf("%d",&num);
	int first_num,second_num;
	printf("THE FIBONOCCI SERIES IS: %d,%d,",first_num=0,second_num=num<0?-1:1);
	if(num>0)
	pos_fibonocci(num,first_num,second_num);
	else
	neg_fibonocci(num,first_num,second_num);
	printf("\nDO YOU WANT TO CONTINUE:");
	scanf(" %c",&choice);
	if( choice == 'Y' || choice == 'y' )
		main();
	return 0;
}
void pos_fibonocci(int num,int first,int second)
{

	int temp=first+second;
	first=second;
	second=temp;
	printf("%d,",second);
	if(first+second<=num)
	{
	pos_fibonocci(num,first,second);		//recursive calling
	}
	else
	return;
}
void neg_fibonocci(int num,int first,int second)
{
	int temp=first-second;
	first=second;
	second=temp;
	printf("%d,",second);
	if(first-second>=num && -(first-second)>=num)
		neg_fibonocci(num,first,second);		//recursive calling
	else
	return;
	
}
