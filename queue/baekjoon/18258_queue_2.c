#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct 	s_queue
{
	int			front;
	int			rear;
	int			*data;
}				t_queue;

t_queue	*queueInit(void)
{
	t_queue	*queue;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue))))
		return (0);
	queue->front = 0;
	queue->rear = -1;
	if (!(queue->data = (int *)malloc(sizeof(int))))
	{
		free(queue);
		return (0);
	}
	return (queue);
}

void	queueSize(t_queue *queue)
{
    printf("%d\n", queue->rear - queue->front + 1);
}

void		isEmpty(t_queue *queue)
{
	if (queue->rear - queue->front + 1 == 0)
		printf("%d\n", 1);
	printf("%d\n", 0);
}

void	queuePush(t_queue *queue, int data)
{
	queue->rear++;
	queue->data[queue->rear] = data;
}

void	queuePop(t_queue *queue)
{
	if (queue->rear - queue->front + 1 == 0)
		printf("%d\n", -1);
	printf("%d\n", queue->data[queue->front++]);
}

void	queueFront(t_queue *queue)
{
	if (queue->rear - queue->front + 1 == 0)
		printf("%d\n", -1);
	printf("%d\n", queue->data[queue->front]);
}

void	queueBack(t_queue *queue)
{
	if (queue->rear - queue->front + 1 == 0)
		printf("%d\n", -1);
	printf("%d\n", queue->data[queue->rear]);
}

int	main(void)
{
	int		N, num;
	char	input[6];
	t_queue	*queue;

	queue = queueInit();
	scanf("%d", &N);
	while (N--)
	{
		scanf("%s", input);
		if (!strcmp(input, "pop"))
			queuePop(queue);
		else if (!strcmp(input, "size"))
			queueSize(queue);
		else if (!strcmp(input, "empty"))
			isEmpty(queue);
		else if (!strcmp(input, "front"))
			queueFront(queue);
		else if (!strcmp(input, "back"))
			queueBack(queue);
		else if (!strcmp(input, "push"))
		{
			scanf("%d", &num);
			queuePush(queue, num);
		}
	}
	return (0);
}
