/**************************************************************************************
DOCUMENTATION:

NAME		: Karthikeyan.V
DATE		: 30.07.2021
DESCRIPTION	: To find the average of n numbers by taking input in 3 different ways.
OUTPUT		:

./a.out
ENTER NO. OF STUDENTS :2
ENTER NO. OF SUBJECTS :2
ENTER THE NAME OF SUBJECT 1 :maths
ENTER THE NAME OF SUBJECT 2 :science
----------------ENTER THE STUDENT DETAILS-------------------
ENTER THE STUDENT ROLL NO. :1
ENTER THE STUDENT 1 NAME :karthikeyan
ENTER THE maths MARK :50
ENTER THE science MARK :90
----------------ENTER THE STUDENT DETAILS-------------------
ENTER THE STUDENT ROLL NO. :2
ENTER THE STUDENT 2 NAME :nithis
ENTER THE maths MARK :80
ENTER THE science MARK :60

-----------DISPLAY MENU-------------
1.ALL STUDENT DETAILS
2.PARTICULAR STUDENT DETAILS
ENTER YOUR CHOICE :1


ROLL NO.	NAME		          maths        science	AVERAGE	GRADE
1		karthikeyan               50           90           	70              D
2		nithis                    80           60           	70              D
DO YOU WANT TO CONTINUE TO DISPLAY (Y/y) :y

-----------DISPLAY MENU-------------
1.ALL STUDENT DETAILS
2.PARTICULAR STUDENT DETAILS
ENTER YOUR CHOICE :2

-------MENU FOR PARTICULAR STUDENT---------

1.NAME
2.ROLL NO.
ENTER YOUR CHOICE: 1
ENTER THE NAME OF THE STUDENT: KARTHIKEYAN


ROLL NO.	NAME		          maths        science	AVERAGE	GRADE
1		karthikeyan               50           90           	70              D
DO YOU WANT TO CONTINUE TO DISPLAY (Y/y) :y

-----------DISPLAY MENU-------------
1.ALL STUDENT DETAILS
2.PARTICULAR STUDENT DETAILS
ENTER YOUR CHOICE :2

-------MENU FOR PARTICULAR STUDENT---------

1.NAME
2.ROLL NO.
ENTER YOUR CHOICE: 2
ENTER THE ROLL NO. OF THE STUDENT: 2


ROLL NO.	NAME		          maths        science	AVERAGE	GRADE
2		nithis                    80           60           	70              D
DO YOU WANT TO CONTINUE TO DISPLAY (Y/y) :y

-----------DISPLAY MENU-------------
1.ALL STUDENT DETAILS
2.PARTICULAR STUDENT DETAILS
ENTER YOUR CHOICE :2

-------MENU FOR PARTICULAR STUDENT---------

1.NAME
2.ROLL NO.
ENTER YOUR CHOICE: 1
ENTER THE NAME OF THE STUDENT: karthi

NOTICE!! NO STUDENT FOUND WITH THE SPECIFIED NAME
DO YOU WANT TO CONTINUE TO DISPLAY (Y/y) :y

-----------DISPLAY MENU-------------
1.ALL STUDENT DETAILS
2.PARTICULAR STUDENT DETAILS
ENTER YOUR CHOICE :2

-------MENU FOR PARTICULAR STUDENT---------

1.NAME
2.ROLL NO.
ENTER YOUR CHOICE: 2
ENTER THE ROLL NO. OF THE STUDENT: 6

NOTICE!! NO STUDENT FOUND WITH THE SPECIFIED ROLL NUMBER
DO YOU WANT TO CONTINUE TO DISPLAY (Y/y) :n
DO YOU WANT TO CONTINUE (Y/y) :n
************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio_ext.h>
char grading(float);
int my_strcmp(char *, char *);
struct student 
{
	int rollno;
	char *name;
	int *marks;
	float average;
	char grade;
};
void printStructure(struct student *s, int count);

int main()
{
	int countOfStudents, countOfSubjects, sum, menuChoice, studentChoice, studentRoll, found = 0;
	char **subject , choice, *studentName;
	do
	{
		__fpurge(stdin);
		printf("ENTER NO. OF STUDENTS :");
		scanf("%d",&countOfStudents);
		struct student s[countOfStudents];
		printf("ENTER NO. OF SUBJECTS :");
		scanf("%d",&countOfSubjects);
		subject = (char **)malloc(countOfSubjects * sizeof(char *));
		for(int i = 0; i < countOfSubjects; i++)
		{
			printf("ENTER THE NAME OF SUBJECT %d :", i+1);
			__fpurge(stdin);
			subject[i] = (char *)malloc(sizeof(char));
			scanf("%s", subject[i]);
			
		}
		for(int i = 0; i < countOfStudents; i++)
		{
			printf("----------------ENTER THE STUDENT DETAILS-------------------\n");
			printf("ENTER THE STUDENT ROLL NO. :");
			__fpurge(stdin);
			scanf("%d", &s[i].rollno);
			__fpurge(stdin);
			printf("ENTER THE STUDENT %d NAME :", i+1);
			s[i].name = (char *)malloc(sizeof(char));			//dynamic allocation for name
			scanf("%s", s[i].name);	
			s[i].marks = (int *) malloc(countOfSubjects * sizeof(int));	//dynamic allocation of marks for no of subjects
			sum = 0;
			
			for(int j = 0; j < countOfSubjects; j++)
			{
				printf("ENTER THE %s MARK :", subject[j]);
				__fpurge(stdin);
				scanf("%d", &s[i].marks[j]);
				sum = sum + s[i].marks[j];
			}	
			s[i].average = (float)sum / countOfSubjects; 			//avaerage
			s[i].grade = grading(s[i].average);			
		}
		
		do
		{
			printf("\n-----------DISPLAY MENU-------------");
			printf("\n1.ALL STUDENT DETAILS\n2.PARTICULAR STUDENT DETAILS\n");
			printf("ENTER YOUR CHOICE :");
			scanf("%d",&menuChoice);
			if(menuChoice ==  1)
			{	
				/*headings*/
				printf("\n\nROLL NO.\tNAME\t\t");
				for(int j = 0; j < countOfSubjects; j++)
				{
					printf("%15s",subject[j]);
				}
				printf("\t\tAVERAGE\t\tGRADE\n");
				
				for(int i = 0; i < countOfStudents; i++)
					printStructure(&s[i], countOfSubjects); 
			}
			else if(menuChoice == 2)
			{
				printf("\n-------MENU FOR PARTICULAR STUDENT---------\n");
				printf("\n1.NAME\n2.ROLL NO.\nENTER YOUR CHOICE: ");
				scanf("%d",&studentChoice);
				
				if(studentChoice == 1)
				{
					found = 0;
					printf("ENTER THE NAME OF THE STUDENT: ");
					scanf(" %s",studentName);
					
					
					for(int i = 0; i < countOfStudents; i++)
					{
						if((my_strcmp(s[i].name , studentName)) == 0)	
						{	
							found++;
						
							if(found > 1)
								printStructure(&s[i], countOfSubjects);
							if(found == 1)
							{
								/*headings*/
								printf("\n\nROLL NO.\tNAME\t\t");
								for(int j = 0; j < countOfSubjects; j++)
								{
									printf("%15s",subject[j]);
								}
								printf("\t\tAVERAGE\t\tGRADE\n");
								printStructure(&s[i], countOfSubjects);
							}		
						}
					}
					if(found == 0)
					{
						printf("\nNOTICE!! NO STUDENT FOUND WITH THE SPECIFIED NAME\n");
					}
				}
				else if(studentChoice == 2)
				{
					found = 0;
					printf("ENTER THE ROLL NO. OF THE STUDENT: ");
					scanf(" %d",&studentRoll);
					
					for(int i = 0; i < countOfStudents; i++)
					{
						if(studentRoll == s[i].rollno)
						{
							found++;
							
							if(found == 1)
							{
								/*headings*/
								printf("\n\nROLL NO.\tNAME\t\t");
								for(int j = 0; j < countOfSubjects; j++)
								{
									printf("%15s",subject[j]);
								}
								printf("\t\tAVERAGE\t\tGRADE\n");
								printStructure(&s[i], countOfSubjects);
							}
							
							if(found > 1)
								printStructure(&s[i], countOfSubjects);			
						}
					}
					if( found == 0 )
						printf("\nNOTICE!! NO STUDENT FOUND WITH THE SPECIFIED ROLL NUMBER\n");
				}
				else
					printf("\nINVALID CHOICE\n");
			}
			else
			{
					printf("\nINVALID CHOICE\n");
			}
			printf("DO YOU WANT TO CONTINUE TO DISPLAY (Y/y) :");
			__fpurge(stdin);
			scanf(" %c", &choice);	
		}while (choice == 'y' || choice == 'Y');
		
	printf("DO YOU WANT TO CONTINUE (Y/y) :");
	__fpurge(stdin);
	scanf(" %c", &choice);	
		
	}while (choice == 'y' || choice =='Y'); 	
	return 0;
}

/*to decide the grade*/
char grading(float avg)
{
		if(avg > 90.0 && avg <= 100.0)
			return 'A';
		if(avg > 80.0 && avg <= 90.0)
			return 'B';
		if(avg > 70.0 && avg <= 80.0)
			return 'C';
		if(avg >60.0 && avg <= 70.0)
			return 'D';
		if(avg > 50.0 && avg <= 60.0)
			return 'E';
		return 'F';
}

/*string compare function*/
int my_strcmp(char *str1, char *str2)
{
	while((*str1 && *str2) && (*str1 == *str2 || *str1 - 32 == *str2 || *str2 - 32 == *str1))
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;	
}	

/*to print the structure elements of one variable*/
void printStructure(struct student *s, int count)
{
	printf("%d\t\t%-26s", s->rollno, s->name);
	for(int i = 0; i < count; i++)
		printf("%-13d",s->marks[i]);
	printf("\t%-16g%c\n", s->average, s->grade); 
}








