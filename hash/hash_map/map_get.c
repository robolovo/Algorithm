#include "map.h"

void *map_get(t_hash_map *map, const char *key)
{
	t_node	*curr;
	int		 hash;

	hash = get_hash(key);
	curr = map->map[hash];
	while (curr)
	{
		if (ft_strcmp(key, curr->key) == 0)
			return (curr->value);
		curr = curr->next;
	}
	return (0);
}
