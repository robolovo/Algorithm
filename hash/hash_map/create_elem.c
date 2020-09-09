#include "map.h"

t_node	*create_elem(const char *key, void *value)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		return (0);
	node->key = key;
	node->value = value;
	node->next = 0;
	return (node);
}
