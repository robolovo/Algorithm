#include <stdio.h>

int	factorial(int n)
{
	if (n == 0 || n == 1)
		return (1);
	return (n * factorial(n - 1));
}

int main(void)
{
	int N, res;

	scanf("%d", &N);

	res = factorial(N);
	printf("%d\n", res);
	return (0);
}
