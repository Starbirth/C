/**********************************************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:2.07.2021
DESCRIPTION	:Replace each string of one or more blanks by a single blank.

OUTPUT		:./a.out

ENTER THE STRING WITH MORE SPACES IN BETWEEN WORDS:
Pointer         sharp 	knives

STRING WITH REDUCED SPACE:
Pointer sharp knives

DO YOU WANT TO CONTINUE(y/Y) :y

ENTER THE STRING WITH MORE SPACES IN BETWEEN WORDS:
	welcome 		to 		the 	wild

STRING WITH REDUCED SPACE:
welcome to the wild

DO YOU WANT TO CONTINUE(y/Y) :n	
**********************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
void remove_spaces(char *str);
int str_len(char *str);
int main()
{	
	char str[200],choice;
	do
	{
	
		__fpurge(stdin);
		printf("\nENTER THE STRING WITH MORE SPACES IN BETWEEN WORDS:\n");
		fgets(str,200,stdin);
		remove_spaces(str);
		printf("\nSTRING WITH REDUCED SPACE:\n%s\n",str);
		__fpurge(stdin);
		printf("DO YOU WANT TO CONTINUE(y/Y) :");
		scanf("%c",&choice);
	
	}while( choice == 'y' || choice== 'Y' );
	
	return 0;
}

/*function to remove the extra spaces*/
void remove_spaces(char *str)
{
	int i, j, char_flag=0, len= str_len(str);
	for(i=0, j=0; i <= len; i++)
	{ 
		if(str[i+1] == '\t')
		{
			str[i+1] = 32;
		}
		
		if( (str[i] != 32 && str[i] != '\t')  || ( str[i] == 32 && str[i+1] != 32 ) )
		{	
			if(char_flag > 0)		//find the first non-space character
				str[j++]=str[i];
			else
				char_flag++;	
		}
	}	
}

/*to find the string length*/
int str_len(char *str)
{	
	int i=0;
	while(*str++)		
		i++; 		//'\0' also included for the length of string
	return i;
}



		
	


