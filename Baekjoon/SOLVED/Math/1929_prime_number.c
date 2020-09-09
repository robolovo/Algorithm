#include <stdio.h>
#include <stdbool.h>

#define MAX 1000000

int main(void)
{
	int N, M, res;
	bool prime[MAX + 1] = { false, };

	scanf("%d %d", &N, &M);

	prime[1] = true;
	for (int i = 2; i * i <= MAX; i++)
		if (!prime[i])
			for (int j = i * i; j <= MAX; j += i)
				prime[j] = true;

	for (int i = N; i <= M; i++)
		if (!prime[i])
			printf("%d\n", i);
	return (0);
}
