/***************************************************************************************
NAME		: Karthikeyan.V
DATE		: 13.06.2021
DESCRIPTION	: 15.Replace n bits from pos
OUTPUT		: ./a.out
		ENTER THE VALUE OF 'n' : 11
		ENTER THE VALUE OF 'i' : 174
		ENTER THE VALUE OF 'a' : 3
		ENTER THE VALUE OF 'b' : 5
		THE BINARY FORM OF 'n'	:00000000000000000000000000001011
		THE BINARY FORM OF 'i'	:00000000000000000000000010101110
		UPDATED FORM OF 'i'(158):00000000000000000000000010011110
		DO YOU WISH TO CONTINUE(y/Y):n

***************************************************************************************/


#include<stdio.h>
int replace_nbits_from_pos(int num, int n, int pos, int val);		//function declaration
int main()
{
	char choice;
	int num,i,a,b,new_i_value;
	do
	{	
		printf("ENTER THE VALUE OF 'n' : ");
		scanf("%d",&num);
		printf("ENTER THE VALUE OF 'i' : ");
		scanf("%d",&i);
		printf("ENTER THE VALUE OF 'a' : ");
		scanf("%d",&a);
		printf("ENTER THE VALUE OF 'b' : ");  
		scanf("%d",&b);
		if(a>0 && a<=31)			
		{
			if(a<=b && b<=31)
			{
				new_i_value=replace_nbits_from_pos(i, b - a + 1, b, num);		//function call
				
				printf("THE BINARY FORM OF 'n'	:");
				for(int j=31;j>=0;j--)						//to print the num in binary form
					{
					printf("%d",(num>>j)&01);
					}
					
				printf("\nTHE BINARY FORM OF 'i'	:");			//to print the 'i' in binary form
				for(int j=31;j>=0;j--)			//to print 			
					{
					printf("%d",(i>>j)&01);
					}
					
				printf("\nUPDATED FORM OF 'i'(%d):",new_i_value);
				for(int j=31;j>=0;j--)						//to print the new value of 'i' in binary form
					{
					printf("%d",(new_i_value>>j)&01);
					}
			}
			else			
			{
				printf("b is not within limits a<=b<=31");
			}
		}
		else
		{
			printf("a is not within limits 0<a<=31");
		}
		
		printf("\nDO YOU WISH TO CONTINUE(y/Y):");
		scanf(" %c",&choice);					//user choice of continuation
		printf("\n");
	}	
	while(choice=='y' || choice=='Y');
}

int replace_nbits_from_pos(int val,int n, int b,int num)	
{
	int move=b-n+1;		//calculate the no of shift 
	num=(num&(1<<n)-1)<<move;	
	int mask=(1<<b+1)-1;		//mask for val(i)
	mask=mask>>move;		//to get the required number of bits
	mask=mask<<move;		//back to position
	val=(~mask) & val;		//to make the bits to be replace 0 in val(i)
	return(val | num);		//to replace nbits from position in num
}
