#include <stdio.h>

int main(void)
{
	int N, n, res;

	scanf("%d", &N);
	int dp[N + 1][3];

	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (n = 2; n <= N; n++)
	{
		dp[n][0] = (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % 9901;
		dp[n][1] = (dp[n - 1][0] + dp[n - 1][2]) % 9901;
		dp[n][2] = (dp[n - 1][0] + dp[n - 1][1]) % 9901;
	}
	printf("%d\n", (dp[N][0] + dp[N][1] + dp[N][2]) % 9901);
	return (0);
}
