#include "includes/list.h"

t_node	*list_get(t_node *begin_list, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		begin_list = begin_list->next;
		if (begin_list == NULL)
			return (0);
	}
	return (begin_list);
}
