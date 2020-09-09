#include <stdio.h>

int	queue[1000001];
int	front = 1;
int	rear = -1;

int	queuePop(void)
{
	return (queue[front++]);
}

int main(void)
{
	int	N, i;

	scanf("%d", &N);
	rear = N;
	i = 1;
	while (i <= N)
	{
		queue[i] = i;
		i++;
	}
	while (1)
	{
		if (rear == front)
		{
			printf("%d\n", queue[rear]);
			break;
		}	
		queue[front++] = 0;
		queue[++rear] = queuePop();
	}
	return (0);
}
