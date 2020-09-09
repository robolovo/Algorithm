#include "deque.h"

t_deque *deque_init(void)
{
	t_deque	*deque;

	if (!(deque = (t_deque *)malloc(sizeof(t_deque))))
		return (0);
	deque->size = 0;
	deque->front = 0;
	deque->back = 0;
	return (deque);
}
