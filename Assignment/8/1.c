#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct stu
{
	char name[100];
	int id;
	double average;
};
struct stu addstudent();
void printstu(struct stu);
int maxstu(struct stu[], int);

int main()
{
	int n, j;
	int i = 0;
	printf("Tedad daneshju: ");
	scanf("%d", &n);
	struct stu *a;
	a = (struct stu *)malloc(n * sizeof(struct stu));
	for (i = 0; i < n; i++)
	{
		a[i] = addstudent();
	}
	for (i = 0; i < n; i++)
	{
		printstu(a[i]);
	}
	printf("maX student: ");
	j = maxstu(a, n);
	printstu(a[j]);

	return 0;
}
int maxstu(struct stu a[], int n)
{
	double max;
	max = 0;
	int i, j;
	for (i = 0; i < n; i++)
	{
		if (max < a[i].average)
		{
			j = i;
		}
	}
	return j;
}
struct stu addstudent()
{
	struct stu newstudent;
	printf("Enter the name of student:");
	scanf("%s", newstudent.name);
	printf("Enter student id:");
	scanf("%d", &newstudent.id);
	printf("Enter average:");
	scanf("%lf", &newstudent.average);

	return newstudent;
}
void printstu(struct stu studenttoprint)
{
	printf("%s \t", studenttoprint.name);
	printf("%d \t", studenttoprint.id);
	printf("%lf \t", studenttoprint.average);
}
