#include "map.h"

void *map_delete(t_hash_map *map, const char *key)
{
	t_node 	*curr;	
	t_node 	*prev;
	void	*rtn;
	int 	hash;

	hash = get_hash(key);
	curr = map->map[hash];
	prev = 0;
	while (curr)
	{
		if (ft_strcmp(key, curr->key) == 0)
			break;
		prev = curr;
		curr = curr->next;
	}
	if (!curr)
		return (0);
	if (prev)
		prev->next = curr->next;
	else
		map->map[hash] = curr->next;
	rtn = curr->value;
	free(curr);
	map->size--;
	return (rtn);
}
