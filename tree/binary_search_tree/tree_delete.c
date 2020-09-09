#include "tree.h"

int tree_delete(t_tree *tree, void *data_ref, void (* free_data)(void *))
{
	t_node	*curr;
	t_node	*parent;
	t_node	*child;
	t_node	*sub_curr;
	t_node 	*sub_parent;
	int		ret;

	if (!tree || !free_data || tree->size == 0)
		return (0);
	curr = tree->root;
	parent = 0;
	while (curr)
	{
		if (!(ret = tree->cmp(data_ref, curr->data)))
			break;
		parent = curr;
		curr = (ret < 0) ? curr->left : curr->right;
	}
	if (!curr)
		return (0);
	//The node that is going to be deleted has no sub tree.(terminal node)
	if (curr->left == 0 && curr->right == 0)
	{
		if (parent)
		{	
			if (parent->left == curr)
				parent->left = 0;
			else
				parent->right = 0;
		}
		else
			tree->root = 0;
		free_data(curr->data);
	}	
	//The node that is going to be deleted has one sub tree.		
	else if (curr->left == 0 || curr->right == 0)
	{
		child = (curr->left != 0) ? curr->left : curr->right;
		if (parent)
		{
			if (parent->left == curr)
				parent->left = child;
			else
				parent->right = child;
		}	
		else
			tree->root = child;
		free_data(curr->data);
	}	
	//The node that is going to be deleted has two sub trees.		
	else
	{
		sub_parent = curr;
		sub_curr = curr->right;
		while (sub_curr->left)
		{	
			sub_parent = sub_curr;	
			sub_curr = sub_curr->left;
		}
		if (sub_parent->left == sub_curr)
			sub_parent->left = sub_curr->right;
		else
			sub_parent->right = sub_curr->right;
		free_data(curr->data);
		curr->data = sub_curr->data;
		curr = sub_curr;
	}
	free(curr);
	tree->size--;
	return (1);
}

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

void free_data(void *a)
{
	printf("free data %d\n", *(int *)a);
}

int main(void)
{
	t_tree	*tree;
	int		data[101];
	
	for (int i = 1; i <= 100; i++)
		data[i] = i;
	tree = tree_init(cmp);
	tree_insert(tree, &data[1]);
	tree_insert(tree, &data[5]);
	tree_insert(tree, &data[3]);
	tree_insert(tree, &data[92]);
	tree_insert(tree, &data[33]);
	tree_insert(tree, &data[77]);
	tree_insert(tree, &data[29]);
	tree_delete(tree, &data[33], free_data);
	print_tree(1, tree->root);
}
