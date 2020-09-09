#include "graph.h"

bool graph_get_edge(t_graph *graph, unsigned int start, unsigned int end)
{
	if (!graph || start >= graph->size || end >= graph->size)
		return (false);
	return (find_list(graph->list[start], end));
}
