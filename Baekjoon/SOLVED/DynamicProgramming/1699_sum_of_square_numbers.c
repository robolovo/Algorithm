#include <stdio.h>

#define max 100001
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main(void)
{
	int n, i, count;
	int dp[max];

	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
		dp[i] = max;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++)
		for (int s = 2; s * s <= i; s++)
			dp[i] = MIN(dp[i], dp[i - (s * s)] + 1);
	
	printf("%d\n", dp[n]);
	return (0);
}
