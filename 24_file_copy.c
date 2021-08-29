/***************************************************************************************
NAME		: Karthikeyan.V
DATE		: 8.08.2021
DESCRIPTION	: Implement a my_cp() function
OUTPUT		./a.out file1.txt file2.txt
DATA SUCCESSFULLY COPIED

 ./a.out file1.txt 
ERROR : DESTINATION FILE MISSING

./a.out file.txt file.txt 
ERROR : NO SUCH A FILE

/a.out 
ERROR : FILENAMES NOT PASSED

***************************************************************************************/
#include<stdio.h>
void myfunc_copy(FILE *, FILE *);
int main(int argc, char **argv)
{
	FILE *fptr1, *fptr2;
	if(argc == 3)
	{
		fptr1 = fopen(argv[1], "r");
		if(fptr1 == NULL)
		{
			printf("ERROR : NO SUCH A FILE\n");
			return 0;
		}
		else
		{
			fptr2 = fopen(argv[2], "w");
			myfunc_copy(fptr2, fptr1);
		}
			
	}
	else if(argc == 1)
		printf("ERROR : FILENAMES NOT PASSED\n");
		
	else if(argc == 2)
		printf("ERROR : DESTINATION FILE MISSING\n"); 
		
	return 0;	
}
void myfunc_copy(FILE *dest, FILE *src)
{	
	char ch;
	while(ch = fgetc(src))
	{
		if(feof(src))			//proceed till end of file
		{
			printf("DATA SUCCESSFULLY COPIED\n");
			break;
		}	
		fputc(ch, dest);
	}			
}
