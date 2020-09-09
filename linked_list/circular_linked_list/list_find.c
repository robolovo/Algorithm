#include "list.h"

int	list_find(t_linked_list *list, void *data, int(*cmp)(void *data1, void *data2))
{
	t_node	*curr;
	int		index;
	int		size;

	size = (int)list->size;
	index = 0;
	if (list == 0 || (curr = list->head) == 0)
		return (-1);
	if (cmp)
	{
		while (index < size)
		{
			if ((*cmp)(data, curr->data) == 0)
				return (index);
			curr = curr->next;
			index++;
		}
	}	
	return (-1);
}
