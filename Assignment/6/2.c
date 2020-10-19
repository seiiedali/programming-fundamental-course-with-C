#include <stdio.h>
int main()
{
	char str[50], c;
	int i = 0, j = 0;
	printf("Enter charactor you want to remove: ");
	scanf("%c", &c);
	printf("Enter string: ");
	scanf("%s", str);
	while (str[i] != 0)
	{
		j = 0;
		while (str[j] != c)
		{
			j++;
		}
		if (str[j] != c)
		{
			break;
		}
		while (str[j] != 0)
		{
			str[j] = str[j + 1];
			j++;
		}

		i++;
	}
	printf("%s", str);
	return 0;
}
