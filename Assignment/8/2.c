#include <stdio.h>
#include <stdlib.h>
int func(int *, int);
int main()
{
	int *pa;
	int n, i;
	printf("Enter n: ");
	scanf("%d", &n);
	pa = func(pa, n);
	pa[0] = 5;
	pa[1] = 2;
	pa[2] = 9;
	for (i = 0; i < 3; i++)
	{
		printf("%d\n", pa[i]);
	}
	return 0;
}
int func(int *a, int n)
{
	a = (int *)malloc(n * sizeof(int));
	return a;
}
