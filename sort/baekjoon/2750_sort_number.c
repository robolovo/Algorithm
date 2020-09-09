#include <stdio.h>

int main(void)
{
	int N, i, j, temp;
	int	array[1000];

	scanf("%d", &N);
	i = 0;
	while (i < N)
	{
		scanf("%d", &array[i]);
		i++;
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	i = 0;
	while(i < N)
		printf("%d\n", array[i++]);
	return (0);
}
