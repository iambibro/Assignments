#include<stdio.h>
struct stud
{
	int roll;
	char name[30];
	int m1, m2;
}s[20];
void entry(int);
void avg();
void highest();
void details();
int n, i;
int main()
{
	int ch;
	printf("Enter number of students: ");
	scanf("%d", &n);
	for(i = 0;i < n;i++)
		entry(i); // Calling method entry
	while(1)
	{
		printf("\n1. Details of student\n2. Average marks\n3. Highest marks\n4. Exit");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	details(); // Find the details of a particular student
					break;
			case 2: avg(); // Displaying average marks 
					break;
			case 3: highest();// Displaying highest marks in each subject
					break;
			case 4: return 0;
			default: printf("\nWrong choice!");				
		}
	}
	return 0;
}

// Definition of 'entry'
void entry(int i)
{
	char n[30];
	int j=0;
	printf("\nEnter the details of student %d :", i+1);
	printf("\nEnter roll: ");
	scanf("%d", &s[i].roll);
	printf("\nEnter name: ");
	fflush(stdin);
	gets(n);
	for(j=0;n[j]!='\0';j++)
		s[i].name[j]=n[j];
	s[i].name[j]='\0';
	printf("\nEnter marks in subject 1: ");
	scanf("%d", &s[i].m1);
	printf("\nEnter marks in subject 2: ");
	scanf("%d", &s[i].m2);
}

// Definition of 'display'
void details()
{
	int r;
	printf("\nEnter the roll no: ");
	scanf("%d", &r);
	for(i = 0;i <  n;i++)
	{
		if(s[i].roll == r)
		{
			printf("\nDetails of student:");
			printf("\n\tName: %s",s[i].name);
			printf("\nMarks in:");
			printf("\n\tSubject 1: %d", s[i].m1);
			printf("\n\tSubject 2: %d", s[i].m2);
			break;
		}
	}
	if(i == n)
		printf("\nRecord does not exist for roll %d", r);
}

// Definition of method average
void avg()
{
	int t1 = 0, t2 = 0;
	float avg1, avg2;
	for(i = 0;i<n;)
	{
		t1 += s[i].m1; // Finding sum of all marks in sub1
		t2 += s[i++].m2; // Finding sum of all marks in sub2
	}
	avg1 = t1/n; avg2 = t2/n;
	printf("\nAverage marks in sub 1: %0.2f", avg1);
	printf("\nAverage marks in sub 2: %0.2f", avg2);
}

//Definition of method highest
void highest()
{
	int max1 = 0, max2 = 0, t1, t2;
	for(i = 0;i < n;i++)
	{
		if(s[i].m1 > max1)
		{
			max1 = s[i].m1;
			t1 = i;
		}
		if(s[i].m2 > max2)
		{
			max2 = s[i].m1;
			t2 = i;
		}
	}
	printf("\nDetails of student(s) who scored the highest marks:");
	if(t1 == t2)
	{
		printf("\n\tRoll: %d\n\tName: %s", s[t1].roll, s[t1].name);
		printf("\nScored highest marks in both the subjects");
	}
	else
	{	
		printf("\n\tRoll: %d\n\tName: %s", s[t1].roll, s[t1].name);
		printf("\nScored the highest marks in subject 1");
		printf("\n\tRoll: %d\n\tName: %s", s[t2].roll, s[t2].name);
		printf("\nScored the highest marks in subject 2");
	}
}
