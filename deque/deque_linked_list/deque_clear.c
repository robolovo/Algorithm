#include "deque.h"

void	deque_clear(t_deque *deque, void(* free_data)(void *))
{
	t_node	*curr;
	t_node	*tmp;

	if (!deque || !free_data)
		return ;
	curr = deque->front;
	while (curr != 0)
	{
		tmp = curr;
		curr = curr->next;
		free_data(tmp->data);
		free(tmp);
		deque->size--;
	}
	deque->front = 0;
	deque->back = 0;
}

