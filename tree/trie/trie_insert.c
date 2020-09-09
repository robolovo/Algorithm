#include "trie.h"

bool	trie_insert(t_trie *trie, char *str)
{
	t_node	*curr;
	int		i;
	int		j;

	if (!trie || !str || str[0] == '\0')
		return (false);
	j = str[0] - 'a';
	if ((*trie)[j] == NULL)
		(*trie)[j] = create_elem();
	curr = (*trie)[j];
	i = 1;
	while (str[i])
	{
		j = str[i] - 'a';	
		if (curr->next[j] == NULL)
			curr->next[j] = create_elem();
		curr = curr->next[j];
		i++;
	}
	curr->finish = true;
	return (true);
}
