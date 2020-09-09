#include "deque.h"

t_node	*deque_front(t_deque *deque)
{	
	if (!deque)
		return (0);
	return (deque->front);
}
