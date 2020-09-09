#ifndef MAP_H
# define MAP_H

# define BIG_PRIME 1000003
# define POWER 109

# include <stdlib.h>

typedef unsigned int uint;

typedef struct		s_node
{
	const char		*key;
	void			*value;
	struct s_node	*next;
}					t_node;

typedef struct		s_hash_map
{
	unsigned int	size;
	t_node			**map;
}					t_hash_map;

t_hash_map			*map_init(void);
t_node				*create_elem(const char *key, void *value);
int					get_hash(const char *key);
int					ft_strcmp(const char *s1, const char *s2);
int					map_insert(t_hash_map *map, const char *key, void *value);
void				*map_get(t_hash_map *map, const char *key);
void				*map_delete(t_hash_map *map, const char *key);
void				free_map(t_hash_map *map, void (*free_data)(void *));

#endif
