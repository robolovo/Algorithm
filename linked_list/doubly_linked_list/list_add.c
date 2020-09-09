#include "list.h"

int	list_add(t_linked_list *list, int data, int n)
{
	int 	i;
	t_node	*curr;
	t_node	*new;

	if (list == 0 || n < 0)
		return (0);
	i = 0;
	new = create_elem(data);
	curr = list->head;
	while (1)
	{
		if (curr == 0)
		{
			new->prev = curr->prev;
			curr = new;
			return (data);
		}	
		if (i == n)
			break;
		curr = curr->next;
		i++;
	}
	curr->prev->next = new;
	new->prev = curr->prev;
	new->next = curr;
	curr->prev = new;
	return (data);
}
