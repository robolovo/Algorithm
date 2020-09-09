#include "set.h"

int set_exists(t_hash_set *set, void *data, unsigned int data_size)
{
	t_node	*curr;
	int	hash;

	if (!set)
		return (0);
	hash = get_hash(data, data_size);
	curr = set->set[hash];
	while (curr)
	{
		if (set->cmp(data, curr->data) == 0)
			return (1);
		curr = curr->next;
	}
	return (0);
}
