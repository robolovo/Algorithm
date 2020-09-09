#include "graph.h"

void dfs(t_graph *graph, bool *visit, int vertex, void (*print_data)(void *))
{
	int i;

	if (visit[vertex] || vertex >= graph->size)
		return ;
	visit[vertex] = true;
	printf("%d번 vertex, data = ", vertex);
	print_data(graph->data[vertex]);
	for (i = 0; i < graph->size; i++)
	{
		if (graph->matrix[vertex][i] || !visit[vertex])
			dfs(graph, visit, i, print_data);
	}
}

void graph_traverse(t_graph *graph, void (*print_data)(void *))
{
	bool *visit;
	int i;

	if (!(visit = malloc(sizeof(bool) * graph->size)))
		return ;
	i = 0;
	while (i < graph->size)
	{
		visit[i] = false;
		i++;
	}
	dfs(graph, visit, 0, print_data);
	free(visit);
}
