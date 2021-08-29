/****************************************************
DOCUMENTATION:
NAME		: V. KARTHIEKEYAN
DATE		: 18.07.2021
DESCRIPTION	: WAP to generate a n*n magic square (n is odd +ve no.)
OUTPUT		:./a.out

ENTER THE DIMENSIONS OF A SQUARE MATRIX: 3
 8  1  6 
 3  5  7 
 4  9  2 


DO YOU WANT TO CONTINUE(y/Y): y

ENTER THE DIMENSIONS OF A SQUARE MATRIX: 5
17 24  1  8 15 
23  5  7 14 16 
 4  6 13 20 22 
10 12 19 21  3 
11 18 25  2  9 


DO YOU WANT TO CONTINUE(y/Y): y

ENTER THE DIMENSIONS OF A SQUARE MATRIX: 2
ERROR: ENTER ONLY POSITIVE ODD NUMBER

DO YOU WANT TO CONTINUE(y/Y): n
*******************************************************/
#include<stdio.h>
#include<stdlib.h>
void Movement(int *, int *, int, int**);
void print_matrix(int n, int **arr);
int main()
{
	char choice;
	int n, row, col, **arr, value;
	arr=NULL;
	do
	{	
		printf("\nENTER THE DIMENSIONS OF A SQUARE MATRIX: ");
		scanf(" %d",&n);
		//error checking
		if(n < 0 || n%2 == 0 )
			printf("ERROR: ENTER ONLY POSITIVE ODD NUMBER\n");
		else
		{
			arr = (int **) calloc(n,sizeof(int *));
			for(int i = 0 ;i < n; i++)
				arr[i] = (int *) calloc(n, sizeof(int));
			
			row = 0;
			col = n/2;
			value = 1;
			while(value <= n*n)
			{
				arr[row][col] = value++;		//assign and increment to the position
				//printf("[%d][%d]=%d\n",row,col,arr[row][col]);
				Movement(&row, &col, n, arr);			
			}
		print_matrix(n, arr);		
		}
	printf("\nDO YOU WANT TO CONTINUE(y/Y): ");
	scanf(" %c",&choice);
	}while(choice=='y' || choice=='Y');	
	return 0;
}

/*printing the array function*/
void print_matrix(int n, int **arr )
{
	int n_square=n*n, space=0;
	while(n_square)
	{
		space++;
		n_square = n_square/10;
	}	
	for(int i=0; i<n; i++, printf("\n"))
		for(int j=0; j<n; j++)
			printf("%*d ",space, arr[i][j]);
	printf("\n");
}

/*position movement for one upward and one right movement(or) downward movement*/
void Movement(int *row,int *col, int n, int **arr)
{
	int r=*row, c=*col;
	
	if( r-1 < 0 )
		r = n-1;
	else
		--r;
	if( c+1 == n )
		c = 0;
	else
		++c;
	if ( arr[r][c] == 0 )
	{
		*row = r;
		*col = c;
	}
	else 
	{
		if( ++(*row) == n)
			*row=0;
	}
}





