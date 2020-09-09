#include "queue.h"

void	*queue_front(t_queue *queue)
{
	if (queue == 0)
		return (0);
	return (queue->data[0]);
}
