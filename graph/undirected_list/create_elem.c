#include "graph.h"

t_node	*create_elem(unsigned int vertex)
{
	t_node *new;

	if (!(new = malloc(sizeof(t_node))))
		return (0);
	new->vertex = vertex;
	new->next = 0;
	return (new);
}
