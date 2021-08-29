/***************************************************************************************
NAME		: Karthikeyan.V
DATE		: 19.06.2021
DESCRIPTION	: To write a program to swap two variables by using pass by reference method
OUTPUT		: ./a.out
		ENTER A NUMBER NUM1 :2
		ENTER A NUMBER NUM2 :-10
		AFTER SWAPPING,
		NUM1= -10
		NUM2= 2
		DO YOU WANT YOU CONTINUE(y/Y) :n
**************************************************************************************/
#include<stdio.h>
void swap(int *a,int *b);
int main()
{
	
	int a,b;
	char choice;
	do
	{
	printf("ENTER A NUMBER NUM1 :");
	scanf(" %d",&a);
	printf("ENTER A NUMBER NUM2 :");
	scanf(" %d",&b);
	swap(&a,&b);
	printf("AFTER SWAPPING,\nNUM1= %d\nNUM2= %d\n",a,b);
	printf("DO YOU WANT YOU CONTINUE(y/Y) :");
	scanf(" %c",&choice);
	}
	while(choice=='y' || choice=='Y');
}
void swap(int *a,int *b)
{
	*a=*a^*b;		//we get the difference of two numbers	
	//printf("%d\n",*a);
	*b=*a^*b;
	//printf("%d\n",*b);	//we get the a value to b
	*a=*a^*b;
	//printf("%d\n",*a);	//we get the b value to a
}
