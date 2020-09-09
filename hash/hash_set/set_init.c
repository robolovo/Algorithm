#include "set.h"

t_hash_set	*set_init(int (*cmp)(void *, void *))
{
	t_hash_set	*set;
	int			i;

	if (!(set = malloc(sizeof(t_hash_set))))
		return (0);
	set->size = 0;
	set->cmp = cmp;
	if (!(set->set = malloc(sizeof(t_node) * BIG_PRIME)))
	{
		free(set);
		return (0);
	}
	i = 0;
	while (i < BIG_PRIME)
	{
		set->set[i] = 0;
		i++;
	}
	return (set);
}
