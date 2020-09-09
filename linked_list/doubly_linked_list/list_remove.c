#include "list.h"

int	list_remove(t_linked_list *list, int n)
{
	int		i;
	t_node	*curr;

	if (list == 0 || list->size >= n ||n < 0)
		return (0);
	i = 0;
	curr = list->head;
	while (1)
	{
		if (i == n)
			break;
		curr = curr->next;
		i++;
	}
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	free(curr);
	list->size--;
	return (1);
}
