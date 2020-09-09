#include "list.h"

void	list_clear(t_linked_list *list)
{
	t_node	*curr;
	t_node	*tmp;

	curr = list->head;
	list->head = 0;
	list->tail = 0;
	list->size = 0;
	while (curr != 0)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}
