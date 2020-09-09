#include "queue.h"

t_node *queue_pop(t_queue *queue)
{
	t_node	*front;

	if (!queue)
		return (0);
	front = queue->head;
	queue->head = front->next;
	queue->size--;
	return (front);
}
