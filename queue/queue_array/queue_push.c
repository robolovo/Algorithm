#include "queue.h"

int	queue_push(t_queue *queue, void *data)
{
	if (queue == 0 || data == 0)
		return (0);
	queue->last_index++;
	queue->data[queue->last_index] = data;
	return (1);
}
