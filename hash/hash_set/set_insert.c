#include "set.h"

int set_insert(t_hash_set *set, void *data, unsigned int data_size)
{
	t_node	*curr;
	int hash;

	if (!set)
		return (0);
	hash = get_hash(data, data_size);
	if (!set->set[hash])
	{
		set->set[hash] = create_elem(data);
		set->size++;
		return (1);
	}
	curr = set->set[hash];
	while (curr)
	{
		if (set->cmp(data, curr->data) == 0)
			return (0);
		curr = curr->next;
	}
	curr = create_elem(data);
	set->size++;
	return (1);
}
