#include "queue.h"

void	free_queue(t_queue *queue, void (*free_data)(void *))
{
	queue_clear(queue, free_data);
	free(queue);
}
