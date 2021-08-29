 /*****************************************************************************************************************************
DOCUMENTATION:
NAME		:V.KARTHIEKEYAN
DATE		:8.07.2021
DESCRIPTION	:WAP to print all possible combinations of given string.

OUTPUT		:./a.out
ENTER THE STRING: abc 
abc
acb
bac
bca
cba
cab

DO YOU WANT TO CONTINUE:(y/Y):n
*******************************************************************************************************************************/
#include <stdio.h>
int str_len(char *str);
void swap(char *,char *);
void permute(char *,int , int);
int repeat_check(char *);
int main()
{
	char str[50],choice;
	do
	{
	printf("ENTER THE STRING: ");
	scanf("%s",str);
	int n = str_len(str);
	int check=repeat_check(str);
	
	if(check==1)
		permute(str, 0, n-1);
	else 
		printf("ENTER DISTINCT CHARACTERS AS INPUT\n");
	
	printf("\nDO YOU WANT TO CONTINUE:(y/Y):");
	scanf(" %c",&choice);
	}while(choice=='y' || choice=='Y');
	return 0;
}

/*to swap the elements of the string*/
void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char *str, int start, int end)
{
int i;
if (start == end)
{
	printf("%s\n", str);
}
else
{
	for (i = start; i <= end; i++)
	{	
		swap(str+start, str+i);
		permute(str, start+1, end);
		swap(str+start, str+i); 
	}
}
}

/*string length function*/
int str_len(char *str)
{
	int count=0;
	while(*str++)
		count++;
	return count;
}

/*to check for repeated characters*/
int repeat_check(char *str)
{
	for(int i=0;str[i]!='\0';i++)
	{
		for(int j=i+1;str[j]!='\0';j++)
		{
			if(str[i]==str[j])
				return 0;
		}
	}
	return 1;
}

