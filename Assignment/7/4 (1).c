#include <stdio.h>
void convert(int[], char[], int);
int main()
{
	int a[20], i, n;
	char b[20];
	printf("How many value: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter the value (x<10): ");
		scanf("%d", &a[i]);
	}
	convert(a, b, n);
	for (i = 0; i < n; i++)
	{
		printf("%c\t", b[i]);
	}
	return 0;
}
void convert(int a[], char b[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		b[i] = a[i] + 48;
	}
}
