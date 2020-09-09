#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node
{
	struct s_node	*next[10];
	bool			finish;
}				t_node;

typedef t_node	*t_trie[10];

t_node	*create_elem(void)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		return (0);
	for (int i = 0; i < 10; i++)
		node->next[i] = 0;
	node->finish = false;
	return (node);
}

t_trie	*trie_init(void)
{
	t_trie	*trie;

	if (!(trie = malloc(sizeof(t_trie))))
		return (0);
	for (int i = 0; i < 10; i++)
		(*trie)[i] = 0;
	return (trie);
}

bool	trie_find(t_trie *trie, char *number)
{
	t_node	*curr;
	int		i, j;

	if (!trie || !number || !number[0])
		return (false);
	j = number[0] - '0';
	curr = (*trie)[j];
	if (curr == NULL)
		return (false);
	if (curr->finish == true && curr->next[j] != NULL)
		return (false);
	i = 1;
	while (number[i])
	{
		j = number[i] - '0';
		if (curr->next[j] == NULL)
			return (false);
		curr = curr->next[j];
		if (curr->finish == true && curr->next[j] != NULL)
			return (false);
		i++;
	}
	return (true);
}

bool	trie_insert(t_trie *trie, char *number)
{
	t_node	*curr;
	int		i, j;

	if (!trie || !number || !number[0])
		return (false);
	j = number[0] - '0';
	if ((*trie)[j] == NULL)
		(*trie)[j] = create_elem();
	curr = (*trie)[j];
	if (curr->finish == true)
		return (false);
	i = 1;
	while (number[i])
	{
		j = number[i] - '0';	
		if (curr->next[j] == NULL)
			curr->next[j] = create_elem();
		curr = curr->next[j];
		if (curr->finish == true)
			return (false);
		i++;
	}
	curr->finish = true;
	return (true);
}


int main(void)
{
	t_trie	*trie;
	int 	t, n, i;
	char	*p_num[10001];
	bool	ret;
	int		flag;

	scanf("%d", &t);
	for (i = 0; i < 10001; i++)
		p_num[i] = malloc(sizeof(char) * 10);
	while (t--)
	{	
		trie = trie_init();
		ret = true;
		flag = 1;
		scanf("%d", &n);	
		for (i = 0; i < n; i++)
		{	
			scanf("%s", p_num[i]);
			ret = trie_insert(trie, p_num[i]);
		}
		for (i = 0; i < n; i++)
		{	
			ret = trie_find(trie, p_num[i]);
			if (ret == false)
				flag = 0;
		}
		if (flag == 0)
			printf("NO\n");
		else
			printf("YES\n");
		free(trie);
	}
	i = 0;
	while (p_num[i])
		free(p_num[i++]);
	return (0);
}
