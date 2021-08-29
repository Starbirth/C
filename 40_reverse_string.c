/*****************************************************************************************************************************
DOCUMENTATION:
NAME		:V.KARTHIEKEYAN
DATE		:8.07.2021
DESCRIPTION	:Read a string and reverse string without storing in another array using recursive method and non-recursive method.

OUTPUT		:./a.out
		1.Iterative method
		2.Recursive method
		Enter you choice:1
		ENTER A STRING:HELLO hai
		REVERSE STRING IS : iah OLLEH
		
		DO YOU WANT TO CONTINUE(Y/y): y
		1.Iterative method
		2.Recursive method
		Enter you choice:2
		ENTER A STRING:Karthikeyan V 
		REVERSE STRING IS : V nayekihtraK
		
		DO YOU WANT TO CONTINUE(Y/y): n
******************************************************************************************************************************/

#include<stdio.h>
#include<stdio_ext.h>
int str_len(char *);
void iterative_reverse(char *);
void recursive_reverse(char *, int, int );
int str_len(char *);
int main()
{
	int operation;
	char choice,str[200];
	do
	{
		printf("1.Iterative method\n2.Recursive method\nEnter you choice:");
		scanf("%d",&operation);
		printf("ENTER A STRING:");
		__fpurge(stdin);
		scanf("%[^\n]",str);
		
		if(operation==1)
		{
			iterative_reverse(str);
			printf("REVERSE STRING IS : %s\n",str);
		}
		else if(operation ==2)
		{
			recursive_reverse(str,0,str_len(str)-1);		//call with first and last indices
			printf("REVERSE STRING IS : %s\n",str);
		}
		else
		{
		printf("ENTER VALID CHOICE OF OPERATION");
		}
		
		printf("\nDO YOU WANT TO CONTINUE(Y/y): ");
		scanf(" %c",&choice);
	}
	while(choice=='y' || choice=='Y');
}
void iterative_reverse(char *str)
{
	char ch;
	for(int i=0,j=str_len(str)-1;i<j;i++,j--)		//to initialise i to first element and j to last
	{	//swap the elements
		ch=str[i];	
		str[i]=str[j];
		str[j]=ch;
	}
}
void recursive_reverse(char *str, int left, int right)
{		
	//swap the elements
	if(left>=right)
		return;
		
	char ch=str[left];
	str[left]=str[right];
	str[right]=ch;
	
	recursive_reverse(str,++left,--right);		//recursive call

}
int str_len(char *str)
{		
	int i=0;
	while(str[i])
		i++;
	return i;
}







