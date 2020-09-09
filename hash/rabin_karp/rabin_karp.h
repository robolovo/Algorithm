#ifndef RABIN_KARP_H
# define RABIN_KARP_H

#include <stdio.h>
#include <stdlib.h>

# define POWER 302
# define BIG_PRIME 1000000007

long long	get_hash_value(const char *str, unsigned int len);
char		*find_str(const char *haystack, const char *needle);

#endif
