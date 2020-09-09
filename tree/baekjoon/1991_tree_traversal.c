#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	char			key;	
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

typedef struct s_tree
{
	t_node	*root;
}				t_tree;

t_tree *tree_init()
{
	t_tree *tree;

	if (!(tree = malloc(sizeof(t_tree))))
		return (0);
	tree->root = 0;
	return (tree);
}

t_node	*create_elem(char key)
{
	t_node *new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (0);
	new->key = key;
	new->right = 0;
	new->left = 0;
	return (new);
}

t_node	*find_node(t_node *node, char key)
{
	t_node *left;
	t_node *right;
	
	if (node == 0)
		return (0);
	if (node->key == key)
		return (node);
	if ((left = find_node(node->left, key)) != 0)
		return (left);
	if ((right = find_node(node->right, key)) != 0)
		return (right);
	return (0);
}

void	preorder_traverse(t_node *node)
{
	if (node == NULL)
        return;
    printf("%c", node->key);
    preorder_traverse(node->left);
    preorder_traverse(node->right);
}

void	inorder_traverse(t_node *node)
{
	if (node == NULL)
        return;
    inorder_traverse(node->left);
    printf("%c", node->key);
    inorder_traverse(node->right);
}

void	postorder_traverse(t_node *node)
{
	if (node == NULL)
        return;
    postorder_traverse(node->left);
    postorder_traverse(node->right);
    printf("%c", node->key);
}	

int	main(void)
{
	t_tree 	*tree;	
	t_node	*curr;
	int		N;
	char	p_key;
	char	left_key;
	char	right_key;
	char	root_key = 'A';
	int		ret;

	scanf("%d", &N);
	getchar();
	tree = tree_init();
	tree->root = create_elem(root_key);
	curr = tree->root;
	while (N--)
	{
		scanf("%c %c %c", &p_key, &left_key, &right_key);
		getchar();
		curr = find_node(tree->root, p_key);
		if (left_key != '.')
			curr->left = create_elem(left_key);
		if (right_key != '.')
			curr->right = create_elem(right_key);
	}
	preorder_traverse(tree->root);
	printf("\n");
	inorder_traverse(tree->root);
	printf("\n");
	postorder_traverse(tree->root);
	printf("\n");
	return (0);
}
