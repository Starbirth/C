/***************************************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:6.07.2021
DESCRIPTION	:WAP to Generate consecutive NRPS of length n using k distinct character

OUTPUT		:./a.out
		ENTER THE NUMBER OF CHARACTERS K: 3
		ENTER THE LENGTH OF STRING N: 8
		ENTER 3 DISTINCT CHARACTERS :a b c
		abcbcaca
		DO YOU WANT TO CONTINUE(y/Y): n
****************************************************************************************/

#include<stdio.h>
#include<stdio_ext.h>
void shift(char *,int);
int repeat_check(char *);
int main()
{
	char choice;
	int k,n;
	do
	{
		printf("ENTER THE NUMBER OF CHARACTERS K: ");
		scanf("%d",&k);
		if(1<=k && k<=9)				//checking for k limit
		{
			char string[k];
			printf("ENTER THE LENGTH OF STRING N: ");
			scanf("%d",&n);
			if(n>0)				//positive length of string
			{
				__fpurge(stdin);
				printf("ENTER %d DISTINCT CHARACTERS :",k);
				for(int i=0;i<k;i++)
					scanf(" %c",&string[i]);	//getting input characters
				__fpurge(stdin);
				int check=repeat_check(string);	//check for repeatiton
				if(check==1)
				{	
				int count=0;
				while(count<n)
				{
					for(int i=0;string[i]!='\0';i++)
					{
						if(count<n)
						{	
							printf("%c",string[i]);		//printint the elements and left shifting
							count++;
						}
						else 
							break;
					}
				shift(string,k);						//left shift	abc==>bca
				}
				}
				else 
				{
				printf("\nERROR:ENTER DISTINCT CHARACTERS AS INPUT\n");
				}
			}
			else
				printf("ENTER ONLY POSITIVE INTEGERS\n");
		}
		else
			printf("ENTER 1<=k<=9\n");
		printf("\nDO YOU WANT TO CONTINUE(y/Y): ");
		scanf(" %c",&choice);
	}while(choice=='y' || choice=='Y');
}
void shift(char *input,int k)
{
	char temp=input[0];
	for(int i=0;i<k-1;i++)
		input[i]=input[i+1];
	input[k-1]=temp;
}

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
	
	
	
	
		
