#include "map.h"

int	get_hash(const char *key)
{
	int hash;
	int i;

	hash = 0;
	i = 0;
	while (key[i])
	{
		hash = (hash * POWER + key[i]) % BIG_PRIME;
		i++;
	}
	return (hash);
}
