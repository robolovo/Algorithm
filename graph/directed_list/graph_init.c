#include "graph.h"

t_graph	*graph_init(unsigned int size)
{
	t_graph	*graph;
	int	i;
	int	j;

	if (!(graph = malloc(sizeof(t_graph))))
		return (0);
	graph->size = size;
	if (!(graph->data = malloc(sizeof(void *) * size)))
	{
		free(graph);
		return (0);
	}
	if (!(graph->list = malloc(sizeof(t_node *) * size)))
	{
		free(graph->data);
		free(graph);
		return (0);
	}
	i = 0;
	while (i < size)
	{
		graph->data[i] = 0;
		graph->list[i] = 0;
		i++;
	}
	return (graph);
}
