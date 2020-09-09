#include "queue.h"

int	queue_push(t_queue *queue, void *data)
{
	t_node	*curr;	
	t_node 	*new;

	if (!queue || !data)
		return (0);
	if (!(new = create_elem(data)))
		return (0);
	curr = queue->head;
	while (curr != 0)
	{
		curr = curr->next;					
	}
	curr = new;
	queue->size++;
	return (1);
}
