/***************************************************************************************
NAME		: Karthikeyan.V
DATE		: 10.06.2021
DESCRIPTION	: Implement the bitwise functions
OUTPUT		:./a.out

-----------------------------------------------------------------------------------------------------------
SELECT BIT OPERATION FROM BELOW LIST						
1.get_nbits
2.replace_nbits
3.get_nbits_from_pos
4.replace_nbits_from_pos
5.toggle_bits_from_pos
6.print_bits
CHOICE OF OPERATION :2

--------REPLACE BITS--------
ENTER THE NUMBER(num) : 10
ENTER THE NUMBER OF BITS TO REPLACE FROM LSB OF INPUT NUMBER(n) :3
ENTER THE VALUE(val) FROM WHICH 3 BITS FROM LSB SHOULD BE TAKEN TO REPLACE ON 10 (val):12
The output of 2 operation is for num=10,n=3 and value=12 is: 12

THE GIVEN NUMBER = 10 IN BINARY     : 00000000000000000000000000000101
THE OUTPUT OF 2 OPERATION IN BINARY : 00000000000000000000000000000110
-----------------------------------------------------------------------------------------------------------
DO YOU WISH TO CONTINUE(y/Y):n

***************************************************************************************/
#include<stdio.h>
int get_nbits(int num,int n);
int replace_nbits(int num, int n, int val);
int get_nbits_from_pos(int num, int n, int pos);
int replace_nbits_from_pos(int num, int n, int pos, int val);
int toggle_bits_from_pos(int num, int n, int pos);
int print_bits(unsigned int num, int n);
int main()
{
	char choice;
	int operation,output=0;
	int num,n,pos,val;
	unsigned int unsigned_num;
	do
	{
	printf("\n-----------------------------------------------------------------------------------------------------------");
	printf("\nSELECT BIT OPERATION FROM BELOW LIST																\n1.get_nbits\n2.replace_nbits\n3.get_nbits_from_pos\n4.replace_nbits_from_pos\n5.toggle_bits_from_pos\n6.print_bits\nCHOICE OF OPERATION :");
	scanf("%d",&operation);			//get the choice of operation from user
	switch(operation)
		{
		case 1:
			printf("\n--------GET 'n' BITS--------\nENTER THE NUMBER(num) : ");
			scanf("%d",&num);
			printf("ENTER THE NUMBER OF BITS TO GET FROM LSB OF INPUT NUMBER(n) :");
			scanf("%d",&n);
			output=get_nbits(num,n);
			printf("The output of %d operation is for num=%d and n=%d values is: %d\n",operation,num,n,output);
			break;
		
		case 2:
			printf("\n--------REPLACE BITS--------\nENTER THE NUMBER(num) : ");
			scanf("%d",&num);
			printf("ENTER THE NUMBER OF BITS TO REPLACE FROM LSB OF INPUT NUMBER(n) :");
			scanf("%d",&n);
			printf("ENTER THE VALUE(val) FROM WHICH %d BITS FROM LSB SHOULD BE TAKEN TO REPLACE ON %d (val):",n,num);  
			scanf("%d",&val);
			output=replace_nbits(num,n,val);
			printf("The output of %d operation is for num=%d,n=%d and value=%d is: %d\n",operation,num,n,val,output);
			break;
			
		case 3:
			printf("\n--------GET_'N'BITS FROM POS--------\nENTER THE NUMBER(num) : ");
			scanf("%d",&num);
			printf("ENTER THE POSITION FROM WHICH BITS SHOULD BE TAKEN FROM INPUT NUMBER(pos) :");
			scanf("%d",&pos);
			printf("ENTER THE NO. OF BITS TAKEN FROM %dth BIT ON NUMBER=%d :(n)",pos,num);  
			scanf("%d",&n);
			output=get_nbits_from_pos(num,n,pos);
			printf("The output of %d operation for values num=%d,pos=%d and n=%d is: %d\n",operation,num,pos,n,output);
			break;
			
		case 4:
			printf("\n--------REPLACE'N' FROM POS--------\nENTER THE NUMBER(num) : ");
			scanf("%d",&num);
			printf("ENTER THE POSITION FROM WHICH BITS SHOULD BE REPLACE IN INPUT NUMBER(pos) :");
			scanf("%d",&pos);
			printf("ENTER THE NO. OF BITS FROM %dth BIT SHOULD BE REPLACE IN %d :(n)",pos,num);  
			scanf("%d",&n);
			printf("ENTER THE VALUE FROM WHICH %d BITS STARTING FROM LSB SHOULD BE REPLACE WITH NUM(val) :",n);
			scanf("%d",&val);
			
			output=replace_nbits_from_pos(num,n,pos,val);
			printf("The output of %d operation for values num=%d,pos=%d,n=%d and val=%d is: %d\n",operation,num,pos,n,val,output);
			break;
			
		case 5:
			printf("\n--------TOGGLE 'N' BITS FROM POSITION--------\nENTER THE NUMBER(num) : ");
			scanf("%d",&num);
			printf("ENTER THE POSITION FROM WHICH BITS SHOULD BE TOGGLED IN INPUT NUMBER(pos) :");
			scanf("%d",&pos);
			printf("ENTER THE NO. OF BITS FROM %dth BIT TO TOGGLED IN %d : (n)",pos,num);  
			scanf("%d",&n);
			output=toggle_bits_from_pos(num,n, pos);
			printf("The output of %d operation for values num=%d,pos=%d,n=%d is: %d\n",operation,num,pos,n,output);
			break;	
				
		case 6:
			printf("\n-------PRINT BITS--------\nENTER THE NUMBER(num) : ");
			scanf("%d",&unsigned_num);
			printf("ENTER THE NUMBER OF BITS FORM LSB OF INPUT NUMBER TO BE PRINTED(n):");
			scanf("%d",&n);
			if(n>32)
				n=32;
			print_bits(unsigned_num,n);
			goto link;				//link to avoid printing bits value of garbage since this operation's output is inside the function
		
		default:
			printf("INVALID CHOICE\n");
			goto link;				//link to avoid printing bits value of garbage
		}
		printf("\nTHE GIVEN NUMBER = %d IN BINARY     : ",num);		
		for(int i=31;i>=0;i--)				//print the given number in binary form
		{
		printf("%d",(num>>i)&01);
		}
		printf("\nTHE OUTPUT OF %d OPERATION IN BINARY : ",operation);	
		for(int i=31;i>=0;i--)				//print the output in binary form
		{
		printf("%d",(output>>i)&01);
		}
		printf("\n-----------------------------------------------------------------------------------------------------------");
		
		link:
		printf("\nDO YOU WISH TO CONTINUE(y/Y):");
		scanf(" %c",&choice);
		printf("\n");
	}	
	while(choice=='y' || choice=='Y');
}
int get_nbits(int num, int n)
{
	return(num&(1<<n)-1);				//move 1 to the required bit from num and perform '&' operation
}
int replace_nbits(int num,int n,int val)		//consider num=10,n=3,n=12
{
	int mask=((1<<n)-1);				//move 1 to the nth position and -1 to get the mask,mask=0000 0111
	val=val & mask;				//to the n bits from lsb of value val=0000 0100
	num=num & (~mask);				//to make the last n bits of num equal to 0 , num=0000 1000
	return(num | val);				//replace last n bits of num with last n bits of val, 0000 1000 & 0000 0100
}
int get_nbits_from_pos(int num, int n, int pos)	//consider num=12,0000 1100, pos=4, n=3,
{
	int mask=((1<<n)-1);				//move 1 to the nth position and -1 to get the mask for n bits,mask=0000 0111
	num=num>>(pos-n+1);				//right shift the num (pos-n+1=2),so the required are at starting from 0th position			
	return(num & mask);				//& operation of num with mask
	
}
int replace_nbits_from_pos(int num, int n, int pos, int val)		//consider num=20,pos=4,n=3,val=12
{
	int move=pos-n+1;		//calculate the no of shift 
	val=(val&(1<<n)-1)<<move;	//0000 1100 & 0000 0111 , that is <<move times 0000 0100
	int mask=(1<<pos+1)-1;		//mask for num
	mask=mask>>move;		//to get the required number of bits
	mask=mask<<move;		//back to position
	num=(~mask) & num;		//to make the bits to be replace 0 in num
	return(val | num);		//to replace nbits from position in num
}
int toggle_bits_from_pos(int num, int n, int pos)
{
	
	int move=pos-n+1;			//no of shift
	int mask=((1<<pos+1)-1)>>move;	//mask of 1's' from pos >> to delete the unwanted bits 
	mask=mask<<move;			//back to position		
	return(num^mask);			//XOR operation of num wiht mask
}
int print_bits(unsigned int num, int n)
{	
	printf("%d in BINARY FORM WITH %d BITS : ",num,n);	
	for(int i=n-1;i>=0;i--)			//print num with n bits
	{
		printf("%d",(num>>i)&01);
	}
	printf("\n");
}





