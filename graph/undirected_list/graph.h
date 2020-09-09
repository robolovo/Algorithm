#ifndef GRAPH_H
# define GRAPH_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct	s_node
{
	unsigned int	vertex;
	struct s_node	*next;
}				t_node;

typedef struct	s_graph
{
	unsigned int	size;
	void			**data;
	t_node			**list;
}				t_graph;

t_graph					*graph_init(unsigned int size);
bool					graph_set_data(
							t_graph *graph, unsigned int vertex, void *data);
bool					graph_set_edge(t_graph *graph,
							unsigned int vertex1, unsigned int vertex2, bool state);
void					*graph_get_data(t_graph *graph, unsigned int vertex);
bool					graph_get_edge(t_graph *graph,
							unsigned int vertex1, unsigned int vertex2);
void					free_graph(t_graph *graph, void (*free_data)(void *));
void					graph_traverse(t_graph *graph,
							void (*print_data)(void *));
t_graph					*make_graph(void);
t_node					*create_elem(unsigned int vertex);
bool 					find_list(t_node *head, unsigned int vertex);

#endif
