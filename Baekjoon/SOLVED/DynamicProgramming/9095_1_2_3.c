#include <stdio.h>

int count;

void dp(int n, int target)
{
	if (n == target)
	{
		count++;
		return ;
	}
	if (n > target)
		return ;
	dp(n + 1, target);
	dp(n + 2, target);
	dp(n + 3, target);
}

int main(void)
{
	int T, N;

	scanf("%d", &T);

	while (T--)
	{
		count = 0;	
		scanf("%d", &N);
		dp(0, N);
		printf("%d\n", count);
	}
	return (0);
}
