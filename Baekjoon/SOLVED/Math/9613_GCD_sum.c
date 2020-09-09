#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (gcd(b, a % b));
}

int main(void)
{
	int t, n, i, j;
	int num[101];
	long long sum;

	scanf("%d", &t);
	while (t--)
	{
		sum = 0;
		scanf("%d", &n);
		i = 0;
		while (i < n)
		{
			scanf("%d", &num[i]);
			i++;
		}
		i = 0;
		while (i < n - 1)
		{
			j = 1;
			while (j < n - i)
			{
				sum += gcd(num[i], num[i + j]);
				j++;
			}
			i++;
		}
		printf("%lld\n", sum);
	}
}
