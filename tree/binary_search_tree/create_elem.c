#include "tree.h"

t_node	*create_elem(void *data)
{
	t_node *new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (0);
	new->data = data;
	new->right = 0;
	new->left = 0;
	return (new);
}
