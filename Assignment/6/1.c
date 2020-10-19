#include <stdio.h>
int main()
{
	char str1[50], str2[50];
	int i, j = 0, n;
	printf("Enter first string: ");
	scanf("%s", str1);
	printf("Enter second string: ");
	scanf("%s", str2);
	printf("How many character from second string: ");
	scanf("%d", &n);
	printf("Enter i: ");
	scanf("%d", &i);
	while (str1[j] != 0)
	{
		j++;
	}
	while (j >= i)
	{
		str1[j + n] = str1[j];
		j--;
	}
	for (j = 0; j < n; j++, i++)
	{
		str1[i] = str2[j];
	}
	printf("%s", str1);
	return 0;
}
