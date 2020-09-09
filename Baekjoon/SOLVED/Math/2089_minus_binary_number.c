#include <stdio.h>
/*
void	decimal_to_binary(int n)
{
	int a, b;

	if (n == 0)
		return ;
	a = n / 2;
	b = n % 2;
	decimal_to_binary(a);
	printf("%d", b);
}
*/
void decimal_to_binary(int n)
{
	int a, b;

	if (n == 0)
		return ;
	if (n % -2 == 0)
		a = n / -2;
	else
		a = (n - 1) / -2;
	b = n % -2;
	decimal_to_binary(a);
	if (b < 0)
		b *= -1;
	printf("%d", b);
}

int main(void)
{
	int N;

	scanf("%d", &N);

	if (N == 0)
	{
		printf("0\n");
		return (0);
	}
	decimal_to_binary(N);
	printf("\n");
	return (0);
}
