#include <stdio.h>

int main(void)
{
	int n;
	int arr[1001];
	int dp[1001];
	int max = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	
	for (int i = 1; i <= n; i++)
		dp[i] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{	
			if (arr[j] < arr[i] && dp[i] <= dp[j])
				dp[i] = dp[j] + 1;
		}
		if (max < dp[i])
			max = dp[i];
	}

	printf("%d\n", max);
	return (0);
}
