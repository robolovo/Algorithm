#include "set.h"

int	get_hash(void *data, int data_size)
{
	int hash;
	char *temp;
	int i;
	
	if (!data || data_size == 0)
		return (0);
	temp = (char *)data;
	hash = 0;
	i = 0;
	while (i < data_size)
	{
		hash = (hash * POWER + temp[i]) % BIG_PRIME;
		i++;
	}
	return (hash);
}
