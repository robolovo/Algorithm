#include "deque.h"

void	free_deque(t_deque *deque, void(* free_data)(void *))
{
	if (!deque || !free_data)
		return ;
	deque_clear(deque, free_data);
	free(deque);
}
