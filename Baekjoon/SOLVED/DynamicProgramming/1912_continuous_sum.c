#include <stdio.h>
#include <limits.h>

int main(void)
{
	int n;
	int arr[100001];
	int max = INT_MIN;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	arr[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] > arr[i - 1] && arr[i - 1] < 0)
			continue;
		arr[i] = arr[i] + arr[i - 1];
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	printf("%d\n", max);
	return (0);
}
