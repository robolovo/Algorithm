#include "queue.h"

t_node	*create_elem(void *data)
{
	t_node	*new_node;

	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
		return (0);
	new_node->data = data;
	new_node->next = 0;
	return (new_node);
}
