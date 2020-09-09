#include "rabin_karp.h"

static unsigned int	get_length(const char *str)
{
	unsigned int len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*find_str(const char *haystack, const char *needle)
{
	int			needle_len;
	int			hay_len;
	long long	needle_value;
	long long 	value;
	int	i;

	needle_len = get_length(needle);
	hay_len = get_length(haystack);
	needle_value = get_hash_value(needle, needle_len);
	value = get_hash_value(haystack, needle_len);	
	i = 0;
	while (i < hay_len)
	{
		if (needle_value == value)
			break;
		else
		{
			haystack++;
			value = get_hash_value(haystack, needle_len);
		}
		i++;
	}
	return ((char *)haystack);
}
