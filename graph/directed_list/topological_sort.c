#include "graph.h"

static void	list_add(t_node **head, t_node *new)
{
	if ((*head)->next == 0)
		(*head)->next = new;
	else
	{
		new->next = (*head)->next;
		(*head)->next = new;
	}
}

static void	dfs(t_graph *graph, t_node *node, bool *visited, t_node **sorted)
{
	if (visited[node->vertex] || !(node->next))
		return ;
	printf("c\n");
	visited[node->vertex] = true;

	while (1)
	{
		if (	
		dfs(graph, node->next, visited, sorted);
	}
	printf("d\n");
	//list_add(sorted, node);
}

void	topological_sort(t_graph *graph)
{
	bool 	*visited;
	t_node	**sorted;
	t_node	*curr;
	int		i;

	if (!(sorted = malloc(sizeof(t_node *) * 10)))
		return ;
	if (!(visited = malloc(sizeof(bool) * graph->size)))
		return ;
	i = 0;
	while (i < graph->size)
		visited[i++] = false;
	i = 0;
	while (i < graph->size)
	{
		printf("g\n");
		dfs(graph, graph->list[i], visited, sorted);
		i++;
	}
	curr = sorted;
	while (curr)
	{
		printf("%d ", curr->vertex);
		curr = curr->next;
	}
	printf("\n");
}

