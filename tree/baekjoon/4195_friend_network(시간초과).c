#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node
{
	struct s_node	*parent;
	char			*name;
}				t_node;

typedef struct	s_trie_node
{
 	struct s_trie_node	*next[58];
 	bool				finish;
	int					index;
}						t_trie_node;

typedef t_trie_node	*t_trie[58];

t_trie *trie_init(void)
{
	t_trie	*trie;
	int		i;

	if (!(trie = (t_trie *)malloc(sizeof(t_trie))))
		return (0);
	i = 0;
	while (i < 58)
	{
		(*trie)[i] = 0;
		i++;
	}
	return (trie);
}

t_trie_node	*create_elem(void)
{
	t_trie_node	*node;
	int			i;

	if (!(node = malloc(sizeof(t_trie_node))))
		return (0);
	i = 0;
	while (i < 58)
	{
		node->next[i] = 0;
		i++;
	}
	node->finish = false;
	node->index = -1;
	return (node);
}

int	trie_insert(t_trie *trie, char *str, int index)
{
	t_trie_node	*curr;
	int		i, j;

	if (!trie || !str || str[0] == '\0')
		return (-1);
	j = str[0] - 'A';
	if ((*trie)[j] == NULL)
		(*trie)[j] = create_elem();
	curr = (*trie)[j];
	i = 1;
	while (str[i])
	{
		j = str[i] - 'A';
		if (curr->next[j] == NULL)
			curr->next[j] = create_elem();
		curr = curr->next[j];
		i++;
	}
	curr->finish = true;
	if (curr->index < 0)
		curr->index = index;
	return (curr->index);
}

t_node	*create_node(char *name)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		return (0);
	node->parent = 0;
	node->name = name;
	return (node);
}

t_node	*find(t_node *node)
{
	if (!node)
		return (0);
	if (!node->parent)
		return (node);
	node->parent = find(node->parent);
	return (node->parent);
}

bool	is_disjoint(t_node *node1, t_node *node2)
{
	if (!node1 || !node2)
		return (true);
	if (find(node1) == find(node2))
		return (false);
	return (true);
}

t_node	*union_func(t_node *node1, t_node *node2)
{
	t_node	*root1;
	t_node	*root2;

	root1 = find(node1);
	root2 = find(node2);
	if (!node1 || !node2)
		return (0);
	if (!is_disjoint(node1, node2))
		return (find(node1));
	return (root2->parent = root1);
}

int	count_path(t_node *node)
{
	int count;

	count = 0;
	if (!node)
		return (0);
	if (!node->parent)
		return (1);
	while (node)
	{
		node = node->parent;
		count++;
	}
	return (count - 1);
}

int	main(void)
{
	t_trie	*trie;	
	t_node	*node[50000];	
	int 	T, F, i, j, index1, index2, count;
	char	name1[21], name2[21];

	scanf("%d", &T);
	while (T--)
	{
		i = 0;
		trie = trie_init();
		scanf("%d", &F);
		while (F--)
		{
			count = 0;	
			scanf("%s %s", name1, name2);
			getchar();
			index1 = trie_insert(trie, name1, i);
			if (node[index1] == NULL && index1 >= 0)
			{		
				node[index1] = create_node(name1);
				i++;
			}
			index2 = trie_insert(trie, name2, i);
			if (node[index2] == NULL && index2 >= 0)
			{
				node[index2] = create_node(name2);
				i++;
			}
			union_func(node[index1], node[index2]);
			j = 0;
			while (j < i)
				count += count_path(node[j++]);
			printf("%d\n", count);
		}
		free(trie);
	}
	return (0);
}
