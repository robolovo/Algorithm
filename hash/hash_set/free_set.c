#include "set.h"

static	void	lst_clear(t_node *node, void (*free_data)(void *))
{
	t_node *temp;

	while (node)
	{
		temp = node;
		node = node->next;
		free_data(temp->data);
		free(temp);
	}
}

void	free_set(t_hash_set *set, void (*free_data)(void *))
{
	int i;
	int flag;

	while (i < BIG_PRIME)
	{
		flag = 1;	
		if (!set->set[i])
			flag = 0;
		if (flag)
			lst_clear(set->set[i], free_data);
		i++;
	}
	free(set->set);
	free(set);
}
