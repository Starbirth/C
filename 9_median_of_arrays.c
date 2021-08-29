/***************************************************************************************
NAME		: Karthikeyan.V
DATE		: 13.06.2021
DESCRIPTION	: Implement the bitwise functions
OUTPUT		:./a.out
		ENTER THE 'N' VALUE OF ARRAY 1: 5
		ENTER THE ELEMENTS ONE BY ONE OF ARRAY 1: 3
		5
		5
		8
		1
		AFTER SORTING :1 3 5 5 8 
		MEDIAN OF ARRAY1 is :5
		ENTER THE 'N' VALUE OF ARRAY 2: 8   
		ENTER THE ELEMENTS ONE BY ONE OF ARRAY 2: 3
		5
		8 
		2
		5 
		2
		4
		8
		AFTER SORTING :2 2 3 4 5 5 8 8 
		MEDIAN OF ARRAY2 is :4.5
		MEDIAN OF BOTH ARRAYS :4.75 
		DO YOU WISH TO CONTINUE(y/Y):n

***************************************************************************************/
#include<stdio.h>
int main()
{
	char choice;
	int index;
	do
	{
		float median[3];		 //to store median of each array
		int turn;			//loop for turn times and to use for indication of array
		for(turn=1;turn<=2;turn++)
		{
			printf("ENTER THE 'N' VALUE OF ARRAY %d: ",turn);
			scanf("%d",&index);
			if(index>1 && index<10)		//limit checking for no of array elements
			{
			int arr[index];
			printf("ENTER THE ELEMENTS ONE BY ONE OF ARRAY %d: ",turn);
			for(int i=0;i<index;i++)		//to scan the elements of array
			{
				scanf("%d",&arr[i]);
			}
			
			int temp;				//swap element

			for(int i=0;i<index-1;i++)		//bubble sort in ascending order
			{
				for(int j=0;j<index-1-i;j++)
				{
					if(arr[j]>arr[j+1])
					{
					 temp=arr[j];
					 arr[j]=arr[j+1];
					 arr[j+1]=temp;
					}
				}
			}
			
			printf("AFTER SORTING :");
	
			for(int i=0;i<index;i++)		//to print the elements after sorting
			{
				printf("%d ",arr[i]);
			}
			
			int n=index/2;
				if(index%2==0)			//if even no. of elements the average of middle two elements
					median[turn]=((float)(arr[n]+arr[--n]))/2;
				else	
					median[turn]=arr[n];	//the middle element in case of odd no. of elements
				printf("\nMEDIAN OF ARRAY%d is :%g\n",turn,median[turn]);
			}
			else
			{
				printf("Max array elements exceeded\n");
				goto wrong;			//no need to print the median so straight to choice of continuation
			}
		}
			
		printf("MEDIAN OF BOTH ARRAYS :%g \n",(median[1]+median[2])/2);
		
		wrong:
		printf("DO YOU WISH TO CONTINUE(y/Y):");
		scanf(" %c",&choice);
		printf("\n");
	}	
	while(choice=='y' || choice=='Y');
}


