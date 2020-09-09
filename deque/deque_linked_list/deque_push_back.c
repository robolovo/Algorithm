#include "deque.h"

int	deque_push_back(t_queue *deque, void *data)
{
	t_node	*new_node;

	if (!deque || !(new_node = create_elem(data)))
		return (0);
	new_node->prev = deque->back;
	if (deque->size == 0)
		deque->front = new_node;	
	else
		deque->back->next = new_node;
	deque->back = new_node;
	deque->size++;
	return (1);
}
