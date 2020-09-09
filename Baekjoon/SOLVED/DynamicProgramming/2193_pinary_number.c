#include <stdio.h>

int main(void)
{
	int n;
	long long dp[91][2];

	scanf("%d", &n);

	dp[1][0] = 0;
	dp[1][1] = 1;

	dp[2][0] = 1;
	dp[2][1] = 0;

	for (int i = 3; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	printf("%lld\n", dp[n][0] + dp[n][1]);
	return (0);
}
