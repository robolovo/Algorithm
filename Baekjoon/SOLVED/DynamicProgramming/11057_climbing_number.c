#include <stdio.h>

int main(void)
{
	int N, ans;

	scanf("%d", &N);
	int dp[N+1][10];

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = 0;
			for (int k = j; k < 10; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
			}
		}		
	}
	ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (ans + dp[N][i]) % 10007;
	printf("%d\n", ans);
	return (0);
}
