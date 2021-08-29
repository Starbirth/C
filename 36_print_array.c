/*****************************************************************************************************************************
DOCUMENTATION:
NAME		:V.KARTHIEKEYAN
DATE		:27.06.2021
DESCRIPTION	:Read n & n floats in a float array ’store’. Print the values in sorted order 
		without modifying or copying ’store’

OUTPUT		:./a.out
		ENTER THE COUNT OF FLOAT ELEMENTS NEED TO STORE: 5
		[0]=10.0
		[1]=1.2
		[2]=3.2
		[3]=8.2
		[4]=-1.4
		AFTER SORTING: -1.4 1.2 3.2 8.2 10 
		AFTER SORTING THE ORIGINAL SEQUENCE :10 1.2 3.2 8.2 -1.4 
		DO YOU WANT TO CONTINUE(y/Y) :n

*****************************************************************************************************************************/

#include<stdio.h>
int sort_array(float arr[],int n)
{
	float small=arr[0];
	float big=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]<small)
			small=arr[i];
		if(arr[i]>big)
			big=arr[i];
	}
	float print;
	for(int i=0;i<n;i++)
	{
	print=big;
	for(int j=0;j<n;j++)
	{
		if(i==0) 
			print=small;
		else if(i==n-1)
			 print=big;
		else if(arr[j]>small && arr[j]<print)		//to pick the next small character to small
			print=arr[j];
	}
		printf("%g ",print);
		small=print;
	}
	return 0;
}
int main()
{
	char choice;
	int n;
	do
	{
	printf("ENTER THE COUNT OF FLOAT ELEMENTS NEED TO STORE: ");
	scanf("%d",&n);
	float array[n];

	for(int i=0;i<n;i++)
	{
		printf("[%d]=",i);
		scanf("%f",&array[i]);
	}
	printf("AFTER SORTING: ");
	
	sort_array(array,n);				//passing array and size 
	
	printf("\nAFTER SORTING THE ORIGINAL SEQUENCE :");

	for(int i=0;i<n;i++)
	{
		printf("%g ",array[i]);
	}
	printf("\nDO YOU WANT TO CONTINUE(y/Y) :");
	scanf(" %c",&choice);
	}while(choice='y' && choice=='Y');
}









