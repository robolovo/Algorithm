#include "queue.h"

void	*queue_pop(t_queue *queue)
{
	int i;
	int	rtn;

	if (queue == 0)
		return (0);
	i = 0;
	rtn = queue->data[0];
	while (i < queue->last_index)
	{
		queue->data[i] = queue->data[i + 1];
		i++;
	}
	queue->last->index--;
	return (rtn);
}
