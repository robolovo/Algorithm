#include "set.h"

int set_delete(t_hash_set *set, void *data, unsigned int data_size, void (*free_data)(void *))
{
	t_node	*curr;
	t_node	*prev;
	int hash;
	
	hash = get_hash(data, data_size);
	curr = set->set[hash];
	prev = 0;
	while (curr)
	{
		if (set->cmp(data, curr->data) == 0)
			break;
		prev = curr;
		curr = curr->next;
	}
	if (!curr)
		return (1);
	if (prev)
		prev->next = curr->next;
	else
		set->set[hash] = curr->next;
	free_data(curr->data);
	free(curr);
	set->size--;
	return (1);
}
