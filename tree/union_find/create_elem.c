#include "union_find.h"

t_node	*create_elem(void *data)
{
	t_node	*node;
	
	if (!(node = malloc(sizeof(t_node))))
		return (0);
	node->parent = 0;
	node->data = data;
	return (node);
}
