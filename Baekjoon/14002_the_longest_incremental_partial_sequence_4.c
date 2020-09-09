#include <stdio.h>

int main(void)
{
	int n;
	int arr[1001];
	int dp[1001];
	int res[1001];
	int max;

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++)
		dp[i] = 1;

	int end;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i] <= dp[j])
				dp[i] = dp[j] + 1;
		}
		if (max < dp[i])
		{
			max = dp[i];
			end = i;
		}
	}

	int min;
	for (int i = 1; i <= max; i++)
	{
		min = 1000;
		for (int j = 1; j <= end; j++)
		{
			if (dp[j] == i && min > arr[j])
				min = arr[j];
		}
		res[i] = min;
	}

	printf("%d\n", max);
	for (int i = 1; i <= max; i++)
		printf("%d ", res[i]);
	printf("\n");
	return (0);
}
