#ifndef TREE_H
# define TREE_H

# include <stdio.h>
# include <stdlib.h>

typedef struct	s_node
{
	void			*data;
	struct s_node	*left;
 	struct s_node	*right;
}					t_node;

typedef struct	s_binary_search_tree
{
 	t_node	*root;
 	int		(*cmp)(void *, void *);
 	int		size;
}			t_tree;

t_tree *tree_init(int (*cmp)(void *, void *));
t_node *create_elem(void *data);
int		tree_size(t_tree *tree);
t_node *tree_find(t_tree *tree, void *data_ref);
int 	tree_insert(t_tree *tree, void *data);
int 	tree_delete(t_tree *tree, void *data_ref, void (*free_data)(void *));
void 	free_tree(t_tree *tree, void (*free_data)(void *));

#endif
