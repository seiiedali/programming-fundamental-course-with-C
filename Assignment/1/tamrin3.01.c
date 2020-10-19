#include <stdio.h>
int main()
{
	int c1, c2, i, j, p1, p2;
	p1 = 2;
	while (p1 < 100)
	{
		c1 = 1;
		i = 0;
		p2 = 0;
		while (c1 <= p1 / 2)
		{
			if ((p1 / c1) * c1 == p1)
			{
				i = i + 1;
			}
			c1 = c1 + 1;
		}
		p2 = p2 + p1 + 2;
		if (i == 1)
		{
			c2 = 1;
			j = 0;
			while (c2 <= p2 / 2)
			{
				if ((p2 / c2) * c2 == p2)
				{
					j = j + 1;
				}
				c2 = c2 + 1;
			}
			if (j == 1)
			{
				printf("%d", p1);
				printf(",%d\n", p2);
			}
		}
		p1 = p1 + 1;
	}
	return 0;
}
