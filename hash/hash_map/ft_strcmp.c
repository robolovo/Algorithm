#include "map.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	uint	i;

	if (!s1 && !s2)
		return (0);
	else if (!s2)
		return (s1[0]);
	else if (!s1)
		return (-s2[0]);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
