#include <stdio.h>
int main()
{
	int i = 0, n, a = 0, b = 0, c = 0;
	double x[100], s1, s2, s3, sum;
	printf("How many number: ");
	scanf("%d", &n);
	while (i < n)
	{
		printf("Enter the number: ");
		scanf("%lf", &x[i]);
		i = i + 1;
	}
	printf("Enter the first & scond & third number for search:\n");
	scanf("%lf", &s1);
	scanf("%lf", &s2);
	scanf("%lf", &s3);
	while (i >= 0)
	{
		if (x[i] == s1)
		{
			a = a + 1;
		}
		if (x[i] == s2)
		{
			b = b + 1;
		}
		if (x[i] == s3)
		{
			c = c + 1;
		}
		i = i - 1;
	}
	printf("The number of first & second & third nember which found is:\n ");
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("The avrage of plenty is: ");
	sum = a + b + c;
	printf("%lf", sum / 3);
	return 0;
}
