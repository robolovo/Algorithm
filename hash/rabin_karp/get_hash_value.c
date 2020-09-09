#include "rabin_karp.h"

static unsigned int	get_strlen(const char *str)
{
	unsigned int len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

long long			get_hash_value(const char *str, unsigned int len)
{
	long long 		result;
	unsigned int	str_len;
	int				i;

	str_len = get_strlen(str);
	if (len > str_len)
		len = str_len;
	result = 0;
	i = 0;
	while (i < len)
	{
		result = (result * POWER + str[i]) % BIG_PRIME;
		i++;
	}
	return (result);
}
