#include "map.h"

int map_insert(t_hash_map *map, const char *key, void *value)
{
	t_node *curr;	
	int hash;

	hash = get_hash(key);
	if (!map->map[hash])
	{
		map->map[hash] = create_elem(key, value);
		map->size++;
		return (1);
	}
	curr = map->map[hash];
	while (curr)
	{
		if (ft_strcmp(key, curr->key) == 0)
			return (0);
		curr = curr->next;
	}
	curr = create_elem(key, value);
	map->size++;
	return (1);
}
