#include "queue.h"

t_node *queue_front(t_queue *queue)
{
	t_node *front;

	front = queue->head;
	return (front);
}
