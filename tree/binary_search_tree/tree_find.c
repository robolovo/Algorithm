#include "tree.h"

t_node	*tree_find(t_tree *tree, void *data_ref)
{
	t_node	*curr;
	int		ret;

	if (!tree)
		return (0);
	curr = tree->root;
	while (curr != NULL)
	{
		if ((ret = tree->cmp(data_ref, curr->data)) == 0)
			return (curr);
		else if (ret < 0)
			curr = curr->left;
		else
			curr = curr->right;
	}
	return (0);
}
