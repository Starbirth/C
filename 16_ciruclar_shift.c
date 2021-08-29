/****************************************************************************************
NAME		: Karthikeyan.V
DATE		: 13.06.2021
DESCRIPTION	: Read an integer & a number n. Circular right & left shift the int by n
OUTPUT		:./a.out
		ENTER THE NUMBER FOR ROTATION: -25
		-25
		ENTER THE NUMBER OF SHIFT :3
		POSSIBLE OPERATIONS:
		1.CIRCULAR RIGHT SHIFT
		2.CIRCULAR LEFT SHIFT
		ENTER YOUR CHOICE: 1
		THE BINARY FORM OF NUMBER	:11111111111111111111111111100111
		AFTER CIRCULAR RIGHT SHIFTING BY 3
		THE BINARY FORM OF NUMBER	:11111111111111111111111111111100
		DO YOU WISH TO CONTINUE(y/Y) :n
***************************************************************************************/
#include<stdio.h>

int right_shift(int num,int n);
int left_shift(int num, int n);
int main()
{
	int num,n,operation;
	char choice;
	do
	{
		printf("ENTER THE NUMBER FOR ROTATION: ");
		scanf("%d",&num);
		printf("%d\n",num);
		printf("ENTER THE NUMBER OF SHIFT :");
		scanf("%d",&n);
		printf("POSSIBLE OPERATIONS:\n1.CIRCULAR RIGHT SHIFT\n2.CIRCULAR LEFT SHIFT\nENTER YOUR CHOICE: ");
		scanf("%d",&operation);
		printf("THE BINARY FORM OF NUMBER	:");
				
		for(int i=31;i>=0;i--)				//to print the input num in binary form
		{
			printf("%d",num>>i&01);
		}
		printf("\n");
		
		if(operation==1)				//right shift
		{
			num=right_shift(num,n);
			printf("AFTER CIRCULAR RIGHT SHIFTING BY %d\n",n);
		}
		else if(operation==2)				//left shift
		{
			num=left_shift(num,n);
			printf("AFTER CIRCULAR LEFT SHIFTING BY %d\n",n);
		}
		else						//error, wrong invalid choice
		{
			printf("INVALID CHOICE OF OPERATION");
		}
		
		if(operation==1 || operation==2)
		{
			printf("THE BINARY FORM OF NUMBER	:");
			for(int i=31;i>=0;i--)
			{
				printf("%d",num>>i&01);
			}
			printf("\n");
		}
		printf("DO YOU WISH TO CONTINUE(y/Y) :");
		scanf(" %c",&choice);
	}while(choice=='y' || choice=='Y');
}

int right_shift(int num,int n)
{	

	int mask=(1<<n)-1;		//mask for getting temp	
	int temp = (num & mask);	//to store the value that will be gone during rigt shift
	temp=temp<<(32-n);		//have to replace in (32-n)position
	mask=~(mask<<(32-n));		//mask for num
	num = num>>n;	
	num=num & mask;			//make zero in the placed to be replaced with MSB 'n'bits
	return(temp|num);		
}
int left_shift(int num,int n)
{
	int mask =(1<<n)-1;			//mask for getting temp
	int temp=(num>>(32-n)) & mask;	//for getting temp,temp bits are in position for replacing
	num=num <<n;				//left shift
	return (temp|num);		
}
			
	
	
	

