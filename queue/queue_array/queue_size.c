#include "queue.h"

int	queue_size(t_queue	*queue)
{
	if (queue == 0)
		return (0);
	return (queue->last_index + 1);
}
