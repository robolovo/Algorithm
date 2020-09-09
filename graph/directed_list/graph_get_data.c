#include "graph.h"

void	*graph_get_data(t_graph *graph, unsigned int vertex)
{
	if (!graph || vertex >= graph->size)
		return (0);
	return (graph->data[vertex]);
}
