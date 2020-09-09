#include "graph.h"

t_graph *graph_init(unsigned int size)
{
	t_graph *graph;
	int		i, j;

	if (!(graph = malloc(sizeof(t_graph))))
		return (0);
	graph->size = size;
	if (!(graph->data = malloc(sizeof(void *) * size)))
	{
		free(graph);
		return (0);
	}
	if (!(graph->matrix = malloc(sizeof(bool *) * size)))
	{
		free(graph->data);
		free(graph);
		return (0);
	}
	i = 0;
	while (i < size)
	{
		if (!(graph->matrix[i] = malloc(sizeof(bool) * size)))
		{
			j = 0;
			while (j < i)
			{
				free(graph->matrix[j]);
				j++;
			}
			free(graph->matrix);
			free(graph->data);
			free(graph);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		graph->data[i] = 0;
		j = 0;
		while (j < size)
		{
			graph->matrix[i][j] = false;
			j++;
		}
		i++;
	}
	return (graph);
}
