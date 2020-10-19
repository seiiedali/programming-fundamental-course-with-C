#include <stdio.h>
int main()
{
	char str[50];
	int j = 0, i;
	printf("Enter string: ");
	scanf("%s", str);
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] == 'o' || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'u')
		{
			j++;
		}
	}
	printf("seda dar: ");
	printf("%d\n", j);
	printf("bi seda: ");
	printf("%d\n", i - j);
	return 0;
}
