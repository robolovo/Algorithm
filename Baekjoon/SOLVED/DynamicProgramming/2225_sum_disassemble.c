#include <stdio.h>

long long dp[201][201];

int main(void)
{
	int n, k;

	scanf("%d %d", &n, &k);
	
	for (int i = 0; i <= n; i++)
		dp[1][i] = 1;
	
	for (int i = 2; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				dp[i][j] += dp[i - 1][l];
				dp[i][j] %= 1000000000;
			}
		}
	}
	printf("%lld\n", dp[k][n]);
	return (0);
}
