#include "trie.h"

t_trie *trie_init(void)
{
	t_trie	*trie;
	int		i;

	if (!(trie = (t_trie *)malloc(sizeof(t_trie))))
		return (0);
	i = 0;
	while (i < 26)
	{
		(*trie)[i] = 0;
		i++;
	}
	return (trie);
}
