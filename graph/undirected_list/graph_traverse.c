#include "graph.h"

void	stack_push(t_graph *graph, int *stack, int *index, int vertex, bool *visit)
{
	t_node	*curr;

	curr = graph->list[vertex];
	while (curr)
	{
		if (visit[curr->vertex] != true)
		{	
			(*index)++;
			stack[(*index)] = curr->vertex;
			visit[curr->vertex] = true;
		}
		curr = curr->next;
	}
}

void 	graph_traverse(t_graph *graph, void (*print_data)(void *))
{
	bool	*visit;
	int		*stack;
	int		i;
	int		vertex;

	if (!(visit = malloc(sizeof(bool) * graph->size)) ||
					!(stack = malloc(sizeof(int) * (graph->size + 1))))
		return ;
	i = 0;
	while (i < graph->size)
		visit[i++] = false;
	i = 1;
	stack[1] = 0;
	visit[0] = true;
	while (i > 0)
	{
		vertex = stack[i--];
		printf("%d번 vertex, data = ", vertex);
		print_data(graph->data[vertex]);
		stack_push(graph, stack, &i, vertex, visit);
	}
	free(stack);
	free(visit);
}
