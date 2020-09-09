#include "trie.h"

bool	trie_find(t_trie *trie, char *str)
{
	t_node	*curr;
	int	i;
	int	j;

	if (!trie || !str || str[0] == '\0')
		return (false);
	j = str[0] - 'a';
	curr = (*trie)[j];
	if (curr == NULL)
		return (false);
	i = 1;
	while (str[i])
	{
		j = str[i] - 'a';
		if (curr->next[j] == NULL)
			return (false);
		curr = curr->next[j];
		i++;
	}
	if (curr->finish != true)
		return (false);
	return (true);
}
