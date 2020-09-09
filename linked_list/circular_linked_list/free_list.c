#include "list.h"

void	free_list(t_linked_list *list, void(*free_data)(void *))
{
	t_node	*curr;
	
	if (list == 0 || list->head == 0)
		return ;
	curr = list->head;
	while (list->size--)
	{
		(*free_data)(curr->data);
		curr = curr->next;
	}
	free(list);
}
