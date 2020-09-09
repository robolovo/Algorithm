#include "graph.h"

bool	find_list(t_node *head, unsigned int vertex)
{
	t_node	*curr;

	if (!head)
		return (false);
	curr = head;
	while (curr)
	{
		if (curr->vertex == vertex)
			return (true);
		curr = curr->next;
	}
	return (false);
}
