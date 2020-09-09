#include <stdio.h>
#include <stdbool.h>

bool visited[9] = { false, };
int	nums[9];


void	dfs(int count, int N, int M)
{
	if (count == M)
	{
		for (int k = 0; k < M - 1; k++)
		{
			if (nums[k] > nums[k + 1])
				return;
		}
		for (int j = 0; j < M; j++)
			printf("%d ", nums[j]);
		printf("\n");
		return ;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			nums[count] = i;
			dfs(count + 1, N, M);
			visited[i] = false;
		}
	}
}

int main(void)
{
	int N, M;

	scanf("%d %d", &N, &M);

	dfs(0, N, M);
	return (0);
}
