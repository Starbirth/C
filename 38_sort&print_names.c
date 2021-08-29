/*********************************************************************************************
DOCUMENTATION:
NAME		:V.KARTHIEKEYAN
DATE		:22.07.2021
DESCRIPTION	:Read n & n person names of maxlen 32. Sort and print the names

OUTPUT		:./a.out

ENTER THE NUMBER OF NAMES TO BE ENTERED :5  

ENTER THE NAMES OF LENGTH MAX 32 CHARACTERS IN EACH
[0] - Delhi
[1] - Agra
[2] - Kolkata
[3] - Bengaluru
[4] - Chennai

THE SORTED NAMES ARE:
Agra
Bengaluru
Chennai
Delhi
Kolkata
DO YOU WANT TO CONTINUE(Y/y): n
***********************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
int my_strcmp(char *, char *);
int main()
{
	char choice, ch;
	char **array;
	int names_count, i, j;
	do
	{
		__fpurge(stdin);
		int char_count_condition = 1;
		
		printf("\nENTER THE NUMBER OF NAMES TO BE ENTERED :");
		scanf("%d",&names_count);
		
		int output_pos[names_count];
		array=malloc(sizeof(char *) * names_count);
		printf("\nENTER THE NAMES OF LENGTH MAX 32 CHARACTERS IN EACH\n");
		
		/*inputing the string and keep count of the characters range within 32*/
		for(i=0; i<names_count; i++)
		{
			output_pos[i] = i;
			array[i]=(char *)malloc(sizeof(char) *32);	
			printf("[%d] - ",i);
			j=0;
			__fpurge(stdin);
			while((ch = getchar()) != '\n' && j < 32)
			{
				array[i][j] = ch;
				j++;					
			}
			__fpurge(stdin);
			array[i][j]='\0';
			if(j >= 32)
			{
				char_count_condition = 0;
				break;
			}
		}
		
		if(char_count_condition == 0) 
		{
			printf("\nERROR: MAX 32 CHARACTERS EXECEEDED\n");		
		}
		/*sorting the array doing string compare*/
		else
		{
		for(i=0; i<names_count-1; i++)
			for(j=0; j<names_count-1-i; j++)
				if(my_strcmp(array[output_pos[j]], array[output_pos[j+1]]) > 0)
					output_pos[j] = output_pos[j] + output_pos[j+1] - (output_pos[j+1] =output_pos[j]);	
		
		printf("\nTHE SORTED NAMES ARE:\n");
		for(i=0; i<names_count; i++)
			printf("%s\n",array[output_pos[i]]);
		}
		
	__fpurge(stdin);
	printf("DO YOU WANT TO CONTINUE(Y/y): ");
	scanf(" %c",&choice);
	
	}while(choice=='y' || choice=='Y');
	return 0;
}

/*string compare without case sensitive*/
int my_strcmp(char *str1, char *str2)
{
	while( *str1 && *str2 )
	{
		if(*str1 != *str2)
		{
			 if((*str1 >= 97 && *str1 <= 122) && (*str2 >= 65 && *str2 <= 90))
			 {
			 	if(*str1 != *str2 + 32)
			 	{
			 		return ((*str1) - *str2+32);
			 	}
			 }
			 else if((*str2 >= 97 && *str2 <= 122 && *str1 >= 65 && *str1 <= 90))
			 {
			 	if(*str1+32 != *str2 )
			 	{
			 		return ((*str1 + 32) - (*str2));
			 	}
			 }
			 else
			 {
			  	return (*str1 - *str2);
			 }
		}
		*str1++;
		*str2++;
	}
	return (*--str1 - *--str2);
}






