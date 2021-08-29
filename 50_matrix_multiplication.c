/********************************************************************************
DOCUMENTATION:
NAME		:V.KARTHIEKEYAN
DATE		:20.07.2021
DESCRIPTION	:WAP to find the product of given matrix.

OUTPUT		: ./a.out
ENTER THE INPUT ARRAY DETAILS:
ENTER THE NO. OF ROWS: 1
ENTER THE NO. OF COLUMNS: 3
ENTER THE INPUTS TO ARRAY:
3 2 5
INPUT ARRAY:
3 2 5 

TRANSPOSE ARRAY
3 
2 
5 

OUTPUT ARRAY
9 

DO YOU WANT TO CONTINUE(Y/y): y
ENTER THE INPUT ARRAY DETAILS:
ENTER THE NO. OF ROWS: 3
ENTER THE NO. OF COLUMNS: 3
ENTER THE INPUTS TO ARRAY:
1 2 3 
5 6 8
2 4 7
INPUT ARRAY:
1 2 3 
5 6 8 
2 4 7 

TRANSPOSE ARRAY
1 5 2 
2 6 4 
3 8 7 

OUTPUT ARRAY
34 97 75 
34 97 75 
34 97 75 

DO YOU WANT TO CONTINUE(Y/y): n
******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
void print_array(int row, int col, int **arr);
int main()
{
	char choice;
	int **A, **AT, **OUTPUT_ARRAY, A_row, A_col, AT_row, AT_col;
	do
	{
	A = NULL;
	AT = NULL;
	OUTPUT_ARRAY = NULL;
	printf("ENTER THE INPUT ARRAY DETAILS:\nENTER THE NO. OF ROWS: ");
	scanf("%d", &A_row);
	printf("ENTER THE NO. OF COLUMNS: ");
	scanf("%d", &A_col);
	if(A_row < 0 || A_col < 0)
	{
		printf("ENTER ONLY POSITIVE VALUES");
	}
	else
	{
		AT_row = A_col;
		AT_col = A_row;
		A = (int **)malloc( sizeof(int *) * A_row );
		AT = (int **)malloc( sizeof(int *) * AT_row );
		OUTPUT_ARRAY = malloc(sizeof(int *) * A_row);
		for(int i=0; i<A_col; i++)
		{
			A[i] =(int *) malloc( sizeof(int) * A_col );
		}
		for(int i=0; i<AT_row;i++)
		{
			AT[i] =(int *) malloc( sizeof(int) * AT_col );
			OUTPUT_ARRAY[i] = (int *) malloc(sizeof(int) * AT_col);	
		}
	
		
		printf("ENTER THE INPUTS TO ARRAY:\n");
		for(int i=0; i < A_row; i++)
		{
			for(int j=0; j < A_col; j++)
			{
				scanf("%d", &A[i][j]);
				AT[j][i]=A[i][j];		//assigning the AT array while inputing the A array
		
			}
		}
		
		int temp, i, j;
		
		for(i=0; i<A_row; i++)
		{
			for( j=0; j<A_row; j++)
			{
				//product of the row of A to col of AT and store in the output array
				temp=0;
				for(int k=0; k < A_col ; k++)
					temp= temp + ( A[j][k] * AT[k][k] );
				OUTPUT_ARRAY[i][j] = temp;
			}
			
		}
		printf("INPUT ARRAY:\n");
		print_array(A_row, A_col, A);
		printf("TRANSPOSE ARRAY\n");
		print_array(AT_row, AT_col, AT);
		printf("OUTPUT ARRAY\n");
		print_array(A_row, AT_col, OUTPUT_ARRAY);
		free(A);
		free(AT);
		free(OUTPUT_ARRAY);
		A=NULL;
		AT=NULL;
		OUTPUT_ARRAY=NULL;
	}
		printf("DO YOU WANT TO CONTINUE(Y/y): ");
		scanf(" %c",&choice);
		} while ( choice == 'y' || choice == 'Y' );
	
	return 0;
}

//to print the 2D array  
void print_array(int row, int col, int **arr )
{
	for(int i=0; i<row; i++, printf("\n"))
		for(int j=0; j<col; j++)
			printf("%d ",arr[i][j]);
	printf("\n");
}

