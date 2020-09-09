#include "graph.h"

static void free_list(t_node *head)
{
	t_node	*temp;
	t_node	*curr;

	curr = head;
	while (curr)
	{
		temp = curr;	
		curr = curr->next;
		free(temp);
	}
}

void	free_graph(t_graph *graph, void (*free_data)(void *))
{
	int i;

	i = 0;
	while (i < graph->size)
	{
		free_data(graph->data[i]);
		free_list(graph->list[i]);
		i++;
	}
	free(graph->data);
	free(graph->list);
	free(graph);
}
