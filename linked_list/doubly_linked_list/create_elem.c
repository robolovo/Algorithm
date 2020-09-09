#include "list.h"

t_node	*create_elem(int data)
{
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (0);
	new->data = data;
	new->prev = 0;
	new->next = 0;
	return (new);
}
