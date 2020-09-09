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
	int				(*cmp)(int , int);
	unsigned int	size;
}					t_tree;

int	cmp(int a, int b)
{
	return (a - b);
}

t_tree *tree_init(int (*cmp)(int, int))
{
	t_tree	*tree;
	
	if (!(tree = (t_tree *)malloc(sizeof(t_tree))))
		return (0);
	tree->size = 0;
	tree->cmp = cmp;
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

int	tree_find(t_tree *tree, int data_ref)
{
	t_node	*curr;
	int		ret;

	if (!tree)
		return (0);
	curr = tree->root;
	while (curr != NULL)
	{
		if ((ret = tree->cmp(data_ref, curr->data)) == 0)
			return (1);
		else if (ret < 0)
			curr = curr->left;
		else
			curr = curr->right;
	}
	return (0);
}

int	main(void)
{	
	t_tree *tree;
	int	N, M, i;
	int	numbers[100001];
	int	to_find[100001];

	scanf("%d", &N);
	i = 1;
	while (i <= N)
		scanf("%d", &numbers[i++]);
	
	scanf("%d", &M);
	i = 1;
	while (i <= M)
		scanf("%d", &to_find[i++]);
	
	tree = tree_init(cmp);
	i = 1;
	while (i <= N)
		tree_insert(tree, numbers[i++]);
	
	i = 1;
	while (i <= M)
	{
		if (tree_find(tree, to_find[i]))
			printf("1\n");
		else
			printf("0\n");	
		i++;
	}
	return (0);
}
