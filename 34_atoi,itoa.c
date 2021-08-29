/*****************************************************************************************************************************
DOCUMENTATION:
NAME		:V.KARTHIEKEYAN
DATE		:8.07.2021
DESCRIPTION	:Implement getword, atoi, itoa functions

OUTPUT		:./a.out
		1.getword
		2.atoi
		3.itoa
		ENTER YOUR CHOICE:1 
		ENTER A WORD: Hello World
		YOU ENTERED Hello and length is 5
		
		DO YOU WANT TO CONTINUE(Y/y) :y
		1.getword
		2.atoi
		3.itoa
		ENTER YOUR CHOICE:2
		ENTER A NUMBERIC STRING: -12345
		STRING TO INTEGER IS -12345
		
		DO YOU WANT TO CONTINUE(Y/y) :y
		1.getword
		2.atoi
		3.itoa
		ENTER YOUR CHOICE:3
		ENTER A NUMBER: 1234
		INTEGER TO STRING IS 1234
		
		DO YOU WANT TO CONTINUE(Y/y) :n
*****************************************************************************************************************************/

#include<stdio.h>
#include<stdio_ext.h>
int get_word(char *);
int string_int(char *);
int is_digit(char);
int int_string(int, char *);
int main()
{
	char choice;
	do
	{
	int num,operation,string_length;
	char char_string[200];
		__fpurge(stdin);
		printf("1.getword\n2.atoi\n3.itoa\nENTER YOUR CHOICE:");
		scanf(" %d",&operation);
		switch(operation)
		{
			case 1:
				printf("ENTER A WORD: ");
				__fpurge(stdin);
				scanf("%[^\n]",char_string);
				string_length=get_word(char_string);
				printf("YOU ENTERED %s and length is %d",char_string,string_length);
				break;
			case 2:
				printf("ENTER A NUMBERIC STRING: ");
				__fpurge(stdin);
				scanf("%[^\n]",char_string);
				num=string_int(char_string);
				printf("STRING TO INTEGER IS %d",num);
				break;
			case 3:
				printf("ENTER A NUMBER: ");
				__fpurge(stdin);
				scanf(" %d",&num);
				string_length=int_string(num,char_string);
				printf("INTEGER TO STRING IS %s",char_string);
				break;
			default:
				printf("ENTER VALID CHOICE OF OPERATION\n");
				break;
		}
		__fpurge(stdin);
		printf("\n\nDO YOU WANT TO CONTINUE(Y/y) :");
		scanf(" %c",&choice);
	
	}while(choice=='y' || choice=='Y');
}
int get_word(char *str)
{
	int count=0;
	while(str[count] && str[count] != 32 && str[count] != '\t')		//cut the loop at ' ' or '\t'
		count++;		
	str[count]='\0';				//join a '\0' at the end of first word
	return count;
}
int string_int(char *str)
{
	int num=0, flag=0;
	for(int i=0;str[i]!='\0';i++)
	{
		
		if(is_digit(str[i]))
		{
			num=(num*10)+(str[i]-'0');		//convert char to int 
		}
		else if(str[i]=='-' || str[i]=='+')
		{	
			if(i==0 && str[i]=='-')
				flag=1;
			if(i>0)				//if second time '+' or '-' occurs break
				break;	
		}
		else
			break;
	}
	if(flag==1)	
		return num*-1;
	return num;	
}
int int_string(int num, char *str)
{
	int i=0,j,count=0,temp=num;
	if(num<0)
	{
		str[i++]='-';			//if negative str[0]='-' && increment the i
		num *= -1;
	}
	while(temp)				//how many digits are in the number
	{
		i++;
		temp=temp/10;
	}
	str[i]='\0';				//null at the end of 'i' characters
	for(j=i-1;num!=0;j--)			//for string i-1
	{
		str[j]=num%10+48;		//get the digit convert to char	
		num=num/10;			//reduce the last digit
	}
	return i;
}
int is_digit(char ch)
{
	return ch>='0' && ch<='9'?1:0;	//for digit check
}




