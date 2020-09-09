#include <stdio.h>

int main(void)
{
	int N, M, i, j, number, exist;
	int num[100001];

	scanf("%d", &N);
	i = 0;
	while (i < N)
	{
		scanf("%d", &number);
		num[i] = number;
		i++;
	}

	scanf("%d", &M);
	i = 0;
	while (i < M)
	{
		scanf("%d", &exist);
		int flag = 1;
		j = 0;
		while (j < N)
		{
			if (num[j] == exist)
			{	
				printf("1\n");
				flag = 0;
				break;
			}
			j++;
		}
		if (flag)
			printf("0\n");
		i++;
	}
	return (0);
}
