#include "list.h"

static int	ABS(int nb)
{
	if (nb < 0)
		nb = nb * -1;
	return (nb);
}

static t_node	*get_nth_list(t_linked_list *list, int n)
{
	t_node	*curr;
	int		index;

	curr = list->head;
	index = ABS(n) % list->size;
	if (n < 0)
		while (index--)
			curr = curr->prev;
	else
		while (index--)
			curr = curr->next;
	return (curr);
}

void	list_remove(t_linked_list *list, int n, void(*free_data)(void *))
{
	t_node	*target;

	if (list == 0 || list->head == 0)
		return ;
	if (free_data)
	{
		if ((target = get_nth_list(list, n)))
		{		
			target->prev->next = target->next;
			target->next->prev = target->prev;
			if (n == 0)
				list->head = target->next;
			(*free_data)(target->data);
			free(target);
			list->size--;
		}
	}
	return ;
}
