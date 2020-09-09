#include <stdio.h>
#include <stdbool.h>

int op[10];
int list[10];
int num[11];
bool visited[10] = { false, };
int max = -1000000000, min = 1000000000;

void	get_max_min(int m)
{
	int res;
	int i;

	i = 0;
	res = num[i];
	while (i < m)
	{	
		if (list[i] == 0)
			res = res + num[i + 1];
		else if (list[i] == 1)
			res = res - num[i + 1];	
		else if (list[i] == 2)
			res = res * num[i + 1];
		else if (list[i] == 3)
		{
			if (res < 0)
			{
				res *= -1;
				res = res / num[i + 1];
				res *= -1;
			}
			else
				res = res / num[i + 1];
		}
		i++;
	}
	if (max < res)
		max = res;
	if (min > res)
		min = res;
}


void dfs(int count, int n, int m)
{
	if (count == m)
	{
		get_max_min(m);
		return ;
	}
	for (int i = 0; i < m; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			list[count] = op[i];
			dfs(count + 1, n, m);
			visited[i] = false;
		}
	}
}

int main(void)
{
	int n, m, i, j, op_num;

	scanf("%d", &n);
	m = n - 1;
	i = 0;
	while (i < n)
	{
		scanf("%d", &num[i]);	
		i++;
	}
	i = 0;
	j = 0;
	while (i < 4)
	{
		scanf("%d", &op_num);
		while (op_num--)
		{
			op[j] = i;
			j++;
		}
		i++;
	}
	dfs(0, n, m);
	printf("%d\n", max);
	printf("%d\n", min);
	return (0);
}
