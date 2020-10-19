#include <stdio.h>
void str_search(char[]);
int main()
{
	char str[50];
	printf("Enter the string: ");
	scanf("%s", str);
	str_search(str);
	return 0;
}
void str_search(char str[])
{
	int i, j, b = 0;
	for (i = 0; str[i] != 0; i++)
	{
		for (j = 0; str[j] != 0; j++)
		{
			if (i == j && str[j + 1] != 0)
			{
				j++;
			}
			else if (str[j + 1] == 0)
			{
				break;
			}
			if (str[i] == str[j])
			{
				printf("The same repetitive charcarter is exist in the word");
				b = 1;
				break;
			}
		}
	}
	if (b == 0)
	{
		printf("The same repetitive charcarter is not exist in the word");
	}
}
