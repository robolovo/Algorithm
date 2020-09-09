#include "list.h"

void	list_foreach(t_linked_list *list, void (*f)(void *))
{
	t_node	*curr;
	int 	size;

	if (list == 0)
		return ;
	if (f)
	{
		if ((curr = list->head))
		{
			size = (int)list->size;
			while (size--)
			{
				(*f)(curr->data);
				curr = curr->next;
			}
		}
	}
}
