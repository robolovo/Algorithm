#include "list.h"

int	list_size(t_node *begin_list)
{
	int size;
	t_node *curr;

	size = 0;
	curr = begin_list;
	while (begin_list)
	{
		curr = begin_list->next;
		size++;
	}
	return (size);	
}
