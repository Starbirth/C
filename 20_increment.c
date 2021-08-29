/*****************************************************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:25.06.2021
DESCRIPTION	:20.WAF for pre and post increment and passing int pointer as their parameter

OUTPUT		:./a.out
		ENTER THE NUMBER: 5
		CHOOSE THE OPERATION:
		1.PRE-INCREMENT
		2.POST_INCREMENT
		CHOICE: 1
		ret=6
		num=6
		DO YOU WANT TO CONTINUE(y/Y) : y
		ENTER THE NUMBER: 5
		CHOOSE THE OPERATION:
		1.PRE-INCREMENT
		2.POST_INCREMENT
		CHOICE: 2
		ret=5
		num=6
		DO YOU WANT TO CONTINUE(y/Y) : n
*****************************************************************************************************/

#include<stdio.h>
int pre_increment(int *num);
int post_increment(int *num);
int main()
{
	int num,ret,operation;
	char choice;
	do{
	printf("ENTER THE NUMBER: ");
	scanf("%d",&num);
	printf("CHOOSE THE OPERATION:\n1.PRE-INCREMENT\n2.POST_INCREMENT\nCHOICE: ");
	scanf("%d",&operation);
	switch(operation)
	{
	case 1:
		ret=pre_increment(&num);
		break;
	case 2:
		ret=post_increment(&num);
		break;
	default:
		printf("INVALID CHOICE OF OPERATION\n");
		goto link;
	}
	printf("ret=%d\n",ret);
	printf("num=%d\n",num);
	link:
	printf("DO YOU WANT TO CONTINUE(y/Y) : ");
	scanf(" %c",&choice);
	}while( choice == 'y' || choice == 'Y' );
	
}
int pre_increment(int *num)
{
	int i;
	for(i=0;i<32;i++)
	{	if(((*num>>i)&1) ==0 )
		{
			break;
		}	
	}	
	*num=*num ^ (1<<i+1)-1; 	//set the first bit from lsb that is '0' and make 0 all the left side bits
	return *num;
}
int post_increment(int *num)
{
	int i,ret;
	ret=*num;		//for returning the same number		
	for(i=0;i<32;i++)
	{
		if(((*num>>i)&1) ==0 )
		{
			break;
		}
	}
	*num=*num ^ (1<<i+1)-1; 		
	return ret;			//returning the value of num as it is
}
