#include "graph.h"

bool	graph_set_data(t_graph *graph, unsigned int vertex, void *data)
{
	if (!graph || vertex >= graph->size)
		return (false);
	graph->data[vertex] = data;
	return (true);
}
