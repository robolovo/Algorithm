#include <stdio.h>

int main(void)
{
	int n, i;
	int m[1001];
	int res;

	scanf("%d", &n);
	
	if (n < 3)
	{
		if (n == 1)
			printf("1\n");
		else
			printf("2\n");
		return (0);
	}
	m[1] = 1;
	m[2] = 2;
	for (i = 3; i <= n; i++)
	{
		m[i] = (m[i - 1] + m[i - 2]) % 10007;
		res = m[i];
	}
	printf("%d\n", res);
	return (0);
}
