#include <stdio.h>
#define MOD 1000000009

long long dp[1000001];

int main(void)
{
	int T, n, i;

	scanf("%d", &T);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (i = 4; i <= 1000000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	dp[i] %= MOD;

	while (T--)
	{
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return (0);
}
