#include "deque.h"

t_node *deque_pop_front(t_deque *deque)
{
	t_node	*rtn;

	if (!deque || deque->size == 0)
		return (0);
	rtn = deque->front;
	deque->front = rtn->next;
	deque->size--;
	if (deque->size == 0)
		deque->back = 0
	else
		deque->front->prev = 0;
	return (rtn);
}
