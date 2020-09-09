#include "graph.h"

static void	add_queue(t_node *node, int *queue, int *last_index, bool *visited)
{
	while (node)
	{
		if (!visited[node->vertex])
		{
			visited[node->vertex] = true;
			queue[*last_index] = node->vertex;
			(*last_index)++;
		}
		node = node->next;
	}
}

void graph_traverse(t_graph *graph, void (*print_data)(void *))
{
	bool	*visited;	
	int 	*queue;
	int		vertex;
	int 	last;
	int 	first;
	int		i;

	if (!(visited = malloc(sizeof(bool) * graph->size)))
		return ;
	if (!(queue = malloc(sizeof(int) * (graph->size + 1))))
	{
		free(visited);
		return ;
	}
	i = 0;
	while (i < graph->size)
		visited[i++] = false;
	last = 1;
	first = 0;
	queue[0] = 0;
	visited[0] = true;
	while (first < last)
	{
		vertex = queue[first];
		last--;
		while (first < last)
		{
			queue[first] = queue[first + 1];
			first++;
		}
		first = 0;
		printf("%d번 vertex, data = ", vertex);
		print_data(graph->data[vertex]);
		add_queue(graph->list[vertex], queue, &last, visited);
	}
	free(visited);
	free(queue);
}
