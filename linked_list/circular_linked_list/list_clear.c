#include "list.h"

void	list_clear(t_linked_list *list, void(*free_data)(void *))
{
	int		size;

	size = (int)list->size;
	if (list == 0)
		return ;
	if (free_data)
		while (size--)
			list_remove(list, 0 ,free_data);
	return ;
}
