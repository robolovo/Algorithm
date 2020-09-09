#include "union_find.h"
		
t_node	*find(t_node *node)
{
	if (!node)
		return (0);
	if (!node->parent)
		return (node);
	node->parent = find(node->parent);
	return (node->parent);
}
