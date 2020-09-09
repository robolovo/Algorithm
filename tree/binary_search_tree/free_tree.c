#include "tree.h"

static void	free_tree_node(t_node *node, void (*free_data)(void *))
{
	if (!node || !free_data)
		return ;
	free_data(node->data);
	free_tree_node(node->left, free_data);
	free_tree_node(node->right, free_data);
	free(node);
}

void	free_tree(t_tree *tree, void (*free_data)(void *))
{
	if (!tree || !free_data)
		return ;
	free_tree_node(tree->root, free_data);
	free(tree);
}
