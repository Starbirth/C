/***************************************************************************************
NAME		: Karthikeyan.V
DATE		: 8.08.2021
DESCRIPTION	: Print bits of float & double. Check IEEE std.
OUTPUT		:
./a.out 
ENTER THE CHOICE :
1.FLOAT
2.DOUBLE
CHOICE: 1

ENTER THE FLOAT VALUE: 2.3
SIGN	EXPONENT	MANTISSA
-----------------------------------------------
0	10000000	00100110011001100110011

DO YOU WANT TO CONTINUE(y/Y): y
ENTER THE CHOICE :
1.FLOAT
2.DOUBLE
CHOICE: 2

ENTER THE DOUBLE VALUE: -2.3
SIGN	EXPONENT	MANTISSA
-------------------------------------------------------------------------------
1	10000000000	0010011001100110011001100110011001100110011001100110

DO YOU WANT TO CONTINUE(y/Y): n

***************************************************************************************/
#include<stdio.h>
#include<stdio_ext.h>
void print_float(void *);
void print_double(void *);
int main()
{
	char choice;
	int operation;
	float f;
	double d;
	do
	{
		printf("ENTER THE CHOICE :\n1.FLOAT\n2.DOUBLE\nCHOICE: ");
		scanf(" %d",&operation);
		switch(operation)
		{
			case 1:
				printf("\nENTER THE FLOAT VALUE: ");
				scanf("%f",&f);
				printf("SIGN\tEXPONENT\tMANTISSA\n");
				printf("-----------------------------------------------\n");
				print_float(&f);
				break;
			case 2:
				printf("\nENTER THE DOUBLE VALUE: ");
				scanf("%lf",&d);
				printf("SIGN\tEXPONENT\tMANTISSA\n");
				printf("-------------------------------------------------------------------------------\n");
				print_double(&d);
				break;
			default:
				printf("\nERROR : ENTER A VALID OPERATION\n");
				break;	
		}		
		printf("DO YOU WANT TO CONTINUE(y/Y): ");
		__fpurge(stdin);
		scanf(" %c",&choice);
	} while (choice == 'y' || choice == 'Y');
		return 0;
}

/*printing IEEE format of float*/
void print_float(void *ptr)
{
	printf("%d\t",(*(int *)ptr) >> 31 & 1);
	for(int i = 30; i >= 23; i--)
		printf("%d",(*(int *)ptr) >> i & 1);
	printf("\t");
	for(int i = 22; i >= 0; i--)
		printf("%d",(*(int *)ptr) >> i & 1);
	
	printf("\n\n");
	
}

/*printing IEEE format of double*/
void print_double(void *ptr)
{
	
	printf("%d\t",*(((int *)ptr)+1) >> 31 & 1);
	for(int i = 30; i >= 20; i--)
		printf("%d",*(((int *)ptr)+1) >> i & 1);
	printf("\t");
	for(int i = 19; i >= 0; i--)
		printf("%d",*(((int *)ptr)+1) >> i & 1);
	for(int i= 31; i >= 0; i--)
		printf("%d",(*(int *)ptr) >> i & 1);
	printf("\n\n");
}
