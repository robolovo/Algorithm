#include "deque.h"

int	deque_push_front(t_deque *deque, void *data)
{
	t_node	*new_node;

	if (!(new_node = create_elem(data)) || !deque)
		return (0);
	new_node->next = deque->front;
	if (deque->size == 0)
		deque->back = new_node;
	else
		deque->front->prev = new_node;
	deque->front = new_node;
	deque->size++;
	return (1);
}
