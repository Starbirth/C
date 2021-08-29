/***********************************************************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:13.07.2021
DESCRIPTION	:Variance calculation with static arrays & with dynamic arrays

OUTPUT		:./a.out
ENTER THE NO. OF ELEMENTS: 10
1.STATIC ALLOCATION
2.DYNAMIC ALLOCATION
ENTER YOUR CHOICE: 1
ENTER THE 10 ELEMENTS
[0]-9
[1]-12
[2]-15
[3]-18
[4]-20
[5]-22
[6]-23
[7]-24
[8]-26
[9]-31
x(input)	D=X-mean	D^2
9		-11		121
12		-8		64
15		-5		25
18		-2		4
20		0		0
22		2		4
23		3		9
24		4		16
26		6		36
31		11		121
Sum=200			Sum=400
THE VARIANCE OF THE ENTERED NUMBERS IS 40

DO YOU WANT TO CONTINUE(y/Y): y
ENTER THE NO. OF ELEMENTS: 10
1.STATIC ALLOCATION
2.DYNAMIC ALLOCATION
ENTER YOUR CHOICE: 2
ENTER THE 10 ELEMENTS
[0]-9
[1]-12
[2]-15
[3]-18
[4]-20
[5]-22
[6]-23
[7]-24
[8]-26
[9]-31
x(input)	D=X-mean	D^2
9		-11		121
12		-8		64
15		-5		25
18		-2		4
20		0		0
22		2		4
23		3		9
24		4		16
26		6		36
31		11		121
Sum=200			Sum=400
THE VARIANCE OF THE ENTERED NUMBERS IS 40

DO YOU WANT TO CONTINUE(y/Y): n
***********************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
static int  variance_calculation(int*, int );
int main()
{
	char choice;
	int operation,n;
	do
	{
		printf("ENTER THE NO. OF ELEMENTS: ");
		scanf("%d",&n);
		printf("1.STATIC ALLOCATION\n2.DYNAMIC ALLOCATION\nENTER YOUR CHOICE: ");
		scanf("%d",&operation);
		printf("ENTER THE %d ELEMENTS\n",n);
		if(operation==1)			//switch case opearation doesn't allow declaration inside case
		{
			int arr[n];			//declare an array of n size
			variance_calculation(arr,n);
			/*
			for(int i=0;i<n;i++)
				printf("%d ",arr[i]);
			//prints the elements without no problem*/
		}
		else if(operation==2)
		{
			int *arr=malloc(n * sizeof(int));		//allocate n*sizeof(int) and return the address to *arr
			if(arr==NULL)
				printf("MEMORY IS NOT ALLOCATED, PLEASE TRY AGAIN WITH LESS ELEMENTS\n");
			else
			{
				variance_calculation(arr,n);
				free(arr);
				arr=NULL;
			}
			/*
			for(int i=0;i<n;i++)
				printf("%d ",arr[i]);
			//accessing the elements after freeing leads to segmentation fault*/
		}
		else
			printf("ENTER VALID CHOICE OF OPERATION\n");
		
		printf("\nDO YOU WANT TO CONTINUE(y/Y): ");
		scanf(" %c",&choice);
	}while( choice == 'y' || choice == 'Y' );
	return 0;	
}
static int variance_calculation(int *arr,int n)
{
	float mean, D, Dsquare_sum=0;
	int sum=0;
	for(int i=0; i<n ; i++)		//scanning and adding the elements of array
	{
	 	printf("[%d]-",i);
		scanf("%d",&arr[i]);
		sum=sum+arr[i];
	}
	mean=sum/n;
	printf("X(input)\tD=X-mean\tD^2\n");
	for(int i=0;i<n;i++)
	{
		D=arr[i]-mean;
		printf("%d\t\t%g\t\t%g\n", arr[i], D, (D*D) );
		Dsquare_sum = Dsquare_sum + (D*D);
	}
	printf("Sum=%d\t\t\t\tSum=%g\nTHE VARIANCE OF THE ENTERED NUMBERS IS %g\n",sum,Dsquare_sum,Dsquare_sum/n);	
}

