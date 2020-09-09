#include <stdio.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main(void)
{
	int N;

	scanf("%d", &N);
	int pack[N + 1];
	int dp[N + 1];

	for (int i = 1; i <= N; i++)
		scanf("%d", &pack[i]);
	for (int i = 0; i <= N; i++)
		dp[i] = 2100000000;

	dp[0] = 0;
	dp[1] = pack[1];
	for (int i = 2; i <= N; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = MIN(dp[i], dp[i - j] + pack[j]);
	printf("%d\n", dp[N]);
	return (0);
}
