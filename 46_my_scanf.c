/**********************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:27.07.2021
DESCRIPTION	:To implement scanf function

OUTPUT		:./a.out

ENTER A NUMBER: 2
YOU entered :2

ENTER A CHARACTER :c
YOU ENTERED : c

ENTER A STRING :hello
YOU ENTERED : hello

ENTER A FLOAT NUMBER :2.5
YOU ENTERED : 2.5

ENTER A DOUBLE :3.65
YOU ENTERED :3.65

DO YOU WANT TO CONTINUE(Y/y): n
************************************************/
#include<stdio.h>
#include<stdarg.h>
#include<stdio_ext.h>

int my_scanf(const char *, ...);
int main()
{
	char choice;
	do
	{
	int num;
	char c;
	char *str;
	float f;
	double d;
	
	printf("\nENTER A NUMBER: ");
	my_scanf("%d", &num);
	printf("YOU entered :%d\n",num);
	
	printf("\nENTER A CHARACTER :");
	my_scanf(" %c", &c);
	printf("YOU ENTERED : %c\n",c);
	
	printf("\nENTER A STRING :");
	my_scanf("%s",str);
	printf("YOU ENTERED : %s\n",str);
	
	printf("\nENTER A FLOAT NUMBER :");
	my_scanf("%f",&f);
	printf("YOU ENTERED : %g\n",f);
	
	printf("\nENTER A DOUBLE :");
	my_scanf("%lf",&d);
	printf("YOU ENTERED :%g\n",d);
	
	__fpurge(stdin);
	printf("\nDO YOU WANT TO CONTINUE(Y/y): ");
	scanf(" %c",&choice);
	} while(choice == 'y' || choice =='Y');
	
	return 0;
}
 
int my_scanf(const char *arg, ...)
{
	/*initialise va_list, and pointers*/
	va_list ap;
	char ch;
	int *num, count=0, i;
	char *c;
	char *str;
	float *f;
	double *d;
		
	va_start(ap, arg);
	while(*arg)
	{
		if(*arg == '%' )
		{
			arg++;
			switch(*arg)
			{
				case 'd':
					__fpurge(stdin);
					num = va_arg(ap, int *);
					fscanf(stdin,"%d",num);
					count++;
					arg++;
					break;
				case 'c':
					__fpurge(stdin);
					c = va_arg(ap, char *);
					*c = getchar();
					count++;
					arg++;
					break;
				case 's':;
					__fpurge(stdin);
					str = va_arg(ap, char *);
					fscanf(stdin,"%s",str);
					count++;
					arg++;
					break;
				case 'f':
					__fpurge(stdin);
					f = va_arg(ap, float *);
					fscanf(stdin,"%f",f);
					count++;
					arg++;
					break;
				case 'l':
					__fpurge(stdin);
					arg++;
					if(*arg == 'f')
					{
						d = va_arg(ap, double *);
						fscanf(stdin,"%lf",d);
						arg++;
					}
					else
						arg--;
					break;
					
			}
		} 
		else
		{
			arg++;
		}
	}
	va_end(ap);
	return count;
}

