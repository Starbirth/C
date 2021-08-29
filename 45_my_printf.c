/****************************************************
DOCUMENTATION:

NAME		:V.KARTHIEKEYAN
DATE		:27.07.2021
DESCRIPTION	:To implement printf function

OUTPUT		: ./a.out

ENTER NUMBER, CHAR, STRING :2,c,hello
2  c  hello 
ENTER FLOAT : 2.65
2.650000 
ENTER DOUBLE : 3.254
3.254000 
DO YOU WANT TO CONTINUE(Y/y): n

******************************************************/
#include<stdio.h>
#include<stdarg.h>

void my_printf(const char *, ...);
int my_itoa(int , char *str);
void my_floatToString(float, char*, int);
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
	my_printf("\nENTER NUMBER, CHAR, STRING :");
	scanf("%d%*c%c%*c%s", &num, &c, str);
	my_printf("%d %c %s",num, c, str);
	my_printf("\nENTER FLOAT : ");
	
	scanf("%f",&f);
	my_printf("%f ",f);
	
	my_printf("\nENTER DOUBLE : ");
	scanf("%lf",&d);
	my_printf("%f ", d);
	
	my_printf("\nDO YOU WANT TO CONTINUE(Y/y): ");
	scanf(" %c",&choice);
	} while(choice == 'y' || choice =='Y');
	
	return 0;
}
 
void my_printf(const char *arg, ...)
{
	va_list ap;
	int num;
	char c;
	char *str, number[50], float_string[50],double_string[50];
	float f;
	double d;
	
	va_start(ap, arg);
	while(*arg)
	{
		if(*arg == '%' )
		{
			arg++;
			switch(*arg)
			{
				case 'd':
					num = va_arg(ap, int);
					my_itoa(num,number);
					for(int i=0; number[i] != '\0'; i++)
						putchar(number[i]); 
					arg++;
					break;
				case 'c':
					c = va_arg(ap, int);
					putchar(c);
					arg++;
					break;
				case 's':
					str = va_arg(ap, char *);
					while(*str)
						putchar(*str++);
					arg++;
					break;
				case 'f':
					f = va_arg(ap, double);
					my_floatToString(f, float_string, 6);
					for(int i=0; float_string[i] != '\0'; i++)
						putchar(float_string[i]); 
					arg++;
					break;
				case 'l':
					arg++;
					if(*arg == 'f')
					{
						d = va_arg(ap, double);
						my_floatToString(f, double_string, 6);
						for(int i=0; double_string[i] != '\0'; i++)
							putchar(double_string[i]); 
						arg++;
					}
					else
						arg--;
					break;
			}
		}
		else
		{
			putchar(*arg);
			arg++;
		} 
	}
}

/* to convert float to float to string*/
void my_floatToString(float f, char *str, int precision)
{
	int i = 0, j = 0, power=1;
	int d = f;
	i = my_itoa(d, str);
	str[i++] = '.';
	f = f - d;				//float - integer not gives round off value
	for(j; j < precision ; j++)
		power *= 10; 
	f = f + (0.1/(float)power);		//as float contains .____9999
	f = (f*power); 
	j = my_itoa((int)f, &str[i]);
	i = i+j;
	for(j; j < 6; j++)
		str[i++] = '0';
	str[i]='\0';
}

/*to convert integer to string*/
int my_itoa(int num, char *str)
{
	int i=0,j,count=0,temp=num;
	if(num<0)
	{
		str[i++]='-';			//if negative str[0]='-' && increment the i
		num *= -1;
	}
	while(temp>0)				//how many digits are in the number
	{
		i++;
		temp=temp/10;
	}
	str[i]='\0';				//null at the end of 'i' characters
	for(j=i-1;num!=0;j--)			//for string i-1
	{
		str[j]=num%10+48;		//get the digit convert to char	
		num=num/10;			//reduce the last digit
	}
	return i;

}

