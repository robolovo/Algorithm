#include "map.h"

t_hash_map	*map_init(void)
{	
	t_hash_map *map;
	int i;

	if (!(map = malloc(sizeof(t_hash_map))))
		return (0);
	map->size = 0;
	if (!(map->map = malloc(sizeof(t_node) * BIG_PRIME)))
	{
		free(map);
		return (0);
	}
	i = 0;
	while (i < BIG_PRIME)
	{
		map->map[i] = 0;
		i++;
	}
	return (map);
}
