#include "trie.h"

t_node	*create_elem(void)
{
	t_node	*node;
	int		i;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (0);
	i = 0;
	while (i < 26)
	{
		node->next[i] = 0;
		i++;
	}
	node->finish = false;
	return (node);
}
