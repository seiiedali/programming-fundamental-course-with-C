#include <stdio.h>
int main()
{
	int i, j, k, sum;
	char str1[50], str2[50], str3[50];
	printf("Enter the first string(mortab): ");
	scanf("%s", str1);
	printf("Enter the second string(moratab): ");
	scanf("%s", str2);
	for (i = 0; str1[i] != 0; i++)
	{
		;
	}
	for (j = 0; str2[j] != 0; j++)
	{
		;
	}
	sum = i + j;
	for (k = 0, i = 0, j = 0; k < sum - 1; k++)
	{
		if (str1[i] != 0)
		{
			str3[k] = str1[i];
			i++;
		}
		if (str2[j] < str3[k] && str2[j] != 0)
		{
			str3[k] = str2[j];
			j++;
			if (str1[i] != 0)
			{
				i--;
			}
		}
	}
	str3[k] = 0;
	printf("%s", str3);
	return 0;
}
