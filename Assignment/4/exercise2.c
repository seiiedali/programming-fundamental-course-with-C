#include <stdio.h>
int gcd(int m, int n);
int main()
{
	int m, n, ans;
	printf("Enter m>0: ");
	scanf("%d", &m);
	printf("Enter n>0: ");
	scanf("%d", &n);
	ans = gcd(m, n);
	if (ans < 0)
	{
		ans = -ans;
	}
	printf("%d", ans);
	return 0;
}
int gcd(int m, int n)
{
	if (m == n || n < 0)
	{
		return n;
	}
	gcd(n, m - n);
}
