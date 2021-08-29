/*****************************************************************
DOCUMENTATION:
NAME		:V.KARTHIEKEYAN
DATE		:22.07.2021
DESCRIPTION	:WAP to implement fragments using Array of Pointers (First Static Second Dynamic).

OUTPUT		:./a.out

ENTER THE NUMBER OF ARRAY YOU WANT TO GIVE AS INPUT: 3
ENTER NO. OF COLUMNS IN ROW[0]: 3
ENTER NO. OF COLUMNS IN ROW[1]: 3
ENTER NO. OF COLUMNS IN ROW[2]: 3
ENTER 3 VALUES OF ROW[0]: 2 3 5
ENTER 3 VALUES OF ROW[1]: 2 4 7
ENTER 3 VALUES OF ROW[2]: 2 1 0
BEFORE SORTING OUTPUT IS: 
2 3 5 3.33333
2 4 7 4.33333
2 1 0 1

AFTER SORTING OUTPUT IS: 
2 1 0 1 
2 3 5 3.33333 
2 4 7 4.33333 

DO YOU WANT TO CONTINUE (y/Y): n
*******************************************************************/
#include<stdio.h>
#include<stdlib.h>
int main()
{	
	int array_count, i, j;
	float sum;
	char choice;
	do
	{
		printf("\nENTER THE NUMBER OF ARRAY YOU WANT TO GIVE AS INPUT: ");
		scanf("%d",&array_count);
		float *arr[array_count];
		int array_of_col_count[array_count];
		int output_pos[array_count];
		
		/*dynamically allocating memory and fill the output_pos array in order*/
		for(i=0; i<array_count; i++)
		{
			printf("ENTER NO. OF COLUMNS IN ROW[%d]: ",i);
			scanf("%d",&array_of_col_count[i]);
			arr[i] = malloc( sizeof(float) * array_of_col_count[i]+1);
			output_pos[i] = i;
		}
		
		/*inputing the array elements*/
		for(i=0; i<array_count; i++)
		{
			printf("ENTER %d VALUES OF ROW[%d]: ",array_of_col_count[i], i);
			for(int j=0; j<array_of_col_count[i]; j++)
				scanf(" %f",&arr[i][j]);
		}
		
		/*printing the array before sorting*/
		printf("BEFORE SORTING OUTPUT IS: \n");
		for(i=0; i<array_count; i++)
		{	
			sum = 0;
			for(j=0; j<array_of_col_count[i]; j++)
			{
				printf("%g ",arr[i][j]);
				sum = sum + arr[i][j];
			} 
			printf("%g\n", arr[i][j]=sum/j );
		}
		
		/*checking the mean and sorting with the mean values of 'n' arrays*/
		for( i=0; i < array_count-1; i++)
		{
			for( j=0; j < array_count-1-i; j++)
			{
			
				if(arr[output_pos[j]][array_of_col_count[output_pos[j]]] > arr[output_pos[j+1]][array_of_col_count[output_pos[j+1]]])
					output_pos[j] = output_pos[j] + output_pos[j+1] - (output_pos[j+1] = output_pos[j]); 
			}	
				
		}
		
		/*printing the array after sorting*/
		printf("\nAFTER SORTING OUTPUT IS: \n");
		for(i=0; i<array_count; i++,printf("\n"))
		{	
			for(j=0; j<array_of_col_count[output_pos[i]]+1; j++)
				printf("%g ",arr[output_pos[i]][j]);
		}
	
	printf("\nDO YOU WANT TO CONTINUE(y/Y) : ");
	scanf(" %c",&choice);
	}while( choice == 'y' || choice =='Y' );
	return 0;
}
