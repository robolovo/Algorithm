#include "tree.h"

int	tree_insert(t_tree *tree, void *data)
{
	t_node	*new;
	t_node	*curr;
	t_node	*parent;
	int		ret;

	if (!tree || !(new = create_elem(data)))
		return (0);
	curr = tree->root;
	parent = NULL;
	while (curr)
	{
		if ((ret = tree->cmp(data, curr->data)) == 0)
			return (0);
		parent = curr;
		if (ret < 0)
			curr = parent->left;
		else
			curr = parent->right;
	}
	if (parent)
	{
		if (ret < 0)
			parent->left = new;
		else		
			parent->right = new;
	}
	else
		tree->root = new;	
	tree->size++;
	return (1);
}
/*
int cmp(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

void print_tree(int index, t_node *node)
{
	if (!node)
		return ;
	printf("#%d node : %d\n", index, *(int *)node->data);
	print_tree(index * 2, node->left);
	print_tree(index * 2 + 1, node->right);
}

int main(void)
{
	t_tree	*tree;
	int		*data;
	int		number;

	number = 10;
	data = malloc(sizeof(int) * (number + 1));
	for (int i = 0; i <= number; i++)
		data[i] = i;
	tree = tree_init(cmp);
	for (int i = 0; i<= number; i++)
		tree_insert(tree, &data[i]);
	print_tree(1, tree->root);
}*/
