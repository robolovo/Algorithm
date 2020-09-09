#include <stdio.h>

#define MOD 1000000009

long long dp[100001][4];

int main(void)
{
	int T, N;

	scanf("%d", &T);

	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[0][3] = 0;

	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[1][3] = 0;

	dp[2][1] = 0;
	dp[2][2] = 1;
	dp[2][3] = 0;

	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int i = 4; i <= 100000; i++)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD; 
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}

	while (T--)
	{
		scanf("%d", &N);
		printf("%lld\n", (dp[N][1] + dp[N][2] + dp[N][3]) % MOD);
	}

	return (0);
}
