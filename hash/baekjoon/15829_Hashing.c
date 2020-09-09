#include <stdio.h>

# define POWER 31
# define MOD 1234567891

long long	get_hash(char *key, int	len)
{
	long long hash;
	int	i;
	long long power;

	power = 1;
	hash = 0;
	i = 0;
	while (i < len)
	{
		hash = (hash + power * (key[i] - 96)) % MOD;
		power = power * POWER % MOD;
		i++;
	}
	return (hash);
}

int main(void)
{
	int L;
	long long hash;
	char key[51];

	scanf("%d", &L);
	scanf("%s", key);

	hash = get_hash(key, L);

	printf("%lld\n", hash);
}
