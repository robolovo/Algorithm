#include "graph.h"

bool	graph_set_edge(t_graph *graph, unsigned int vertex1, unsigned int vertex2, bool state)
{
	if (!graph || vertex1 >= graph->size || vertex2 >= graph->size)
		return (false);
	graph->matrix[vertex1][vertex2] = state;
	graph->matrix[vertex2][vertex1] = state;
	return (true);
}
