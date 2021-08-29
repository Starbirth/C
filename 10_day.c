/***************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:03.06.2021
DESCRIPTION	:10. Write a program to find which day of the year
OUTPUT		:./a.out
		CHOOSE FIRST DAY:
		1.Sunday
		2.Monday
		3.Tuesday
		4.Wednesday
		5.Thurday
		6.Friday
		7.Saturday
		CHOOSE THE FIRST DAY OF THE YEAR: 5
		ENTER THE 'N'th TO BE FOUND :6
		THE 6th DAY OF THE YEAR = Tuesday
		DO YOU WANT TO CONTIUNE(y/Y): n

***************************************************************/

#include<stdio.h>
int main()
{	
	char choice='y';
	int first_day, Nth_day;
	while( choice=='y' || choice=='Y' )				//while choice is y or Y execute the operation	
	{
		int output;						
		printf("CHOOSE FIRST DAY:\n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thurday\n6.Friday\n7.Saturday\n");
		
		printf("CHOOSE THE FIRST DAY OF THE YEAR: ");
		scanf("%d",&first_day);
		
		if(first_day>0 && first_day<=7)			//check if the input of first day is invalid
		{
		
		printf("ENTER THE 'N'th TO BE FOUND :");
		scanf("%d", &Nth_day);
		
			if(Nth_day>0 && Nth_day<=365)			//Nth day should be within the limit of number of days in a year
			{		
			
			output=((Nth_day+first_day-1)%7);		//to get the counting start from sunday as "1"
			
			printf("THE %dth DAY OF THE YEAR = ",Nth_day);
			
			switch (output)
			{
				case 1:
					printf("Sunday");
					break;
				case 2:
					printf("Monday");
					break;
				case 3:
					printf("Tuesday");
					break;
				case 4:
					printf("Wednesday");
					break;
				case 5:
					printf("Thrusday");
					break;
				case 6:
					printf("Friday");
					break;
				case 0:
					printf("Saturday");		//the 7th series day %7 will be 0
					break;
				default:
					break;		
			}
			
			}
			
			else
			{	
				printf("Invalid Input, n value should be > 0 and <= 365");
			}
		}
		else
		{
		printf("Invalid input, first day should be > 0 and <= 7\n");
		}
		
	printf("\nDO YOU WANT TO CONTIUNE(y/Y): ");
	scanf(" %c",&choice);					//to get the proceeding choice from user
	}
	return 0;
}

