/**********************************************************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:2.07.2021
DESCRIPTION	:WAP implement the solution for tower of hanoi

OUTPUT		:./a.out
		Enter the number of disks N : 3

		Make the legal move from rod A to C
		Make the legal move from rod A to B
		Make the legal move from rod C to B
		Make the legal move from rod A to C
		Make the legal move from rod B to A
		Make the legal move from rod B to C
		Make the legal move from rod A to C

		DO YOU WANT TO CONTINUE (y/Y):n
	
************************************************************************************************/
#include <stdio.h>
#include<stdio_ext.h>
void towers(int, char, char, char);
int main()
{
    int num;
    char choice;
    do
    {
    __fpurge(stdin);
    printf("Enter the number of disks N : ");
    scanf("%d", &num);
    towers(num, 'A', 'C', 'B');		//from , to , buffer
    __fpurge(stdin);
    printf("\n\nDO YOU WANT TO CONTINUE (y/Y):");
    scanf(" %c",&choice);
    }
    while(choice=='y' || choice=='Y');
    return 0;
}
void towers(int num, char from_rod, char to_rod, char buffer)
{	
    if (num == 1)
    {
        printf("\nMake the legal move from rod %c to %c", from_rod, to_rod);
        return;
    }
    towers(num - 1, from_rod, buffer, to_rod);
    printf("\nMake the legal move from rod %c to %c", from_rod, to_rod);
    towers(num - 1, buffer, to_rod, from_rod);
}
