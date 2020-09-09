#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node
{
	struct s_node	*next[126];
	bool			finish;
}				t_node;

typedef t_node	*t_trie[126];

t_node *create_elem(void)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		return (0);
	for (int i = 0; i < 126; i++)
		node->next[i] = 0;	
	node->finish = false;
	return (node);
}

t_trie	*trie_init(void)
{
	t_trie	*trie;

	if (!(trie = malloc(sizeof(t_trie))))
		return (0);
	for (int i = 0; i < 126; i++)
		(*trie)[i] = 0;			
	return (trie);
}

bool	trie_find(t_trie *trie, char *str)
{
	t_node	*curr;
	int		i;
	int		j;

	if (!trie || !str || !str[0])
		return (false);
	j = str[0];
	curr = (*trie)[j];
	if (!curr)
		return (false);
	i = 1;
	while (str[i])
	{
		j = str[i];
		if (curr->next[j] == NULL)
			return (false);
		curr = curr->next[j];
		i++;
	}
	if (curr->finish != true)
		return (false);	
	return (true);
}

bool	trie_insert(t_trie *trie, char *str)
{
	t_node	*curr;
	int		i;
	int		j;

	if (!trie || !str || !str[0])
		return (false);
	j = str[0];
	if ((*trie)[j] == NULL)
		(*trie)[j] = create_elem();
	curr = (*trie)[j];
	i = 1;
	while (str[i])
	{
		j = str[i];
		if (curr->next[j] == NULL)
			curr->next[j] = create_elem();
		curr = curr->next[j];
		i++;
	}
	curr->finish = true;
	return (true);
}

int main(void)
{
	t_trie	*trie;
	char	str[31];
	int		ret;
	int		count;

	trie = trie_init();
	while (scanf("%s", str) != EOF)
	{
		ret = trie_find(trie, str);
		if (ret != true)
		{		
			trie_insert(trie, str);
			count++;
		}
		else
			count++;
	}
	printf("%d\n", count);
	return (0);
}
