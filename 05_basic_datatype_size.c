/******************************************************************************************************************
  
Name              : V.Karthikeyan
Date              : 02-06-2021
Description       : Program to print size of basic data types and also with their qualifiers using sizeof operator
Input             :./a.out
Output            :
Size of int 		 	 :4
Size of short int 		 :2
Size of char 		 	 :1
Size of float 		 	 :4
Size of double 		 :8
Size of long double 		 :16
Size of long long int 		 :8
Size of signed int 		 :4
Size of unsigned int 		 :4
Size of signed char 		 :1
Size of unsigned char 		 :1
Size of unsigned short int 	 :2
Size of unsigned long 		 :8
Size of long int		 :8

*******************************************************************************************************************/

#include <stdio.h>

int main()
{
    printf("Size of int 		 	 :%zu\n", sizeof(int));
    printf("Size of short int 		 :%zu\n", sizeof(short int));
    printf("Size of char 		 	 :%zu\n", sizeof(char));
    printf("Size of float 		 	 :%zu\n", sizeof(float));
    printf("Size of double 		 	 :%zu\n", sizeof(double));
    printf("Size of long double 		 :%zu\n", sizeof(long double));
    printf("Size of long long int 		 :%zu\n", sizeof(long long int));
    printf("Size of signed int 		 :%zu\n", sizeof(signed int));
    printf("Size of unsigned int 		 :%zu\n", sizeof(unsigned int));
    printf("Size of signed char 		 :%zu\n", sizeof(signed char));
    printf("Size of unsigned char 		 :%zu\n", sizeof(unsigned char));
    printf("Size of unsigned short int 	 :%zu\n", sizeof(unsigned short int));
    printf("Size of unsigned long 		 :%zu\n", sizeof(unsigned long));
    printf("Size of long int		 :%ld\n", sizeof(long int));
}
