#include "union_find.h"

bool	is_disjoint(t_node *node1, t_node *node2)
{
	if (!node1 || !node2)
		return (true);
	if (find(node1) == find(node2))
		return (false);
	return (true);
}
