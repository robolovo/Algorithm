#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int	key;
}				t_node;

typedef struct s_set
{
	t_node	**set;
}			t_set;

t_set	*set_init(void)
{
	t_set *set;
	int	i;

	if (!(set = malloc(sizeof(t_set))))
		return (0);
	if (!(set->set = malloc(sizeof(t_node *) * 100001)))
	{
		free(set);
		return (0);
	}
	i = 0;
	while (i < 100001)
	{
		set->set[i] = 0;
		i++;
	}
	return (set);
}

t_node	*create_elem(int key)
{
	t_node	*new;

	if (!(new = malloc(sizeof(t_node))))
		return (0);
	new->key = key;
	return (new);
}

int main(void)
{
	int N, M, i, to_find;
	int key, hash;	
	t_set *set;

	scanf("%d", &N);
	set = set_init();
	hash = 0;
	i = 0;
	while (i < N)
	{
		scanf("%d", &key);
		hash = key;
		set->set[hash] = create_elem(key);
		i++;
	}

	scanf("%d", &M);
	i = 0;
	while (i < M)
	{
		scanf("%d", &to_find);
		if (set->set[to_find])
		{
			if (set->set[to_find]->key == to_find)
				printf("1\n");
			else
				printf("0\n");
		}
		else
			printf("0\n");
		i++;
	}
	return (0);
}
