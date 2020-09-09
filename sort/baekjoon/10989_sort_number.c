#include <stdio.h>

int main(void)
{
	int N, i, j, num, flag;
	int count[10001];
	
	i = 0;
	while (i <= 10000)
		count[i++] = 0;
	
	scanf("%d", &N);
	
	i = 0;
	while (i < N)
	{
		scanf("%d", &num);
		count[num] += 1; 
		i++;
	}
	
	i = 0;
	while (i <= 10000)
	{
		flag = 1;	
		if (count[i] == 0)
			flag = -1;
		j = 0;
		while (flag == 1 && j < count[i])
		{
			printf("%d\n", i);
			j++;
		}
		i++;
	}
	return (0);
}
