#include "graph.h"

void	free_list(t_node *curr)
{
	t_node	*temp;

	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
}

void	free_graph(t_graph *graph, void (*free_data)(void *))
{
	int	i;

	if (!graph || !free_data)
		return ;
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
