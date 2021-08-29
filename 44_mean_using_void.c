/******************************************************************

DOCUMENTATION:
NAME		: V. KARTHIEKEYAN
DATE		: 15.07.2021
DESCRIPTION	: WAP to implement binary search for all basic datatypes.
OUTPUT		:./a.out

ENTER THE NUMBER OF ELEMENTS IN THE ARRAY :3
CHOOSE THE OPERATION ON: 
1.int
2.short
3.float
4.double
ENTER THE CHOICE: 4
ENTER THE 3 ELEMENTS
[0]-2.35
[1]-2.314
[2]-2.314
mean=2.326 
DO YOU WANT TO CONTINUE(Y/y): y

ENTER THE NUMBER OF ELEMENTS IN THE ARRAY :3
CHOOSE THE OPERATION ON: 
1.int
2.short
3.float
4.double
ENTER THE CHOICE: 1
ENTER THE 3 ELEMENTS
[0]-2
[1]-3
[2]-5
mean=3.33333 
DO YOU WANT TO CONTINUE(Y/y): n
******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
double cal_mean(void *ptr,int n,int );
int main()
{
	int n,i,operation;
	char choice;
	double mean;
	do
	{
	mean = 0;
	void *ptr;
	ptr=NULL;
	printf("\nENTER THE NUMBER OF ELEMENTS IN THE ARRAY :");
	scanf("%d",&n);
	printf("CHOOSE THE OPERATION ON: \n1.int\n2.short\n3.float\n4.double\nENTER THE CHOICE: ");
	scanf("%d",&operation);
	printf("ENTER THE %d ELEMENTS\n",n);
	switch(operation)
	{
		case 1:
			ptr = malloc(n * sizeof(int));
			for(i = 0; i < n; i++)
			{
				printf("[%d]-",i);
				scanf("%d",&*(int *)ptr+i);
			}
			mean=cal_mean(ptr,n, operation);		
			free(ptr);
			break;
		case 2:
			ptr = malloc(n * sizeof(short));
			for(i=0;i<n;i++)
			{
				printf("[%d]-",i);
				scanf("%hd",&*(short *)ptr+i);
			}
			mean=cal_mean(ptr,n, operation);
			free(ptr);
			break;
		case (3):
			ptr =  malloc(n * sizeof(float));
			for(i=0;i<n;i++)
			{
				printf("[%d]-",i);
				scanf("%f",&*(float *)ptr+i);
			}
			mean=cal_mean(ptr,n, operation);
			free(ptr);
			break;
		case (4):
			ptr = malloc(n* sizeof(double));
			for(i=0;i<n;i++)
			{
				printf("[%d]-",i);
				scanf("%lf",&*(double *)ptr+i);
			
			}mean=cal_mean(ptr,n, operation);
			free(ptr);
			break;
		default:
			printf("ENTER VALID CHOICE OF DATA TYPE\n");
			goto error;
	}
	ptr=NULL;
	printf("mean=%g ",mean);
	error:
	__fpurge(stdin);
	printf("\nDO YOU WANT TO CONTINUE(Y/y): ");
	scanf(" %c",&choice);
	}while(choice=='y' || choice=='Y');
	
	return 0;
}

/* calculate mean according to the datatype selected*/
double cal_mean(void *ptr,int n,int operation)
{
	double sum=0;
		if(operation == 1)
		{
			for(int i = 0 ; i < n ; i++)
				sum = sum + *((int *)ptr+i);
		}	
		else if(operation ==2)
		{
			for(int i = 0 ; i < n ; i++)
				sum = sum + *((short *)ptr+i);
		}
		else if(operation == 3)
		{ 
			for(int i = 0 ; i < n ; i++)
				sum = sum + *((float *)ptr+i);
		}
		else if(operation ==4)
		{
			for(int i = 0 ; i < n ; i++)
				sum = sum + *((double *)ptr+i);
		}
	
	return sum/n;	
}
