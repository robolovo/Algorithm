#include "deque.h"

t_node	*deque_pop_back(t_deque *deque)
{
	t_node	*rtn;

	if (!deque || deque->size == 0)
		return (0);
	rtn = deque->back;
	deque->back = rtn->prev;
	deque->size--;
	if (deque->size == 0)
		deque->front = 0;
	else 
		deque->back->next = 0;
	return (rtn);
}
