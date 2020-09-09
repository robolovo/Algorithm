#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MOD 1000003

typedef struct s_node
{
	char			*key;
	struct s_node	*next;
}				t_node;

typedef struct s_map
{
	int	 size;
	t_node		**map;
}				t_map;

t_node	*create_elem(char *name)
{
	t_node	*new;

	if (!(new = malloc(sizeof(t_node))))
		return (0);
	new->key = strdup(name);
	new->next = 0;
	return (new);
}

t_map	*map_init(void)
{
	t_map *map;

	if (!(map = malloc(sizeof(t_map))))
		return (0);
	map->size = 0;
	if (!(map->map = malloc(sizeof(t_node) * MOD)))
	{
		free(map);
		return (0);
	}
	for (int i = 0; i < MOD; i++)
		map->map[i] = 0;
	return (map);
}

long long get_hash(char *key)
{
	long long hash = 0, power = 1;
	int i, len;

	i = 0;
	len = strlen(key);
	while (i < len)
	{
		hash = (hash + power * (key[i] - 'A' + 1)) % MOD;
		power = power * 31 % MOD;
		i++;
	}
	return (hash);
}

int str_cmp(const void *a, const void *b)
{
	return (strcmp(*(char **)b, *(char **)a));
}

int map_insert(t_map *map, char *key)
{
	t_node *curr;	
	long long hash;

	hash = get_hash(key);
	if (!map->map[hash])
	{
		map->map[hash] = create_elem(key);
		map->size++;
		return (1);
	}
	curr = map->map[hash];
	while (curr)
	{
		if (strcmp(key, curr->key) == 0)
			return (0);
		curr = curr->next;
	}
	curr = create_elem(key);
	map->size++;
	return (1);
}

int map_delete(t_map *map, char *key)
{
	t_node 	*curr;	
	t_node 	*prev;
	long long 	hash;

	hash = get_hash(key);
	curr = map->map[hash];
	prev = 0;
	while (curr)
	{
		if (strcmp(key, curr->key) == 0)
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
	free(curr);
	map->size--;
	return (1);
}

void	print_result(t_map *map)
{
	int i, j;
	char **result;	
	t_node	*curr;

	result = malloc(sizeof(char *) * map->size);
	for (i = 0; i < map->size; i++)
		result[i] = malloc(sizeof(char) * 6);
	j = 0;
	for (i = 0; i < MOD; i++)
	{
		if (map->map[i] != 0)
		{
			curr = map->map[i];
			while (curr)
			{
				result[j] = curr->key;
				j++;
				curr = curr->next;
			}
		}
	}
	qsort(result, map->size, sizeof(result[0]), str_cmp);
	for (i = 0; i < map->size; i++)
		printf("%s\n", result[i]);
}

int main(void)
{
	int 		N, i, j;
	char 		name[6], cases[6];
	t_map		 *map;

	scanf("%d", &N);
	map = map_init();
	while (N--)
	{
		scanf("%s %s", name, cases);
		if (strcmp(cases, "enter") == 0)
			map_insert(map, name);
		else if (strcmp(cases, "leave") == 0)
			map_delete(map, name);
	}	
	if (map->size <= 0)
		return (0);
	print_result(map);
	return (0);
}
