/***************************************************************************************
NAME		: Karthikeyan.V
DATE		: 8.08.2021
DESCRIPTION	: To take 8 consecutive bytes in memory. Provide a menu to manipulate or 
		  display the value of variable of type t (input) & indexed at i (i/p)
OUTPUT		:
./a.out 

MENU:
1.ADD ELEMENT
2.REMOVE ELEMENT
3.DISPLAY ELEMENT
4.EXIT FROM THE PROGRAM
CHOICE-->1

ENTER THE TYPE YOU HAVE TO INSERT: 
1.INT
2.CHAR
3.SHORT
4.FLOAT
5.DOUBLE
CHOICE-->1

ENTER THE INTEGER :5

MENU:
1.ADD ELEMENT
2.REMOVE ELEMENT
3.DISPLAY ELEMENT
4.EXIT FROM THE PROGRAM
CHOICE-->1

ENTER THE TYPE YOU HAVE TO INSERT: 
1.INT
2.CHAR
3.SHORT
4.FLOAT
5.DOUBLE
CHOICE-->4

THE MEMORY IS OCCUPIED
MENU:
1.ADD ELEMENT
2.REMOVE ELEMENT
3.DISPLAY ELEMENT
4.EXIT FROM THE PROGRAM
CHOICE-->1

ENTER THE TYPE YOU HAVE TO INSERT: 
1.INT
2.CHAR
3.SHORT
4.FLOAT
5.DOUBLE
CHOICE-->2

ENTER A CHARACTER : a

MENU:
1.ADD ELEMENT
2.REMOVE ELEMENT
3.DISPLAY ELEMENT
4.EXIT FROM THE PROGRAM
CHOICE-->1

ENTER THE TYPE YOU HAVE TO INSERT: 
1.INT
2.CHAR
3.SHORT
4.FLOAT
5.DOUBLE
CHOICE-->2

ENTER A CHARACTER : f

MENU:
1.ADD ELEMENT
2.REMOVE ELEMENT
3.DISPLAY ELEMENT
4.EXIT FROM THE PROGRAM
CHOICE-->2
0	-->	a
1	-->	f
2	-->	5

ENTER THE INDEX VALUE TO BE DELETED: 0

MEMORY AT INDEX 0 SUCCESSFULLY DELETED

MENU:
1.ADD ELEMENT
2.REMOVE ELEMENT
3.DISPLAY ELEMENT
4.EXIT FROM THE PROGRAM
CHOICE-->3

---------------------------------------------
0	-->	f	(char)
1	-->	5	(int)
---------------------------------------------
MENU:
1.ADD ELEMENT
2.REMOVE ELEMENT
3.DISPLAY ELEMENT
4.EXIT FROM THE PROGRAM
CHOICE-->4

EXITING PROGRAM

***************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
int main()
{
	int index[5];
	int n1, n2;
	int char_flag = 0, int_flag = 0,float_flag = 0, short_flag = 0, double_flag = 0, int_index;
	void *ptr;
	ptr = malloc(2 * sizeof(int));
 	while(1)
 	{
 	printf("\nMENU:\n1.ADD ELEMENT\n2.REMOVE ELEMENT\n3.DISPLAY ELEMENT\n4.EXIT FROM THE PROGRAM\nCHOICE-->");
 	__fpurge(stdin);
	scanf("%d", &n1);
	switch(n1)
	{
		/*checking the flags and add new element*/
		case 1:
			printf("\nENTER THE TYPE YOU HAVE TO INSERT: ");
			printf("\n1.INT\n2.CHAR\n3.SHORT\n4.FLOAT\n5.DOUBLE\nCHOICE-->");
			__fpurge(stdin);
			scanf("%d", &n2);
			switch(n2)
			{
				case 1:
					if(int_flag == 0 && float_flag == 0 && double_flag == 0)
					{
						int_flag++;	
						printf("\nENTER THE INTEGER :");
						scanf("%d",(((int *)ptr)+1));						
					}
					else
						printf("\nTHE MEMORY IS OCCUPIED");
					break;
				case 2:
					if(char_flag < 2 && double_flag == 0)
					{
						printf("\nENTER A CHARACTER : ");
						__fpurge(stdin);
						scanf("%c",((char *)ptr)+char_flag);
						char_flag++;
					}
					else
						printf("\nTHE MEMORY IS OCCUPIED");
					break;
				case 3:
					if(short_flag == 0 && double_flag == 0)
					{
						printf("\nENTER THE SHORT: ");
						scanf("%hd",(((short *)ptr)+1));
						short_flag++;
					}
					else
						printf("\nTHE MEMORY IS OCCUPIED");
					break;
				case 4: 
					if(int_flag == 0 && float_flag == 0 && double_flag == 0)
					{
						
						printf("\nENTER THE FLOAT: ");
						scanf("%f",(((float *)ptr)+1));
						float_flag++;
					}
					else
						printf("\nTHE MEMORY IS OCCUPIED");
					break;
				case 5:
					if(char_flag == 0 && int_flag ==0 && float_flag == 0 && short_flag == 0 && double_flag==0)
					{
						
						printf("\nENTER THE DOUBLE");
						__fpurge(stdin);
						scanf("%lf",(((double *)ptr)));
						double_flag++;
					}
					else
						printf("\nTHE MEMORY IS OCCUPIED");
					break;
				default:
					printf("\nERROR : THE SELECTED OPTION IS NOT VALID\n");
					break;
				}
			break;
		case 2:
			/*display indices and remove element*/
			int_index = 0; 
			if(char_flag > 0)
			{
				printf("%d	-->	%c\n",int_index, *((char *)ptr));
				index[int_index++] = 1;
				if(char_flag > 1)
				{
				printf("%d	-->	%c\n",int_index, *(((char *)ptr)+1));
				index[int_index++] = 1;
				}
			}
			if(short_flag == 1)
			{
				printf("%d	-->	%hd\n",int_index, *(((short *)ptr)+1));
				index[int_index++] = 2;
			}
			if(int_flag == 1)
			{
				printf("%d	-->	%d\n",int_index, *(((int *)ptr)+1));
				index[int_index++] = 3;
			}
			if(float_flag == 1)
			{
				printf("%d	-->	%g\n",int_index, *(((float *)ptr)+1));
				index[int_index++] = 4;
			}
			if(double_flag == 1)
			{
				printf("%d	-->	%g\n",int_index, *((double *)ptr));
				index[int_index++] = 5;
			}
			
			if(char_flag == 0 && int_flag ==0 && float_flag == 0 && short_flag == 0 && double_flag==0)
				printf("\nNO SPACE IS OCCUPIED\n");
			else
			{
				printf("\nENTER THE INDEX VALUE TO BE DELETED: ");
				scanf(" %d",&int_index);
			
			switch(index[int_index])
			{
				case 1:
					if(char_flag > 0)
					{
						if(char_flag > 1 && int_index == 0)
						{
							*((char *)ptr)	= *(((char *)ptr) +1);
						}
						char_flag--;
						printf("\nMEMORY AT INDEX %d SUCCESSFULLY DELETED\n",int_index);
					}
					else
						printf("\nMEMORY ALREADY FREED\n");
					break;
				case 2:
					if(short_flag == 1)
					{
						short_flag--;
						printf("\nMEMORY AT INDEX %d SUCCESSFULLY DELETED\n",int_index);
					}
					else
						printf("\nMEMORY ALREADY FREED\n");
					break;
				case 3:
					if(int_flag == 1)
					{
						int_flag--;
						printf("\nMEMORY AT INDEX %d SUCCESSFULLY DELETED\n",int_index);
					}	
					else
						printf("\nMEMORY ALREADY FREED\n");
					break;
				case 4:
					if(float_flag == 1)
					{
						float_flag--;
						printf("\nMEMORY AT INDEX %d SUCCESSFULLY DELETED\n",int_index);
					}	
					else
						printf("\nMEMORY ALREADY FREED\n");
					break;
				case 5:
					if(double_flag == 1)
					{
						double_flag--;
						printf("\nMEMORY AT INDEX %d SUCCESSFULLY DELETED\n",int_index);
					}	
					else
						printf("\nMEMORY ALREADY FREED\n");
					break;
				default:
					printf("\nINVALID OPTION\n");
					break;		
			}
			}
			break;
		case 3:
			/*display elements*/
			int_index = 0; 
			printf("\n---------------------------------------------");
			if(char_flag == 0 && int_flag ==0 && float_flag == 0 && short_flag == 0 && double_flag==0)
				printf("\nNO SPACE IS OCCUPIED\n");
			else
			{
				if(char_flag > 0)
				{
					printf("\n%d	-->	%c	(char)",int_index++, *((char *)ptr));
					if(char_flag > 1)
					{
					printf("\n%d	-->	%c	(char)",int_index++, *(((char *)ptr)+1));
					}
				}
				if(short_flag == 1)
				{
					printf("\n%d	-->	%hd	(short)",int_index++, *(((short *)ptr)+1));
				}
				if(int_flag == 1)
				{
					printf("\n%d	-->	%d	(int)",int_index++, *(((int *)ptr)+1));
				}
				if(float_flag == 1)
				{
					printf("\n%d	-->  %g	(float)",int_index++, *(((float *)ptr)+1));
				}
				if(double_flag == 1)
				{
					printf("\n%d	-->  %g	(double)\n",int_index++, *((double *)ptr));
				}
			}
			printf("\n---------------------------------------------");
			break;
		case 4:
			/*free pointer and exit*/
			free(ptr);
			printf("\nEXITING PROGRAM\n");
			exit(1);
			break;
		case 5:
			printf("\nINVALID OPTION\n");
			break;		
			
		}
	}

	return 0;
}
