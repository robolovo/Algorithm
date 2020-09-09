#include "queue.h"

t_queue	*queue_init(void)
{
	t_queue	*queue;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue))))
		return (0);
	queue->size = 0;
	queue->head = 0;
	queue->tail = 0;
	return (queue);
}
