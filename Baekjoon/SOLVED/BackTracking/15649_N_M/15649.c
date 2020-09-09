#include <stdio.h>
#include <stdbool.h>

bool visited[9] = { false, };
int nums[8];

void	dfs(int count, int N, int M)
{
	int i;

	if (count == M)
	{
		for (i = 0; i < M; i++)
			printf("%d ", nums[i]);
		printf("\n");
		return ;
	}
	for (i = 1; i <= N; i++)
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

int	main(void)
{
	int	N, M;

	scanf("%d %d", &N, &M);
	
	dfs(0, N, M);
	return (0);
}
