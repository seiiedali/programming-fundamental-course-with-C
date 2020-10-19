#include <stdio.h>
struct name
{
	char nam[20];
	char fam_nam[20];
};
struct stu
{
	struct name esm;
	double mark[3];
	double avg;
};

void input(struct stu, int);
int main()
{
	int i;
	struct stu st[4];
	for (i = 0; i < 4; i++)
	{
		input(st[i], i);
	}
	return 0;
}
void input(struct stu a, int i)
{
	int j;
	printf("Enter %d student name: ", i + 1);
	scanf("%s", a.esm.nam);
	printf("Enter %d student family name: ", i + 1);
	scanf("%s", a.esm.fam_nam);
	for (j = 0; j < 3; j++)
	{
		printf("Enter %d student mark(%d) : ", i + 1, j + 1);
		scanf("%lf", &a.mark[j]);
	}
}
