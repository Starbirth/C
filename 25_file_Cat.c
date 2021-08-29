/*****************************************************************************************
DOCUMENTATION:

NAME		: Karthikeyan.V
DATE		: 11.08.2021
DESCRIPTION	: WAP to concatenate two files
OUTPUT		:

./a.out file1.txt file2.txt file3.txt 
DATA SUCCESSFULLY COPIED TO DESTINATION FILE
DATA SUCCESSFULLY COPIED TO DESTINATION FILE

./a.out file1.txt
karthi

END OF FILE REACHED

 ./a.out file1.txt file2.txt
karthi
karthi

./a.out
hello
hello

./a.out
hello this is karthikeyan
hello this is karthikeyan

******************************************************************************************/
#include<stdio.h>
void myfunc_cat(FILE *, FILE *);

int main(int argc, char **argv)
{
	FILE *fptr1, *fptr2, *fptr3;
	if(argc == 4)
	{
		fptr1 = fopen(argv[1], "r");
		fptr2 = fopen(argv[2], "r");
		if(fptr1 == NULL || fptr2 == NULL)
		{
			printf("ERROR : NO SUCH A FILE\n");
			return 0;
		}
		else
		{
			fptr3 = fopen(argv[3], "w");
			myfunc_cat(fptr3, fptr1);
			myfunc_cat(fptr3, fptr2);
		}	
	}
	
	else if( argc == 3 )
	{
		fptr1 = fopen(argv[1], "r");
		fptr2 = fopen(argv[2], "r");
		if(fptr1 == NULL || fptr2 == NULL)
		{
			printf("ERROR : NO SUCH A FILE\n");
			return 0;
		}
		char ch;
		
		while(ch = fgetc(fptr1))
		{
			if(feof(fptr1))			//proceed till end of file
			{					
				break;
			}	
			putchar(ch);
		}
		while(ch = fgetc(fptr2))
		{
			if(feof(fptr2))			//proceed till end of file
			{					
				break;
			}	
			putchar(ch);
		}		
		
	} 
	
	else if( argc == 2 )
	{
		fptr1 = fopen(argv[1], "r");
		if(fptr1 == NULL)
		{
			printf("ERROR : NO SUCH A FILE\n");
			return 0;
		}
		else
		{
			char ch;
			while(ch = fgetc(fptr1))
			{
				if(feof(fptr1))			//proceed till end of file
				{
					printf("\nEND OF FILE REACHED\n");
					break;
				}	
				putchar(ch);
			}	
		}
	}
	
	else if( argc == 1 )
	{
		char *str, ch;
		while((ch = getchar()) != '\n')
		{
			putchar(ch);
		}
		printf("\n");
	}
	
	else
	{
		printf("\nINVALID ENTRY OF DATAS\n");
	}
	
	return 0;	
}

void myfunc_cat( FILE *dest, FILE *src )
{	
	char ch;
	while( ch = fgetc(src) )
	{
		if( feof(src) )			//proceed till end of file
		{
			printf("DATA SUCCESSFULLY COPIED TO DESTINATION FILE\n");
			break;
		}	
		fputc( ch, dest );
	}			
}
