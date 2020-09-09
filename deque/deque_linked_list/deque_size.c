#include "deque.h"

int	deque_size(t_deque *deque)
{
	int	size;
	t_node *curr;

	if (!deque)
		return (0);
	curr = deque->front;
	size = 0;
	while (curr->next != 0)
	{
		curr = curr->next;
		size++;
	}
	return (size);
}
