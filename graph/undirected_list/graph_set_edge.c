#include "graph.h"

bool remove_list(t_node **head, unsigned int vertex)
{
	t_node *prev;
	t_node *curr;

	if (!head)
		return (false);
	if (!(*head))
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

bool add_list(t_node **head, t_node *new)
{
	t_node	*curr;
	t_node	*prev;

	if (!head || !new)
		return (false);
	if (*head == 0)
	{
		*head = new;
		return (true);
	}
	curr = *head;
	prev = 0;
	while (curr)
	{
		if (new->vertex >= curr->vertex)
			break;
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

bool graph_set_edge(t_graph *graph, unsigned int vertex1, unsigned int vertex2, bool state)
{
	t_node	*new1;
	t_node	*new2;

	if (!(new1 = create_elem(vertex1)) || !(new2 = create_elem(vertex2)))
		return (false);
	if (find_list(graph->list[vertex1], vertex2) == state)
		return (true);
	if (state)
	{
		if (!add_list(&(graph->list[vertex1]), new2) || 
						!add_list(&(graph->list[vertex2]), new1))
		{
			free(new1);
			free(new2);
			return (false);
		}
	}
	else
	{
		if (!remove_list(&(graph->list[vertex1]), vertex2) || 
						!remove_list(&(graph->list[vertex2]), vertex1))
			return (false);
	}
	return (true);
}
