#include <stdio.h>
#include <stdbool.h>

#define MAX 1000000

int main(void)
{
	int n, p, i, j;
	bool prime[MAX + 1] = { false, };

	prime[1] = true;
	for (i = 2; i * i <= MAX; i++)
		for (j = i * i; j <= MAX; j += i)
			if (!prime[j])
				prime[j] = true;

	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (i = 2; i <= n; i++)
		{
			if (!prime[i])
			{	
				p = n - i;
				if (!prime[p])
				{
					printf("%d = %d + %d\n", n, i, p);
					break;
				}
			}
		}
	}
	
	return (0);
}
