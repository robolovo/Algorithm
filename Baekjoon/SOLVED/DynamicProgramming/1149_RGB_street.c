#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int	cost[3][1001];

int main(void)
{
	int N;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &cost[j][i]);
	
	for (int n = 2; n <= N; n++)
	{
		cost[0][n] += MIN(cost[1][n - 1], cost[2][n - 1]);
		cost[1][n] += MIN(cost[0][n - 1], cost[2][n - 1]);
		cost[2][n] += MIN(cost[0][n - 1], cost[1][n - 1]); 
	}
	printf("%d\n", MIN(MIN(cost[0][N], cost[1][N]), cost[2][N]));
	return (0);
}
