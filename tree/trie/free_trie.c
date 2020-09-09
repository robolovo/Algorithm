#include "trie.h"

void	free_elem(t_node *node)
{
	int i;

	if (!node)
		return ;
	i = 0;
	while (i < 26)
	{
		free_elem(node->next[i]);
		i++;
	}
	free(node);
}

void	free_trie(t_trie *trie)
{
	int     i;

	if (!trie || !(*trie))
		return ;
	i = 0;
	while (i < 26)
	{
		free_elem((*trie)[i]);
		i++;
	}
	free(trie);
}
