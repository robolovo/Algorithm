#include "set.h"

t_node	*create_elem(void *data)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		return (0);
	node->data = data;
	node->next = 0;
	return (node);
}
