/***************************************************************************************
DOCUMENTATION:

NAME		: V.KARTHIEKEYAN
DATE		: 11.08.2021
DESCRIPTION	: WAP to demote the type of given float number to integer using bitwise
		  operators and bitfields.

OUTPUT		:./a.out

ENTER A FLOAT VALUE: 12.34
DEMOTED VALUE: 12.000000
DO YOU WANT TO CONTINUE(y/Y) :y

ENTER A FLOAT VALUE: -12.34
DEMOTED VALUE: -12.000000
DO YOU WANT TO CONTINUE(y/Y) :n

****************************************************************************************/


#include<stdio.h>
/* union where float data is shared with bitfields*/
union Float
{
	float f;
	struct
	{
		unsigned int mantissa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	};
}var;

void demote_to_int(union Float *);

int main()
{
	char choice;
	do
	{
		printf("\nENTER A FLOAT VALUE: ");
		scanf("%f",&var.f);
		printf("exponent=%u\n",var.exponent);
		demote_to_int(&var);
		
		printf("DEMOTED VALUE: %f\n",var.f);
		printf("DO YOU WANT TO CONTINUE(y/Y) :");
		scanf(" %c", &choice);
	} while (choice == 'y' || choice == 'Y');
	return 0;
}

/*function to demote the value of float to int*/
void demote_to_int(union Float *var)
{
	//standard bias number = 127
	int exponent = var -> exponent - 127 ;
	if( exponent  <= 0 && var -> f > -1.0f && var -> f < 1.0f)
	{
		var -> f = 0;
	}
	else
	{	
		int mantissa = (var -> mantissa) >> (23 - exponent);
		exponent = 1 << exponent;
		if (var -> sign == 1)
			var -> f = -(exponent | mantissa);
		else
			var -> f = exponent | mantissa;
	}
}


