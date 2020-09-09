#include "graph.h"
#include <string.h>

t_graph	*make_graph(void)
{
	t_graph *graph;
	int i;
	char	**str;

	if (!(graph = graph_init(5)) || !(str = malloc(sizeof(char *) * 5)))
		return (0);
	str[0] = strdup("a0");
	str[1] = strdup("b1");
	str[2] = strdup("c2");
	str[3] = strdup("d3");
	str[4] = strdup("e4");
	i = 0;
	while (i < 5)
	{
		graph_set_data(graph, i, str[i]);
		i++;
	}
	graph_set_edge(graph, 0, 1, true);
	graph_set_edge(graph, 0 ,3, true);
	graph_set_edge(graph, 1, 2, true);
	graph_set_edge(graph, 1, 3, true);
	graph_set_edge(graph, 3, 4, true);
	return (graph);
}
