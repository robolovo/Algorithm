#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node
{
	struct s_node	*next[26];
	bool			finish;
}			t_node;

typedef t_node	*t_trie[26];

t_node	*create_elem(void)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (0);
	for (int i = 0; i < 26; i++)
		node->next[i++] = 0;
	node->finish = false;
	return (node);
}

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

int	main(void)
{
	t_trie	*trie;	
	int		N, M, i;
	char	*str[10001];
	char	to_find[501];
	int		count = 0;
	bool	ret;

	i = 0;
	while (i < 10001)
	{
		str[i] = malloc(sizeof(char) * 501);
		i++;
	}
	scanf("%d %d", &N, &M);
	getchar();
	trie = trie_init();
	
	i = 0;
	while (i < N)
	{
		scanf("%s", str[i]);
		i++;
	}
	
	i = 0;
	while (i < N)
	{	
		trie_insert(trie, str[i]);
		i++;
	}

	i = 0;
	while (i < M)
	{
		scanf("%s", to_find);
		ret = trie_find(trie, to_find);
		if (ret == true)
			count++;
		i++;
	}
	printf("%d\n", count);
}
