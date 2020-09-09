#include "queue.h"

t_queue	*queue_init(unsigned int max_size)
{
	t_queue	*queue;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue))))
		return (0);
	queue->max_size = max_size;
	queue->last_index = -1;
	if (!(queue->data = (void **)malloc(sizeof(void *) * max_size)))
	{
		free(queue);
		return (0);
	}
	return (queue);
}
