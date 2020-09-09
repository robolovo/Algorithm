#include <stdio.h>

int	queue[1000];
int	front;
int	rear;

int	main(void)
{
	int	N, i, nth, docsNum, docTarget;

	scanf("%d\n", &N);
	while (N--)
	{
		scanf("%d %d", &docsNum, &docTarget);
		i = 0;
		while (i < docsNum)
			scanf("%d", &queue[i++]);
		front = 0;
		rear = i - 1;
		i = 0;
		nth = 0;
		while (front + i <= rear)
		{
			if (queue[front] < queue[front + i])
			{
				queue[++rear] = queue[front++];
				if (front - 1 == docTarget)
					docTarget = rear;
				i = -1;
			}
			if (front + i == rear)
			{	
				queue[front++] = 0;	
				nth++;
				i = -1;
				if (front - 1 == docTarget)
					break;
			}
			i++;
		}
		printf("%d\n", nth);
	}
}
