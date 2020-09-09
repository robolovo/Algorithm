#include "queue.h"

void queue_clear(t_queue *queue, void (*free_data)(void *))
{
	t_node	*curr;
	t_node	*tmp;

	if (!queue || !free_data)
		return ;
	curr = queue->head;
	while (curr != 0)
	{
		tmp = curr;
		curr = curr->next;
		free_data(tmp->data);
		free(tmp);
	}
	queue->size = 0;
	queue->head = 0;
	queue->tail = 0;
}
