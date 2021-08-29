/********************************************************************************************
DOCUMENTATION:
NAME		: V. KARTHIEKEYAN
DATE		: 15.07.2021
DESCRIPTION	: Implement binary_search for all data types
OUTPUT		: ./a.out

ENTER THE LENGTH OF THE ARRAY: 3

CHOOSE IN WHICH DATA_TYPE THE OPERATION HAS TO BE DONE: 
1.int
2.Char
3.flaot
4.double
ENTER YOU CHOICE:3

[0]-2.3
[1]-2.5
[2]-2.1
After sorting :2.1 2.3 2.5 
ENTER THE SEARCH ELEMENT :2.3
THE ELEMENT 2.3 IS AT POSITION 1 OF ARRAY
DO YOU WANT TO CONTINUE(Y/y) :y
ENTER THE LENGTH OF THE ARRAY: 5

CHOOSE IN WHICH DATA_TYPE THE OPERATION HAS TO BE DONE: 
1.int
2.Char
3.flaot
4.double
ENTER YOU CHOICE:2
[0]-a
[1]-v
[2]-d
[3]-e
[4]-g
After sorting :a d e g v 
ENTER THE SEARCH ELEMENT :d
THE ELEMENT 100 IS AT POSITION 1 OF ARRAY

ENTER THE LENGTH OF THE ARRAY: 4

CHOOSE IN WHICH DATA_TYPE THE OPERATION HAS TO BE DONE: 
1.int
2.Char
3.flaot
4.double
ENTER YOU CHOICE:4
[0]-2.35
[1]-2.324
[2]-2.2145
[3]-2.145
ENTER THE SEARCH ELEMENT :2.324
THE ELEMENT 2.324 IS AT POSITION 2 OF ARRAY

DO YOU WANT TO CONTINUE(Y/y) :n

***********************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
void intInputSort(void *, int );
void charInputSort(void *, int );
void floatInputSort(void*, int );
void doubleInputSort(void *, int );
int IntBinarySearch(void *, int, int, int);
int CharBinarySearch(void *, int, int, char);
int FloatBinarySearch(void *, int, int, float);
int DoubleBinarySearch(void *, int, int, double);

int main()
{
	int arrayLength, choiceOfOperation;
	char choice;
	do
	{
	int searchResult=-1;
	__fpurge(stdin);
	printf("\nENTER THE LENGTH OF THE ARRAY: ");
	scanf("%d",&arrayLength);
	__fpurge(stdin);
	printf("\nCHOOSE IN WHICH DATA_TYPE THE OPERATION HAS TO BE DONE: ");
	printf("\n1.int\n2.Char\n3.flaot\n4.double\nENTER YOU CHOICE:");
	scanf(" %d",&choiceOfOperation);
	void *ptr;
	ptr=NULL;
	switch(choiceOfOperation)
	{
		case 1:
			ptr=(int *)malloc(arrayLength * sizeof(int));			//alloate memory for int  array
			if(ptr==NULL)
				printf("\nMEMORY NOT ALLOCATED, TRY WITH SMALLER SIZE ARRAY\n");
			else
			{	
				int searchElement;			
				intInputSort(ptr, arrayLength ); 
				printf("\nENTER THE SEARCH ELEMENT :");
				scanf(" %d",&searchElement);
				searchResult = IntBinarySearch(ptr, 0, arrayLength-1, searchElement);
				
				if(searchResult == -1)					//as -1 is not an index of array, keep that for false case
					printf("THE ELEMENT %d IS NOT PRESENT IN THE ARRAY\n",searchElement);
				else
					printf("THE ELEMENT %d IS AT POSITION %d OF ARRAY\n",searchElement, searchResult);
				//free memory
				free(ptr);			
				ptr=NULL;
			}
			break;
		case 2:
			ptr=(char *)malloc(arrayLength * sizeof(char));
			if(ptr==NULL)
				printf("\nMEMORY NOT ALLOCATED, TRY WITH SMALLER SIZE ARRAY\n");
			else
			{
				char searchElement;
				charInputSort(ptr, arrayLength ); 
				printf("\nENTER THE SEARCH ELEMENT :");
				scanf(" %c",&searchElement);
				searchResult = CharBinarySearch(ptr, 0, arrayLength-1, searchElement);
				if(searchResult == -1)
					printf("THE ELEMENT %hd IS NOT PRESENT IN THE ARRAY",searchElement);
				else
					printf("THE ELEMENT %hd IS AT POSITION %d OF ARRAY",searchElement, searchResult);
				free(ptr);
				ptr=NULL;
			}
			break;
		case 3:
			ptr=(float *)malloc(arrayLength * sizeof(float));
			if(ptr==NULL)
				printf("\nMEMORY NOT ALLOCATED, TRY WITH SMALLER SIZE ARRAY\n");
			else
			{
				float searchElement;
				floatInputSort(ptr, arrayLength ); 
				__fpurge(stdin);
				printf("\nENTER THE SEARCH ELEMENT :");
				scanf(" %f",&searchElement);
				searchResult = FloatBinarySearch(ptr, 0, arrayLength-1, searchElement);
				if(searchResult == -1)
					printf("THE ELEMENT %g IS NOT PRESENT IN THE ARRAY",searchElement);
				else
					printf("THE ELEMENT %g IS AT POSITION %d OF ARRAY",searchElement, searchResult);
			free(ptr);
			
			}
			break;
		case 4:
			ptr=(double *)malloc(arrayLength * sizeof(double));
			if(ptr==NULL)
				printf("\nMEMORY NOT ALLOCATED, TRY WITH SMALLER SIZE ARRAY\n");
			else
			{
				double searchElement;
				doubleInputSort(ptr, arrayLength ); 
				__fpurge(stdout);
				printf("\nENTER THE SEARCH ELEMENT :");
				scanf(" %lf",&searchElement);
				searchResult = DoubleBinarySearch(ptr, 0, arrayLength-1, searchElement);
				if(searchResult == -1)
					printf("THE ELEMENT %g IS NOT PRESENT IN THE ARRAY",searchElement);
				else
					printf("THE ELEMENT %g IS AT POSITION %d OF ARRAY",searchElement, searchResult);
			free(ptr);
			ptr=NULL;
			}
			break;
		default:
			printf("\nERROR: ENTER VALID CHOICE OF OPERATION\n");
			break;
	}
	__fpurge(stdin);
	printf("\nDO YOU WANT TO CONTINUE(Y/y) :");
	scanf(" %c",&choice);
	}while ( choice == 'y' || choice == 'Y' );		
}
void intInputSort(void *ptr,int n )
{
	for(int i=0;i<n;i++)
	{
		printf("[%d]-",i);
		scanf("%d",(int *)ptr+i);
	}
	
	int temp, i, j;
	/* bubble sorting in ascending order*/
	for(i=0; i<n-1; i++)
	{	
		for(j=0; j<n-i-1; j++)
		{
			if( *((int *)ptr+j) > *((int *)ptr+j+1))		
			{
			 	
			 	temp=*((int *)ptr+j);
			 	*((int *)ptr+j)=*((int *)ptr+j+1);
			 	*((int *)ptr+j+1)=temp;
			}
		}	
	}
	printf("After sorting :");	
	for(int i=0;i<n;i++)
	{
		printf("%d ",*((int *)ptr+i));
	}
}
void charInputSort(void *ptr,int n )
{
	for(int i=0;i<n;i++)
	{
		printf("[%d]-",i);
		scanf(" %c",(char *)ptr+i);
	}
	
	char temp;
	int i, j;
	/* bubble sorting in ascending order*/
	for(i=0; i<n-1; i++)
	{	
		for(j=0; j<n-i-1; j++)
		{
			if( *((char*)ptr+j) > *((char*)ptr+j+1))
			{
			 	
			 	temp=*((char*)ptr+j);
			 	*((char*)ptr+j)=*((char*)ptr+j+1);
			 	*((char*)ptr+j+1)=temp;
			}
		}	
	}
	printf("After sorting :");	
	for(int i=0;i<n;i++)
	{
		printf("%c ",*((char *)ptr+i));
	}
}
void floatInputSort(void *ptr, int n)
{
	for(int i=0;i<n;i++)
	{	
		printf("\n[%d]-",i);
		scanf("%f",(float *)ptr+i);
	}
	float temp;
	int i,j;
	/* bubble sorting in ascending order*/
	for(i=0; i<n-1; i++)
	{	
		for(j=0; j<n-i-1; j++)
		{
			if( *((float*)ptr+j) > *((float*)ptr+j+1))
			{
			 	
			 	temp=*((float*)ptr+j);
			 	*((float*)ptr+j)=*((float*)ptr+j+1);
			 	*((float*)ptr+j+1)=temp;
			}
		}	
	}
	printf("After sorting :");	
	for(int i=0;i<n;i++)
	{
		printf("%g ",*((float *)ptr+i));
	}
}
void doubleInputSort(void *ptr,int n )
{
	for(int i=0;i<n;i++)
	{
		printf("[%d]-",i);
		scanf("%lf",(double *)ptr+i);
	}
	
	double temp;
	int i,j;
	/* bubble sorting in ascending order*/
	for(i=0; i<n-1; i++)
	{	
		for(j=0; j<n-i-1; j++)
		{
			if( *((double*)ptr+j) > *((double*)ptr+j+1))
			{
			 	
			 	temp=*((double*)ptr+j);
			 	*((double*)ptr+j)=*((double*)ptr+j+1);
			 	*((double*)ptr+j+1)=temp;
			}
		}	
	}
	printf("After sorting :");	
	for(int i=0; i<n; i++)
	{
		printf("%lf ",*((double *)ptr+i));
	}
}
/*binary search for int*/
int IntBinarySearch(void *ptr, int start, int end, int element)
{	
	int middle;
	while(start <= end)
	{
		middle = start + (end-start) / 2;
		if( *((int *)ptr+middle) == element )
			return middle;
		else if(  *((int *)ptr+middle) > element )
			end = middle-1;
		else if( *((int *)ptr+middle) < element )
			start = middle+1;
	}
	return -1;
}

