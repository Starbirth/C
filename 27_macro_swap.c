/****************************************************************************************************
DOCUMENTATION:

Name              : V.Karthikeyan
Date              : 01.08.2021
Description       : To define a macro swap (t, x, y) that interchanges two arguments of type t
Input             : ./a.out

1.Int
2.Char
3.Short
4.Float
5.Double
6.String
ENTER YOUR CHOICE :1

ENTER NUM1: 2
ENTER NUM2: 3

AFTER SWAPPPING:
num1 = 3
num2 = 2
DO YOU WANT TO CONTINUE(y/Y): y

1.Int
2.Char
3.Short
4.Float
5.Double
6.String
ENTER YOUR CHOICE :2

ENTER CHARACTER1: c
ENTER CHARACTER2: g

AFTER SWAPPPING:
CHARACTER1 = g
CHARACTER2 = c
DO YOU WANT TO CONTINUE(y/Y): y

1.Int
2.Char
3.Short
4.Float
5.Double
6.String
ENTER YOUR CHOICE :3

ENTER SHORT NUM1: 2
ENTER SHORT NUM2: 5

AFTER SWAPPING:
Short num1=5
Short num2 = 2
DO YOU WANT TO CONTINUE(y/Y): y

1.Int
2.Char
3.Short
4.Float
5.Double
6.String
ENTER YOUR CHOICE :4

ENTER FLOAT NUM1: 2.3
ENTER FLOAT NUM2: 5.6

AFTER SWAPPING:
FLOAT num1=5.600000
FLOAT num2 = 2.300000
DO YOU WANT TO CONTINUE(y/Y): y

1.Int
2.Char
3.Short
4.Float
5.Double
6.String
ENTER YOUR CHOICE :5   

ENTER DOUBLE NUM1: 2.36
ENTER DOUBLE NUM2: 2.54
￼￼
￼
￼
￼
￼
￼
￼

AFTER SWAPPING:
DOUBLE num1=2.540000
DOUBLE num2 = 2.360000
DO YOU WANT TO CONTINUE(y/Y): Y

1.Int
2.Char
3.Short
4.Float
5.Double
6.String
ENTER YOUR CHOICE :6

ENTER STRING1 : hi
ENTER STRING2 : hello

After Swapping: string1:
hello
string2:hi
DO YOU WANT TO CONTINUE(y/Y): n
*****************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>

//To swap the two variables of type t
#define MacroSwap(t, x, y)		\
{					\
	t temp;			\
	temp = x;			\
	x=y;				\
	y=temp;			\
}
	
int main()
{
	int num1, num2, operation;
	short s1, s2;
	float f1, f2;
	double d1, d2;
	char c1, c2, choice;
	char *str1, *str2;
	do
	{
		printf("\n1.Int\n2.Char\n3.Short\n4.Float\n5.Double\n6.String\nENTER YOUR CHOICE :");
		scanf("%d",&operation);
		switch(operation)
		{
			case 1:
				printf("\nENTER NUM1: ");
				scanf("%d",&num1);
				printf("ENTER NUM2: ");
				scanf("%d",&num2);
				MacroSwap(int, num1, num2);
				printf("\nAFTER SWAPPPING:\nnum1 = %d\nnum2 = %d\n",num1,num2);
				break;
			case 2:
				printf("\nENTER CHARACTER1: ");
				scanf(" %c",&c1);
				printf("ENTER CHARACTER2: ");
				scanf(" %c",&c2);
				MacroSwap(char, c1, c2);
				printf("\nAFTER SWAPPPING:\nCHARACTER1 = %c\nCHARACTER2 = %c\n",c1,c2);
				break;
			case 3:
				printf("\nENTER SHORT NUM1: ");
				scanf("%hd",&s1);
				printf("ENTER SHORT NUM2: ");
				scanf("%hd",&s2);
				MacroSwap(short, s1, s2);
				printf("\nAFTER SWAPPING:\nShort num1=%hd\nShort num2 = %hd\n",s1,s2);
				break;
			case 4:
				printf("\nENTER FLOAT NUM1: ");
				scanf("%f",&f1);
				printf("ENTER FLOAT NUM2: ");
				scanf("%f",&f2);
				MacroSwap(float, f1, f2);
				printf("\nAFTER SWAPPING:\nFLOAT num1=%f\nFLOAT num2 = %f\n",f1,f2);
				break;
			case 5:
				printf("\nENTER DOUBLE NUM1: ");
				scanf("%lf",&d1);
				printf("ENTER DOUBLE NUM2: ");
				scanf("%lf",&d2);
				MacroSwap(double, d1, d2);
				printf("\nAFTER SWAPPING:\nDOUBLE num1=%lf\nDOUBLE num2 = %lf\n",d1,d2);
				break;
			case 6:
				str1 = (char *)malloc(1024);
				str2 = (char *)malloc(1024);
				printf("\nENTER STRING1 : ");
				scanf("%s",str1);
				printf("ENTER STRING2 : ");
				scanf("%s",str2);
				MacroSwap(char*, str1, str2);
				printf("\nAfter Swapping:\nstring1:%s\nstring2:%s\n",str1,str2);
				free(str1);
				free(str2);
				break;
			default:
				printf("\nERROR: ENTER VALID CHOICE OF OPERATION\n");
				break;
				}
	
	printf("DO YOU WANT TO CONTINUE(y/Y): ");
	scanf(" %c",&choice);
	}while (choice =='y' || choice == 'Y');
	return 0;
}
