/**********************************************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:27.06.2021
DESCRIPTION	:To write a program to count number of characters, words and lines, entered
		 through stdin buffer

OUTPUT		:./a.out
		DKJFKDJF	
		hello	 sdjfkdjf
		sdjfkdj
			3	4	34
		
		DO YOU WANT TO CONTINUE(y/Y): y
		fsdf
			1	1	5 
			
		DO YOU WANT TO CONTINUE(y/Y): n
		
************************************************************************************************/


#include<stdio.h>
#include<stdio_ext.h>
int main()
{	
	char choice;
	do
	{
	char ch;
	__fpurge(stdin);
	int word_count = 0, char_count = 0, line_count = 0,space_flag = 0,char_flag = 0;	
		while((ch = getchar()) != EOF)				//until ctrl+d is entered
		{
			char_count++;		
			
			if(ch == '\t' || ch == '\n' || ch == 32)		//checking for space
				space_flag = 1;
			else
				char_flag = 1;
			
			if(char_flag == 1 && space_flag == 1)		//condition for word_count
			{
				word_count++;
				char_flag = 0;				//set conditions for char and space flags to 0
				space_flag = 0;
			}
			if(ch == '\n')
			{		
				line_count++;
				char_flag = 0;
				space_flag = 0;
			}	
		}
	
	if(char_flag == 1 && ch == EOF)					//if terminated with character at last consider as a word
		word_count++;
		
	fflush(stdout);
	printf("\t%d\t%d\t%d\n", line_count, word_count, char_count);
	
	__fpurge(stdin);
			
	printf("\nDO YOU WANT TO CONTINUE(y/Y): ");
	scanf(" %c",&choice);
	__fpurge(stdin);

	}while( choice == 'y' || choice == 'Y' );
	return 0;
} 
