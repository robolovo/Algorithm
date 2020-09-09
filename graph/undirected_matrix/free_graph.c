#include "graph.h"

void	free_graph(t_graph *graph, void (*free_data)(void *))
{
	int i;

	if (!graph || !free_data)
		return ;
	i = 0;
	while (i < graph->size)
	{
		free_data(graph->data[i]);
		free(graph->matrix[i]);
		i++;
	}
	free(graph->data);
	free(graph->matrix);
	free(graph);
}