/*binary search for Char*/
int CharBinarySearch(void *ptr, int start, int end, char element)
{	
	int middle;
	while(start <= end)
	{
		middle = start + (end-start) / 2;
		if( *((char *)ptr+middle) == element )
			return middle;
		else if(  *((char *)ptr+middle) > element )
			end = middle-1;
		else if( *((char *)ptr+middle) < element )
			start = middle+1;
	}
	return -1;
}

/*binary search for float*/
int FloatBinarySearch(void *ptr, int start, int end, float element)
{	
	int middle;
	while(start <= end)
	{
		middle = start + (end-start) / 2;
		if( *((float *)ptr+middle) == element )
			return middle;
		else if(  *((float *)ptr+middle) > element )
			end = middle-1;
		else if( *((float *)ptr+middle) < element )
			start = middle+1;
	}
	return -1;
}

/*binary search for double*/
int DoubleBinarySearch(void *ptr, int start, int end, double element)
{	
	int middle;
	while(start <= end)
	{
		middle = start + (end-start) / 2;
		if( *((double *)ptr+middle) == element )
			return middle;
		else if(  *((double *)ptr+middle) > element )
			end = middle-1;
		else if( *((double *)ptr+middle) < element )
			start = middle+1;
	}
	return -1;
}


	
	
	
	
	
	
	
	
	
