/***************************************************************************************
NAME		: Karthikeyan.V
DATE		: 30.07.2021
DESCRIPTION	: To find the average of n numbers by taking input in 3 different ways.
OUTPUT		:

./a.out

SELECT THE METHOD TO CALCULATE AVERAGE:
SCAN FROM KEYBOARD..PROCEED WITH PROVIDED COMMAND LIND ARGUMENTS
3.PROCEDD WITH ENVIRONMENT VARIABLE ARGUMENTS
ENTER YOU CHOICE: 3
THE NUMBERS ARE: 1 2 3 4
THE AVERAGE OF ENTERED NUMBERS :2.5

 ./a.out 2 3

SELECT THE METHOD TO CALCULATE AVERAGE:
1.SCAN FROM KEYBOARD.
2.PROCEED WITH PROVIDED COMMAND LIND ARGUMENTS
3.PROCEDD WITH ENVIRONMENT VARIABLE ARGUMENTS
ENTER YOU CHOICE: 2
THE AVERAGE OF ENTERED NUMBERS :2.5

./a.out 2 3

SELECT THE METHOD TO CALCULATE AVERAGE:
1.SCAN FROM KEYBOARD.
2.PROCEED WITH PROVIDED COMMAND LIND ARGUMENTS
3.PROCEDD WITH ENVIRONMENT VARIABLE ARGUMENTS
ENTER YOU CHOICE: 1
ENTER THE TOTAL NUMBER OF INTEGERS: 6
ENTER THE 6 ELEMENTS
1 2 36 5 8 7
THE AVERAGE OF ENTERED NUMBERS : 9.83333

**************************************************************************************/
#include<stdio.h>
#include<stdarg.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
int my_atoi(char *);
char *my_strtok(char *, char *);
int is_digit(char );


int main(int argc,char **argv, char **envp)
{
	int operation, element, count = 0, k;
	float sum = 0;
	char choice, *element_string, *tok;
	
		printf("\nSELECT THE METHOD TO CALCULATE AVERAGE:\n1.SCAN FROM KEYBOARD.\n2.PROCEED WITH PROVIDED COMMAND LIND ARGUMENTS\n3.PROCEDD WITH ENVIRONMENT VARIABLE ARGUMENTS\nENTER YOU CHOICE: ");
		scanf(" %d", &operation);
		switch(operation)
		{
			case 1:
				
				printf("ENTER THE TOTAL NUMBER OF INTEGERS: ");
				scanf("%d", &count);
				printf("ENTER THE %d ELEMENTS\n", count);
				for( k = 0; k < count; k++)
				{
					scanf("%d",&element);
					sum = sum + element;
				}	
				printf("THE AVERAGE OF ENTERED NUMBERS : %g\n",sum/count);
				break;
			case 2:
				if(argc < 2)
				{
					printf("THE ENTERED ARGUMENTS ARE TOO LESS FOR OPERATION\n");	
				}
				else
				{
					for( k = 1; k < argc; k++)
					{
						sum = sum + (element = my_atoi(argv[k]));
					}
					printf("THE AVERAGE OF ENTERED NUMBERS :%g\n",sum/(argc-1)); 
				}
				break;
			case 3:;				
				char *arr;
				arr= getenv("arr"); 
				tok=" ";
				printf("THE NUMBERS ARE: %s\n",arr);	
				element_string= my_strtok(arr, tok);
				if(element_string!=NULL)
				{
					element = my_atoi(element_string);
				while(element_string != NULL)
				{	
					if(element_string!=NULL)
					{
						count++;
						sum = sum + (my_atoi(element_string));
					}
					element_string=my_strtok(NULL, tok);
					
					
				}
				printf("THE AVERAGE OF ENTERED NUMBERS :%g\n",sum/count); 
				}
				else
					printf("\nerror:environmental variable is empty\n");
				break;
			default:
				printf("\nENTER A VALID CHOICE OF OPERATION\n");
				break;				
		}
}

int my_atoi(char *str)
{
	int num=0, flag=0;
	for(int i=0;str[i]!='\0';i++)
	{
		
		if(is_digit(str[i]))
		{
			num=(num*10)+(str[i]-'0');		//convert char to int 
		}
		else if(str[i]=='-' || str[i]=='+')
		{	
			if(i==0 && str[i]=='-')
				flag=1;
			if(i>0)				//if second time '+' or '-' occurs break
				break;	
		}
		else
			break;
	}
	if(flag==1)	
		return num*-1;
	return num;	
}
char *my_strtok(char *str1, char *str2)
{
    //Declaring variables

    int j;       
    static int i;
    static char *temp;
    int length = i;

    if (str1 != NULL)
    {
        temp = str1;
    }
    for(i; temp[i] != '\0'; i++)
    {
        j = 0;
        for(j;(str2[j] != '\0'); j++)
        {
            //Checking for delimiter

            if (str2[j] == temp[i])
            {
                temp[i] = '\0';
                i++;
                if (temp[length] != '\0')
                {
                    return (&temp[length]);
                }
                else
                {
                    length = i;
                    i--;
                    break;
                }
            }
	}
    }
    if (temp[length] == '\0')
    {
        i = 0;
        return NULL;
    }
    else
    {
        return (&temp[length]);
    }
}

int is_digit(char ch)
{
	return ch>='0' && ch<='9'?1:0;	//for digit check
}
