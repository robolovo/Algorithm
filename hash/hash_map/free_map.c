#include "map.h"

void	clear(t_node *node, void (*free_data)(void *))
{
	t_node *temp;	
	while (node)
	{
		temp = node;
		node = node->next;
		free_data(temp->value);
		free(temp);
	}
}

void free_map(t_hash_map *map, void (*free_data)(void *))
{
	int i;
	int	flag;

	i = 0;
	while (i < BIG_PRIME)
	{
		flag = 1;
		if (map->map[i] == 0)
			flag = 0;
		if (flag)
			clear(map->map[i], free_data);
		i++;
	}
	free(map->map);
	free(map);
}
