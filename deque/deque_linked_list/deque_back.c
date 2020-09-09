#include "deque.h"

t_node	*deque_back(t_deque *deque)
{
	if (!deque)
		return (0);
	return (deque->back);
}
