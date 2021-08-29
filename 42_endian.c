/****************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:23.06.2021
DESCRIPTION	:WAP to check your processor endianess	
OUTPUT		:./a.out
		ENTER ANY NUMBER: 25
		LITTLE ENDIAN SYSTEM
		DO YOU WANT TO CONTINUE:n
		
****************************************************************/

#include<stdio.h>
int endian(unsigned int num,char *cptr);
int main()
{
	char choice;
	unsigned int num=0;
	char *cptr;
	cptr=(char *)&num;
	printf("ENTER ANY NUMBER: ");
	scanf("%d",&num);
	endian(num,cptr);
	printf("\nDO YOU WANT TO CONTINUE:");
	scanf(" %c",&choice);
	if( choice == 'Y' || choice == 'y' )
		main();
	return 0;
}
int endian(unsigned int num, char *cptr)
{
	int check = 0xff & num;				//take the first byte 
	if( check == *cptr )				//*cptr points to first byte 
		printf("LITTLE ENDIAN SYSTEM");
	else 						//*cptr points to last byte
		printf("BIG ENDIAN SYSTEM");
}
