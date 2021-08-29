/*********************************************************************************************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:8.07.2021
DESCRIPTION	:Write an alternative version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2

OUTPUT		:./a.out
		ENTER STRING1: karthikeyan venugopal
		ENTER STRING2: ktpl
		After squeeze string1: arhieyan venugoa
		DO YOU WANT TO CONTINUE(Y/y): n

*********************************************************************************************************************************************/

#include<stdio.h>
#include<stdio_ext.h>
void squeeze_string(char *, char *);
int str_len(char *);
int main()
{
	char choice;
	char string1[200];
	char string2[200];
	do
	{
	__fpurge(stdin);
	printf("ENTER STRING1: ");
	scanf("%[^\n]",string1);
	__fpurge(stdin);
	printf("ENTER STRING2: ");
	scanf("%[^\n]",string2);
	squeeze_string( string1, string2 );
	printf("After squeeze string1: %s\n",string1);
	printf("DO YOU WANT TO CONTINUE(Y/y): ");
	scanf(" %c",&choice);
	}while(choice=='y' || choice=='Y');
}
void squeeze_string(char *str1, char *str2)
{
	int i,j,index=0,flag=0;			//index for allocating the elements in position as i and j are changing
	int str1_len=str_len(str1), str2_len=str_len(str2);
	for(i=0;i<str1_len;i++)
	{
		for(j=0;j<str2_len;j++)
		{
			if(str1[i]==str2[j])
				flag=1;	
		}
		if(flag==0)
			str1[index++]=str1[i];
		flag=0;
	}
	str1[index]='\0';				//put a NULL at the end of required characters
}

//function to find the length of the string
int str_len(char *str)
{
	int i=0;
	while(str[i])
		i++;
	return i;
}
