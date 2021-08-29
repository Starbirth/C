/*****************************************************************************

DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:14.07.2021
DESCRIPTION	:To implement strtok function.

OUTPUT		:./a.out
ENTER THE STRING1 :Bangalore;:;;;----Chenni;:Kolkata;:Delhi;-:mumbai--
ENTER THE STRING2 :;:/.-
Bangalore
Chenni
Kolkata
Delhi
mumbai

DO YOU WANT TO CONTINUE(y/Y) :y
ENTER THE STRING1 :karthi---keyan;:::
ENTER THE STRING2 :;:-
karthi
keyan

DO YOU WANT TO CONTINUE(y/Y) :n
*****************************************************************************/

#include<stdio.h>
#include<stdio_ext.h>
char *my_strtok(char *,char *);
int str_len(char *);
char *resume;
int main()
{
	char choice, str1[500], str2[50], *print_string;
	do
	{
		__fpurge(stdin);
		printf("ENTER THE STRING1 :");
		scanf("%[^\n]",str1);
		__fpurge(stdin);
		printf("ENTER THE STRING2 :");
		scanf("%[^\n]",str2);
		if(str1[0]=='\0' ||  str2[0] == '\0')		//if entered an empty string, error msg to be printed
		{
			printf("PLEASE ENTER VALID STRING INPUTS\n");
		}
		else
		{
			print_string=my_strtok(str1, str2);		//first call with str1 and str2
			while(print_string != NULL)
			{	
				printf("%s\n",print_string);
				print_string=my_strtok(NULL,str2);
			}
		}
		__fpurge(stdin);
		printf("\nDO YOU WANT TO CONTINUE(y/Y) :");
		scanf(" %c",&choice);
	}while(choice=='y' || choice=='Y');
	return 0;
}

char *my_strtok(char *str1,char *str2)
{
	char *pos;			//to return the base address of the return value
	if(str1 == NULL)		//in first call this  is false
	{
		if(resume==NULL)	
			return NULL;
		char *str;
		int flag, i, len=str_len(str2);
		pos=&resume[1];	//since at the base address of resume '\0' is present, we take the next element as starting
		
		/*to find the address of the non-token character*/
		
		for(i=1; resume[i] != '\0';i++)			//since resume[0]='\0', start from [1]
		{	
			flag=0;
			for(int j=0; str2[j]!='\0'; j++)
			{
				if(resume[i] != str2[j])
					flag++;	
								
			}
			if( flag == len)		//if flag=len, then it is a non-token character
			{				//then assign the starting pos as the present address	
				pos=&resume[i];	
				str=&resume[i];	//use of local variable str with non-token character at [0]
				break;
			}	
		}
		
		if(flag==len-1)			//if throughout remaining everything is token, then flag will be len-1
		{
			return NULL;			
		}
		
		/*to determine the ending address of the string to be retuned*/
		
		for(i=0;str[i]!='\0' ; i++)
		{
			for(int j=0;str2[j]!='\0';j++)
			{
				if(str[i] == str2[j])
				{
					str[i]='\0';		//assigning the end of the string to '\0'
					resume=&str[i];  
					return pos;
				}
			}
		}
		resume=NULL;					//if throughout no next token is found, return the pos, 
								//and changes to return NULL for the next call
		return pos;
	}
	else 
	{
		int i=0, flag, len=str_len(str2);
		pos=str1;
		/*to determine the non-token character address from start*/
		
		for(i;str1[i]!='\0' ; i++)
		{
			flag=0;
			for(int j=0;str2[j]!='\0';j++)
			{
				if(str1[i] != str2[j])
				{
					flag++;
				}
			}
			if( flag==len )
			{
				pos=&str1[i];
				break;					
			}
		}
		
		/*given the token is not repeated in str2 */
		
		if(flag==len-1)			//if throughout remaining everything is token, then flag will be len-1
		{
			return NULL;			
		}
				
		for(i;str1[i]!='\0' ; i++)
		{
			for(int j=0;str2[j]!='\0';j++)
			{
				if(str1[i] == str2[j])
				{
					str1[i]='\0';			
					resume=&str1[i];		//assign the resume address for next call
					return pos;			//return the address of first non-token character in str1
				}
			}
		}
		resume=NULL;			//if no token is found further in str1, for ending the next call, take resume=NULL
		return pos;			//return the pos
	}
}	
int str_len(char *str)
{
	int n=0;
	while(*str++)
		n++;
	return n;
}

	
