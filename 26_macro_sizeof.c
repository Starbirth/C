/*****************************************************************************************************
DOCUMENTATION:

Name              : V.Karthikeyan
Date              : 01.08.2021
Description       : To define a macro SIZEOF(x), where x is a variable, without using sizeof operator
Input             : ./a.out./a.out

size of Int			:4 
size of Short int		:2 
size of Char			:1 
size of Float			:4 
size of Double			:8 
size of Long Double		:16 
size of Lont_long_int		:8 
size of Signed_char		:1 
size of Unsigned_short_int	:2 
size of Unsigned_int		:4
******************************************************************************************************/
#include<stdio.h>

//to calculate the size of data_type
#define SIZE_OF(x)	 (char *)(&x+1) - (char *)&x	
int main()
{
	int Integer;
	short int Short_int;
	char Char;
	float Float;
	double Double;
	long double Long_double;
	long long int Long_long_int;
	signed char Signed_char;
	unsigned short int Unsigned_short_int;
	unsigned int Unsigned_int;
	long int Long_int;
	
	printf("\nsize of Int\t\t\t:%lu ",SIZE_OF(Integer));
	printf("\nsize of Short int\t\t:%lu ",SIZE_OF(Short_int));
	printf("\nsize of Char\t\t\t:%lu ",SIZE_OF(Char));
	printf("\nsize of Float\t\t\t:%lu ",SIZE_OF(Float));
	printf("\nsize of Double\t\t\t:%lu ",SIZE_OF(Double));
	printf("\nsize of Long Double\t\t:%lu ",SIZE_OF(Long_double));
	printf("\nsize of Lont_long_int\t\t:%lu ",SIZE_OF(Long_long_int));
	printf("\nsize of Signed_char\t\t:%lu ",SIZE_OF(Signed_char));
	printf("\nsize of Unsigned_short_int\t:%lu ",SIZE_OF(Unsigned_short_int));
	printf("\nsize of Unsigned_int\t\t:%lu\n",SIZE_OF(Unsigned_int));
	
	return 0;	
}
