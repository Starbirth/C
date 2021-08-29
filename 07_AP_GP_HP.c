/**************************************************************************
NAME		: Karthikeyan.V
DATE		: 03.06.2021
DESCRIPTION	: To generate  AP, GP and HP values
OUTPUT		: ./a.out
		Enter First Number 'A': 5
		Enter Comman Difference / Ratio 'R': 2
		Enter Number of terms 'N': 5
		AP = 5 7 9 11 13 
		GP = 5 10 20 40 80 
		HP = 0.200000 0.142857 0.111111 0.090909 0.076923 
		Do you want to continue (y/Y) : n

***************************************************************************/

#include<stdio.h>

int main()
{
	int A, R, N, check=1;
	int ap, gp;
	float hp;
	char choice;
	for (int i=1;i<=10;i++) 		// TO SET THE LIMITS
    	     check=check*2;
    	     
	do
	{
		printf("Enter First Number : ");
		scanf("%d",&A);
		printf("Enter Comman Difference / Ratio : ");
		scanf("%d",&R);
		printf("Enter Number of terms : ");
		scanf("%d",&N);
		
		if ( (A < check && A >= 0) &&  (R < check && R >= 0) && (N < check && N >= 0) ) // CHECK A,R,N INPUT FOR RANGE
		{
			//ARITHMETIC PROGRESSION
			ap=A;
			printf("AP = ");
			for(int i=1;i<=N;i++)
			{
				printf("%d ",ap);
				ap=ap+R;	
			}
			
			printf("\n");
			
			//GEOMETRIC PROGRESSION
			gp=A;
			printf("GP = ");
			for(int i=1;i<=N;i++)
			{
				printf("%d ",gp);
				gp=gp*R;	
			}
			
			printf("\n");
			
			//HARMONIC PROGRESSION
			hp=1/(float)A;
			printf("HP = ");
			for(int i=1;i<=N;i++)
			{
				printf("%f ",hp);
				A=A+R;
				hp=1/(float)A;	
			}
			
			printf("\n");
		}
		else if ( A > check || R > check || N > check)	// PRINTS ERROR IF ANY OF THE INPUTS IS OUT OF RANGE OR NOT
    	            printf("Inputs out of range\n");
			
		else if ( A < 0 || R < 0 || N < 0)			// PRINTS ERROR IF ANY OF THE INPUTS IS < 0
    	            printf("Invalid inputs : Please enter only positive values\n");
    	            
    	        printf("Do you want to continue (y/Y) : ");
    	        scanf(" %c",&choice);
    	      
	}  while (choice == 'Y' || choice == 'y');  			// CHECK TO PROCEED THE EXECUTION OR NOT
	
	return 0;
}	
