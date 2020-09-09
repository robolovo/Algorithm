#include "graph.h"

static bool remove_list(t_node **head, unsigned int vertex)
{
	t_node	*curr;
	t_node	*prev;

	if (*head == 0)
		return (true);
	curr = *head;
	prev = 0;
	while (curr)
	{
		if (curr->vertex == vertex)
			break;
		prev = curr;
		curr = curr->next;
	}
	if (!curr)
		return (true);
	if (!prev)
		*head = curr->next;
	else
		prev->next = curr->next;
	free(curr);
	return (true);
}

static bool	add_list(t_node **head, t_node *new)
{
	t_node	*curr;
	t_node	*prev;

	if (*head == 0)
	{
		*head = new;
		return (true);
	}
	curr = *head;
	prev = 0;
	while (curr && new->vertex > curr->vertex)
	{
		prev = curr;
		curr = curr->next;
	}
	if (!prev)
		*head = new;
	else
		prev->next = new;
	new->next = curr;
	return (true);
}

bool	graph_set_edge(t_graph *graph, unsigned int start, unsigned int end, bool state)
{
	t_node	*new;
		
	if (!graph || start >= graph->size || end >= graph->size)
		return (false);
	if (find_list(graph->list[start], end) == state)
		return (true);
	if (!(new = create_elem(end)))
		return (false);
	if (state)
	{
		if (!(add_list(&(graph->list[start]), new)))
		{
			free(new);
			return (false);
		}
	}
	else
	{
		if (!(remove_list(&(graph->list[start]), end)))
			return (false);
	}
	return (true);
}
