#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				data;	
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

typedef struct s_tree
{
	t_node			*root;
	unsigned int 	size;
}					t_tree;

int	cmp(int a, int b)
{
	return (a - b);
}

t_tree *tree_init(void)
{
	t_tree	*tree;
	
	if (!(tree = (t_tree *)malloc(sizeof(t_tree))))
		return (0);
	tree->size = 0;
	tree->root = 0;
	return (tree);
}

t_node	*create_elem(int data)
{
	t_node *new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (0);
	new->data = data;
	new->right = 0;
	new->left = 0;
	return (new);
}

int	tree_insert(t_tree *tree, int data)
{
	t_node	*curr;
	t_node	*parent;
	t_node	*new;
	int		ret;

	new = create_elem(data);
	curr = tree->root;
	parent = 0;
	while (curr)
	{	
		parent = curr;
		ret = cmp(data, curr->data);
		if (ret == 0)
			return (0);
		else if (ret < 0)
			curr = curr->left;
		else
			curr = curr->right;	
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

void	postorder_traverse(t_node	*node)
{
	if (node == 0)
		return ;
	postorder_traverse(node->left);
	postorder_traverse(node->right);
	printf("%d\n", node->data);
}

int	main(void)
{
	t_tree	*tree;
	int		node;

	tree = tree_init();
	while (scanf("%d", &node) != EOF)
		tree_insert(tree, node);
	postorder_traverse(tree->root);
	return (0);
}
