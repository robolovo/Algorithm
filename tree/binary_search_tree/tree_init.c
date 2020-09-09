#include "tree.h"

t_tree *tree_init(int (*cmp)(void *, void *))
{
	t_tree	*tree;
	
	if (!(tree = (t_tree *)malloc(sizeof(t_tree))))
		return (0);
	tree->size = 0;
	tree->cmp = cmp;
	tree->root = 0;
	return (tree);
}
